/*
* Recitation Section Number: 
* Breakout Number:
* Member Name
* Member Name
* Member Name
* Member Name
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#define BUFSIZE 20
#define PERM 0644
int main(int argc, char *argv[]) {
	int infile; char buffer[BUFSIZE];
	// create/open a file named write.txt
	infile = open("write.txt", O_CREAT | O_RDWR | O_TRUNC, PERM);
	// write hello world to write.txtS
	write(infile, "hello world\n", 12);
	// spawn a child process and use this child process to reroute stdout to write.txt
	pid_t pid = fork();
	if (!pid) {
		dup2(infile, 1);
	}
	// print pid
	printf("Process %d\n", pid);
	
	// use the child process spawned previously to read the contents from write.txt, restore output to stdout
	// and then prints the contents of write.txt to stdout.
	if (!pid) {
		read(infile, buffer, 20);
		int stdout = open("/dev/tty", O_WRONLY);
		dup2(1, stdout);
		printf("%s\n", buffer);
		return 0;
	}
	// print pid
	printf("%d\n", pid);
	// close the file write.txt
	close(infile);
	return 0;
}