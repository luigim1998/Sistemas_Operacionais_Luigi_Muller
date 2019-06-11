#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/list.h>
#include<linux/slab.h>
#include<linux/string.h>

#include <linux/init.h>           // Macros used to mark up functions e.g. __init __exit
#include <linux/device.h>         // Header to support the kernel Driver Model
#include <linux/fs.h>             // Header for the Linux file system support
#include <linux/uaccess.h>        // Required for the copy to user function

struct k_list {
	struct list_head test_list;
	char temp[256];
};

struct list_head test_head;

static int __init list_init(void) {

	struct k_list *one,*two,*three,*four,*five,*entry;
	struct list_head *ptr;

	one=kmalloc(sizeof(struct k_list *),GFP_KERNEL);
	two=kmalloc(sizeof(struct k_list *),GFP_KERNEL);
	three=kmalloc(sizeof(struct k_list *),GFP_KERNEL);
	four=kmalloc(sizeof(struct k_list *),GFP_KERNEL);
	five=kmalloc(sizeof(struct k_list *),GFP_KERNEL);

	strcpy(one->temp,   "Abrir porta");
	strcpy(two->temp,   "Beber chá");
	strcpy(three->temp, "Cozinhar miojo");
	strcpy(four->temp,  "Deitar");
	strcpy(five->temp,  "E rolar");

	INIT_LIST_HEAD(&test_head);

	list_add(&one->test_list,&test_head);
	list_add(&two->test_list,&test_head);
	list_add(&three->test_list,&test_head);
	list_add(&four->test_list,&test_head);
	list_add(&five->test_list,&test_head);

	list_for_each(ptr,&test_head){
		entry=list_entry(ptr,struct k_list,test_list);

		printk(KERN_INFO "Tarefa: %s\n", entry->temp);

	}
	return 0;

}

static void __exit list_exit(void) {
	printk(KERN_INFO "Saindo do bagulho\n");
}

module_init(list_init);
module_exit(list_exit);