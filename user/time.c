#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/param.h"
#include "kernel/pstat.h"

int
main(int argc, char *argv[])
{
    int time1 = uptime();
    printf("Time :%d ticks \n", time1);
    int rc = fork();
    if (rc < 0) {
        printf("fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        char *argv2[] = {argv[1],0};
        exec (argv2[0],argv2);
    } else {
        struct rusage r;
        wait2(0, &r);
        int time2 = uptime();    
        //int cpu  = r.cputime*100 ;
        //printf("elapsed time %d ticks, cpu time %d ticks, cpu% : %d%\n", time2-time1,cputime,cputime*100/time2);
     	printf("elapsed time %d ticks, cpu time %d ticks, cpu%% : %d%%\n", time2 - time1, r.cputime, r.cputime * 100 / time2);


    }
    exit(0);
}
