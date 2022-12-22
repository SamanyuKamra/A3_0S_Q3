#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/unistd.h>
#include <linux/syscalls.h>
#include <linux/sched.h>

int pid = 0;
module_param(pid, int, 0);

static int __init init(void)
{
    struct task_struct *t;
    t = pid_task(find_vpid(pid), PIDTYPE_PID);
    if (!t)
    {
        return -ESRCH;
    }
    printk(KERN_INFO "Pid: %d\n", t1->pid);
    printk(KERN_INFO "Uid: %d\n", t1->cred->uid.val);
    printk(KERN_INFO "Pgid: %d\n", t1->group_leader->pid);
    printk(KERN_INFO "Comm: %s\n", t1->comm);
    return 0;
}
module_init(init);
