#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xa0c1c7e8, "module_layout" },
	{ 0x61b7b126, "simple_strtoull" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x5457a9aa, "kmem_cache_destroy" },
	{ 0x73aa49f, "fs_bio_set" },
	{ 0x3554d5f7, "iet_mem_size" },
	{ 0x9b944697, "kmalloc_caches" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0xc897c382, "sg_init_table" },
	{ 0x9b388444, "get_zeroed_page" },
	{ 0xbb86f05b, "bio_alloc_bioset" },
	{ 0x80380062, "kernel_sendmsg" },
	{ 0x9bb274b4, "mem_map" },
	{ 0x76ebea8, "pv_lock_ops" },
	{ 0xd0d8621b, "strlen" },
	{ 0xf17a530b, "page_address" },
	{ 0x6f874bbb, "filemap_write_and_wait_range" },
	{ 0xb57f9b40, "seq_open" },
	{ 0x3a013b7d, "remove_wait_queue" },
	{ 0xacf4d843, "match_strdup" },
	{ 0xc01cf848, "_raw_read_lock" },
	{ 0xe0895973, "__lock_page" },
	{ 0xa4eb4eff, "_raw_spin_lock_bh" },
	{ 0xe8b63ace, "radix_tree_range_tag_if_tagged" },
	{ 0xdd5c3f37, "sock_recvmsg" },
	{ 0x96c7e43b, "seq_printf" },
	{ 0xe120b394, "remove_proc_entry" },
	{ 0x6729d3df, "__get_user_4" },
	{ 0x44e9a829, "match_token" },
	{ 0xf5dd6389, "__register_chrdev" },
	{ 0x694d9d2, "filp_close" },
	{ 0x6acc2418, "iet_mem_virt" },
	{ 0x593a99b, "init_timer_key" },
	{ 0xe1819f15, "mutex_unlock" },
	{ 0x85df9b6c, "strsep" },
	{ 0xb0bd2fc6, "seq_read" },
	{ 0x30f362cf, "__alloc_pages_nodemask" },
	{ 0xc499ae1e, "kstrdup" },
	{ 0x1f00ebee, "kthread_create_on_node" },
	{ 0x7d11c268, "jiffies" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x8522d5f7, "end_page_writeback" },
	{ 0xec67185d, "fsync_bdev" },
	{ 0x9f9b6c64, "sock_no_sendpage" },
	{ 0x68dfc59f, "__init_waitqueue_head" },
	{ 0xffd5a395, "default_wake_function" },
	{ 0x3fa58ef8, "wait_for_completion" },
	{ 0xbce1715d, "vfs_read" },
	{ 0xd5f2172f, "del_timer_sync" },
	{ 0x2bc95bd4, "memset" },
	{ 0xa8bb409b, "proc_mkdir" },
	{ 0x11089ac7, "_ctype" },
	{ 0xb2d3cb20, "current_task" },
	{ 0xa61e5c61, "mutex_lock_interruptible" },
	{ 0x5e651052, "__mutex_init" },
	{ 0x50eedeb8, "printk" },
	{ 0xebf15e2e, "kthread_stop" },
	{ 0x8ad7bab7, "bio_add_page" },
	{ 0xb6b50c41, "netlink_kernel_release" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x2f287f0d, "copy_to_user" },
	{ 0xb6ed1e53, "strncpy" },
	{ 0xb4390f9a, "mcount" },
	{ 0xc8d2bad1, "blkdev_get_by_path" },
	{ 0xe8d8df47, "kmem_cache_free" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0x98bf94b0, "mutex_lock" },
	{ 0x7f658e80, "_raw_write_lock" },
	{ 0x8834396c, "mod_timer" },
	{ 0x6b1c0807, "netlink_unicast" },
	{ 0xdb266609, "wait_on_page_bit" },
	{ 0xcde172ac, "radix_tree_gang_lookup_tag_slot" },
	{ 0xa07217e7, "skb_pull" },
	{ 0x62f623a9, "unlock_page" },
	{ 0xc6042de6, "init_net" },
	{ 0x5215b1b6, "fput" },
	{ 0x5724261, "contig_page_data" },
	{ 0x5d5b5a16, "radix_tree_delete" },
	{ 0x70d627b8, "bio_put" },
	{ 0x7c6c2363, "put_io_context" },
	{ 0xa1751f89, "module_put" },
	{ 0xf925bc09, "submit_bio" },
	{ 0xdd1c65f6, "blk_finish_plug" },
	{ 0x4646dc37, "kmem_cache_alloc" },
	{ 0x8ff4079b, "pv_irq_ops" },
	{ 0xd53ffb53, "__free_pages" },
	{ 0xd1e94001, "blkdev_put" },
	{ 0x51d2c130, "__alloc_skb" },
	{ 0x47b3f862, "radix_tree_lookup_slot" },
	{ 0x8bf826c, "_raw_spin_unlock_bh" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x4292364c, "schedule" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0xf1faac3a, "_raw_spin_lock_irq" },
	{ 0x6b2dc060, "dump_stack" },
	{ 0x21929ec9, "get_task_io_context" },
	{ 0xb932b481, "crypto_destroy_tfm" },
	{ 0xa84a9c99, "create_proc_entry" },
	{ 0x4c6de143, "wake_up_process" },
	{ 0xd77a84f5, "netlink_ack" },
	{ 0x8f605f2f, "kmem_cache_alloc_trace" },
	{ 0x67f7403e, "_raw_spin_lock" },
	{ 0x73507dad, "vfs_writev" },
	{ 0x5642793a, "radix_tree_tag_clear" },
	{ 0x178fd99a, "kmem_cache_create" },
	{ 0x4302d0eb, "free_pages" },
	{ 0xe45f60d8, "__wake_up" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0xff1e9dd8, "seq_list_start" },
	{ 0x5c3edd59, "_raw_write_unlock_bh" },
	{ 0xcf6c558b, "__netlink_kernel_create" },
	{ 0xd7bd3af2, "add_wait_queue" },
	{ 0x9d9d7e7c, "seq_lseek" },
	{ 0x37a0cba, "kfree" },
	{ 0x2e60bace, "memcpy" },
	{ 0x9754ec10, "radix_tree_preload" },
	{ 0xe0c3fd11, "fget" },
	{ 0x32eeaded, "_raw_write_lock_bh" },
	{ 0x90a1004a, "crypto_has_alg" },
	{ 0x19a9e62b, "complete" },
	{ 0xb81960ca, "snprintf" },
	{ 0x562f24de, "seq_release" },
	{ 0xe7d4daac, "seq_list_next" },
	{ 0x395afe4, "crypto_alloc_base" },
	{ 0x362ef408, "_copy_from_user" },
	{ 0xf202c5cb, "radix_tree_insert" },
	{ 0xe5d95985, "param_ops_ulong" },
	{ 0x2c421365, "__nlmsg_put" },
	{ 0x43a0458b, "blk_start_plug" },
	{ 0xfdba3ae9, "try_module_get" },
	{ 0x760a0f4f, "yield" },
	{ 0x71c5d3ce, "vfs_write" },
	{ 0x88635c1d, "filp_open" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "60488393A6CB171AD6C23A1");
