#include "cache_conn.h"

static int cio_add_pages(struct cio *cio, int count)
{
	int i;
	struct page *page;

	cio->pg_cnt = count;

	count *= sizeof(struct page *);

	do {
		cio->pvec = kzalloc(count, GFP_KERNEL);
		if (!cio->pvec)
			yield();
	} while (!cio->pvec);

	for (i = 0; i < cio->pg_cnt; i++) {
		do {
			if (!(page = alloc_page(GFP_KERNEL)))
				yield();
		} while (!page);
		cio->pvec[i] = page;
	}
	return 0;
}

static struct kmem_cache *cio_cache;

struct cio *cio_alloc(int count)
{
	struct cio *cio;

	cio = kmem_cache_alloc(cio_cache, GFP_KERNEL | __GFP_NOFAIL);

	cio->pg_cnt = 0;
	cio->offset = 0;
	cio->size = 0;
	cio->pvec = NULL;

	atomic_set(&cio->count, 1);

	if (count)
		cio_add_pages(cio, count);

	return cio;
}

struct cio_iterator {
	struct cio *cio;
	u32 size;
	u32 pg_idx;
	u32 pg_off;
};

void
cio_init_iterator(struct cio *cio,
		  struct cio_iterator *iter)
{
	iter->cio = cio;
	iter->size = 0;
	iter->pg_idx = 0;
	iter->pg_off = 0;
}

size_t
cio_add_data(struct cio_iterator *iter,
	     const u8 *data,
	     size_t len)
{
	struct cio *cio = iter->cio;
	const size_t to_copy = min(cio->pg_cnt * PAGE_SIZE - iter->size, len);
	size_t residual = to_copy;

	BUG_ON(cio->size < iter->size);

	do {
		u8 *ptr = page_address(iter->cio->pvec[iter->pg_idx]) + iter->pg_off;
		size_t chunk = min(PAGE_SIZE - iter->pg_off, residual);
		memcpy(ptr, data, chunk);
		residual -= chunk;
		if (residual ||
		    iter->pg_off + chunk == PAGE_SIZE) {
			++iter->pg_idx;
			iter->pg_off = 0;
		} else
			iter->pg_off += chunk;
	} while (residual);

	return to_copy;
}

static void cio_free(struct cio *cio)
{
	int i;
	for (i = 0; i < cio->pg_cnt; i++) {
		BUG_ON(!cio->pvec[i]);
		__free_page(cio->pvec[i]);
	}
	kfree(cio->pvec);
	kmem_cache_free(cio_cache, cio);
}

void cio_put(struct cio *cio)
{
	BUG_ON(!atomic_read(&cio->count));
	if (atomic_dec_and_test(&cio->count))
		cio_free(cio);
}

void cio_get(struct cio *cio)
{
	atomic_inc(&cio->count);
}

void cio_set(struct cio *cio, u32 size, loff_t offset)
{
	cio->offset = offset;
	cio->size = size;
}

int cio_init(void)
{
	cio_cache = KMEM_CACHE(cio, 0);
	return  cio_cache ? 0 : -ENOMEM;
}

void cio_exit(void)
{
	if (cio_cache)
		kmem_cache_destroy(cio_cache);
}

