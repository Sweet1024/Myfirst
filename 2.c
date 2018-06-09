#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void waiting(),stop();
int wait_mark;
main()
{
	int p1,p2;
	if(p1=fork())
	{
		if(p2=fork())
		{
			wait_mark=1;
			signal(SIGINT,stop);
			waiting();
			kill(p1,16);
			kill(p2,17);
			wait(0);
			wait(0);
			printf("parent process is killed!\n");
			exit(0);
		}
	else
	{
		wait_mark=1;
		signal(SIGINT,stop);
		waiting();
		lockf(1,0,0);
		printf("child process2 is killed by parent!\n");
		lockf(1,0,0);
		exit(0);
	}
    }
else
{
	wait_mark=1;
	signal(SIGINT,stop);
	waiting();
	lockf(1,0,0);
	printf("child process1 is killed by parent!\n");
	lockf(1,0,0);
	exit(0);
}
}
void waiting()
{
	while(wait_mark!=0);
}
void stop()
{
	wait_mark=0;
}