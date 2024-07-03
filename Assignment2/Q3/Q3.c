#include<linux/sched/signal.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
MODULE_DESCRIPTION("OS ASSIGNMENT-2 KERNEL MODULE (Q3)");
MODULE_AUTHOR("Animesh Pareek and Viwaswaan Navani");
MODULE_LICENSE("GPL");
static int __init mysyscall_module(void){
	printk(KERN_INFO "Entering the custom module\n");
	struct task_struct *p=NULL;
	int n=0;
	for_each_process(p){
		n++;
	}
	printk(KERN_ALERT "No.of Processes -> %d\n",n);
	return 0;
}
static void __exit cleanup_fn(void){
	printk(KERN_INFO "Exitting from our custom module!!\n");
}
module_init(mysyscall_module);
module_exit(cleanup_fn);
