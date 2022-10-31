#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc fs.h>
#include <asm/uaccess.h>

#define BUFFER SIZE 128
#define PROC NAME "YourProcNameHere"

ssize t proc read(struct file *file, char user *usr buf,
  size t count, loff t *pos);

static struct file operations proc ops = {
  .owner = THIS MODULE,
  .read = proc read,
};

/* This function is called when the module is loaded. */
int proc init(void)
{
  /* creates the /proc/YourProcNameHere entry */
  proc create(PROC NAME, 0666, NULL, &proc ops);
  return 0;
}

/* This function is called when the module is removed. */
void proc exit(void)
{
  /* removes the /proc/YourProcNameHere entry */
  remove proc entry(PROC NAME, NULL);
}
