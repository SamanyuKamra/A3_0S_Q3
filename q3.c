#include <linux/kernel.h>
#include <linux/unistd.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/syscalls.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Samanyu Kamra - 2021487");
MODULE_DESCRIPTION("Linux module for reading process as entries.");
MODULE_VERSION("0.01");

int pid = 0;
module_param(pid,int,0);

static int __init q3_init(void)
{
 struct task_struct *process;
 pid_t process_pid ;
 uid_t process_uid ;
 pid_t process_pgid;
 
 process = pid_task(find_vpid(pid), PIDTYPE_PID);
 process_pid = process->pid;
 process_uid = process->cred->uid.val;
 process_pgid = process->group_leader->pid;
 printk(KERN_INFO "comm: %s\n",process->comm);
 printk(KERN_INFO "pid: %d\n",process_pid);
 printk(KERN_INFO "uid: %d\n",process_uid);
 printk(KERN_INFO "pgid: %d\n",process_pgid);
 return 0;
}
static void __exit q3_exit(void) {
 printk(KERN_INFO "Module ended\n");
}
module_init(q3_init);
module_exit(q3_exit);
