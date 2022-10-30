/* This function is called each time /proc/YourProcNameHere is read */
ssize t proc read(struct file *file, char user *usr buf,
size t count, loff t *pos)
{
int rv = 0;
char buffer[BUFFER SIZE];
static int completed = 0;
if (completed) {
completed = 0;
return 0;
}
completed = 1;
rv = sprintf(buffer, "This is the proc read function");
/* copies kernel space buffer to user space usr buf */
copy to user(usr buf, buffer, rv);
return rv;
}
module init(proc init);
module exit(proc exit);
MODULE LICENSE("GPL");
MODULE DESCRIPTION("PROC MOD");
MODULE AUTHOR("SGG");
