/*
CSci 4061 - Recitation 2 - 21st Sept 2020
Breakout 1
An iditoic loner's lone attempt
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char **argv) {
	// take 'n' from the input and convert to integer
	// hint: see cmd slide
	if (argc < 2) {
		printf("USAGE: ./main int\n");
		return -1;
	}
	int n = strtol(argv[1], NULL, 10);
	// for i in n
	//		create child process
	//			print pid //hint: check week 2 slides
	//			call execl to print 'hello there' using 'echo' //hint: check recitation slide
	pid_t pid;
	for (int i=0; i<n; i++) {
		pid = fork();
		if (pid == 0) {
			
		} else {
printf("%d\n", getpid());
			execl("/bin/echo", "/bin/echo", "hello", "there", NULL);
		}
	}
	// parent waits for all child processes to terminate
	for (int i=0; i<n; i++) {
		wait(NULL);
	}
	// parent create child process
	//		call execv on 'ptime' executable // hint: similar to 'echo' usage in slide
	pid = fork();
	if (pid != 0) {
		char *args[] = {"./ptime", NULL};
		execv(*args, args);
	}
	// parent waits for child to complete
	waitpid(pid, NULL, 0);
	return 0;
}