//Function to read the pid value and print it

static ssize_t proc_read(struct file *file, char __user *usr_buf, size_t count, loff_t *pos) {
	// ...
    struct task_struct *tsk = NULL;
    tsk = pid_task(find_vpid(current_pid), PIDTYPE_PID);
    if(tsk) {
        rv = snprintf(buffer, BUFFER_SIZE,
                      "command = [%s], pid = [%d], state = [%ld]\n",
                      tsk->comm, current_pid, tsk->state);
    } else {
        printk(KERN_INFO "Invalid PID %d!", current_pid);
        return 0;
    }
	// ...
}
