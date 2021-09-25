#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/kdev_t.h>


#undef pr_fmt
#define pr_fmt(fmt) "%s:" fmt,__func__
// pseduo device's memor
#define DEV_MEM_SIZE 512
char device_buffer[DEV_MEM_SIZE];

dev_t device_number; // this holde the device nuber

/* creating cdev variable */
struct cdev pcd_cdev;

/* file operations of driver */

loff_t pcd_lseek(struct file *filp, loff_t off,int whence)
{
	pr_info("lseek is requested\n");
	return 0;
}

ssize_t pcd_read(struct file *filp,char __user *buff, size_t count, loff_t *f_pos)
{
	pr_info("read is requested and the count value is %zu bytes/n",count);
	return 0;
}

ssize_t pcd_write(struct file *filp, const char __user *buff,size_t count, loff_t *f_pos)
{
	pr_info("write requested for %zu bytes",count);
	return 0;
}

int pcd_open(struct inode *inode, struct file *filp)
{
	pr_info("open was successful \n"); 
	return 0;
}

int pcd_close(struct inode *inode, struct file *filp)
{
	pr_info("close was successful \n");
	return 0;
}

struct file_operations pcd_fops=
{
	.open = pcd_open,
	.write = pcd_write,
	.read = pcd_read,
	.llseek = pcd_lseek,
	.owner = THIS_MODULE
};



struct device *device_pcd;
struct class *class_pcd;
static int __init pcd_driver_init(void)
{
	// 1.  dynamically allocate a device number
	alloc_chrdev_region(&device_number,0,1,"pcd_devices");
	pr_info("device number major:minor = %d:%d \n",MAJOR(device_number),MINOR(device_number));
		
	/* 2. initialize the cdev with fops */
	cdev_init(&pcd_cdev,&pcd_fops);

       /* 3. Register cdev struct with VFS */
        pcd_cdev.owner = THIS_MODULE;
	cdev_add(&pcd_cdev,device_number,1);

	/* 4. cretae device class under sys/class/ */
	class_pcd = class_create(THIS_MODULE,"pcd_class");

	/* 5. device file creation or populate the sysfs with devie information */
	device_pcd = device_create(class_pcd,NULL,device_number,NULL,"pcd");

	pr_info("module init is succesfull\n");

        return 0;


}

static void __exit pcd_driver_cleanup(void)
{
	/* 1. device destroy */
	device_destroy(class_pcd,device_number);

	/* 2. class destroy */
	class_destroy(class_pcd);

	/* 3. cdev delete */
	cdev_del(&pcd_cdev);

	/* 4. unregister chardev region  */
	unregister_chrdev_region(device_number,1);
	pr_info("module unloaded successfuly PCD");


}
module_init(pcd_driver_init);
module_exit(pcd_driver_cleanup);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Himanshu");
MODULE_DESCRIPTION("A pseudo char driver");



