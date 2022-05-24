/*
* Recitation Section Number: 9
* Breakout Number: 6
* Audrey Hebert (heber169)
* Qiyu Tian (tian0068)
* Mouhari Mouhamed (mouha003)
* Matt Strapp (strap012)
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

// Remember the usage of sig_atomic_t in the recitation example
static volatile sig_atomic_t doneflag = 0;

static void setdoneflag(int signo) {
	doneflag = doneflag ^ 1;
}

void infinitePrint() {

	static int count = 0;
	printf("%ld: Count = %d\n", time(NULL), ++count);
	sleep(1);
}

int main() {

	// ------------------sol2.c-----------------
	// setup signal handler - sigaction struct, sigemptyset,
	struct sigaction act;
	sigset_t sigset;
	// specify action associated with SIGNT - sigaction()
	act.sa_handler = setdoneflag; /* set up signal handler */
	act.sa_flags = 0;
	if ((sigemptyset(&act.sa_mask) == -1) ||
		(sigaction(SIGINT, &act, NULL) == -1))
	{
		perror("Failed to set SIGINT handler");
		return 1;
	}
	// You are free to modify the while loop but not the infinitePrint()
	// -----------------------------------------

	/* Print infinitely. */
	while (1) {
		if (!doneflag)
		infinitePrint();
	}
}