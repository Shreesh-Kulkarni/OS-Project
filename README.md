### OS-Project
Project/assignment for the CS252 Operating System course(Minors)
##Linux Kernel Module for Task Information
Linux Kernel Module for Task Information. (Operating System Concepts, 10th Edition, Chapter 3, Project 2)

#Description
This is a Linux kernel module that uses the `/proc` file system for diplaying a task's information based on it's process identifier value `pid`.

The whole project can be broken down into 3 steps:

1. Writing a process identifier to the file `/proc/pid`(Module Instantiation)
2. Writing to the `/proc` file system
3. Reading from the `/proc` file system

Once a `pid` has been written to the `/proc/pid` file, subsequent reads from `/proc/pid` will report

1. the command the task is running
2. the value of the task’s `pid` 
3. the current state of the task.
