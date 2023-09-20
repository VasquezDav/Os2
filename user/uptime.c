#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(){
	printf("up %d clock ticks\n",uptime());
	exit(0);
}
