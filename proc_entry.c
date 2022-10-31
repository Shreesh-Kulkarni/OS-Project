#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc fs.h>
#include <asm/uaccess.h>

#define BUFFER_SIZE 128
#define PROC_NAME "YourProcNameHere"

ssize_t proc_read(struct file *file, char __user *usr_buf,
  size_t count, loff_t *pos);

static struct file_operations proc_ops = {
  .owner = THIS_MODULE,
  .read = proc_read,
  .write = proc_write,
};

/* This function is called when the module is loaded. */
int proc_init(void)
{
  /* creates the /proc/YourProcNameHere entry */
  proc_create(PROC_NAME, 0666, NULL, &proc_ops);
  return 0;
}

/* This function is called when the module is removed. */
void proc_exit(void)
{
  /* removes the /proc/YourProcNameHere entry */
  remove_proc_entry(PROC_NAME, NULL);
}
