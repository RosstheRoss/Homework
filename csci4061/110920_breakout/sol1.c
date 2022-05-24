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

void infinitePrint() {

	static int count = 0;
	printf("%ld: Count = %d\n", time(NULL), ++count);
	sleep(1);
}

int main() {

	// ------------------sol1.c-----------------
	// initialize new sigset - sigset_t, sigemptyset
	sigset_t sigset;
	sigemptyset(&sigset);
	// add SIGINT to sigset - sigaddset
	sigaddset(&sigset, SIGINT);
	// block SIGINT - sigprocmask
	sigprocmask(SIG_BLOCK, &sigset, NULL);
	// Do not modify the while loop and infinitePrint()
	// -----------------------------------------

	/* Print infinitely. */
	while (1) infinitePrint();
}