#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
   // printf("Time :%d ticksss \n", uptime());
    
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        printf("fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        char *argv2[] = {argv[1],0};
        exec(argv2[0],argv2);
        printf("exec did not work \n");
    } else {
        wait(0); 
        printf("elapsed time: %d ticks\n",uptime());
    }
    exit(0);
}
