static ssize_t proc_write(struct file *file, const char __user *usr_buf, size_t count, loff_t *pos) {
    char *k_mem;
    // allocate kernel memory
    k_mem = kmalloc(count, GFP_KERNEL);
    /* copies user space usr_buf to kernel buffer */
    if (raw_copy_from_user(k_mem, usr_buf, count)) {
        printk( KERN_INFO "Error copying from user\n");
        return -1;
    }
    k_mem[count] = '\0';   // make sure k_mem is null-terminated
    kstrtoint(k_mem, 10, &current_pid);
    printk(KERN_INFO "Set current PID to %d", current_pid);
    kfree(k_mem);
    return count;
}
