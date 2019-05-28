#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Luigi Linhares");
MODULE_DESCRIPTION("A hello simple linux driver.");
MODULE_VERSION("0.1");

static char *name = "world";

module_param(name, charp, S_IRUGO);

static int __init hello_start(void){
    printk(KERN_INFO "Carregando o modulo ... \n");
    printk(KERN_INFO "Hello %s a partir do LKM \n", name);
    return 0;
}

static void __exit hello_end(void){
    printk(KERN_INFO "Tchauuuuu do LKM \n");
}

module_init(hello_start);
module_exit(hello_end);