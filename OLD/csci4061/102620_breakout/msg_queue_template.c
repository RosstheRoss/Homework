/*
* Recitation Section Number: 02
* Breakout Number: 05
* Graden Hill (hill1582)
* Gustav Baumgart (baumg260)
* Matt Strapp (strap012)
* Skylan Recnana (recan001)
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <zconf.h>
#include <string.h>
#include <stdlib.h>

#define PERM 0666
#define MSGSIZE 100
#define NCHILD 3

// structure for message queue
typedef struct msg_buffer {
    long mtype;
    char mtext[MSGSIZE];
} message;

int main(void) {
    key_t key;
    int msgid;
    pid_t pid1, pid2;
    message msg;

    // generate unique key
    key = ftok("recitation", 4061);

    // creates a message queue
    msgid = msgget(key, PERM | IPC_CREAT);


    // sender child process
    pid1 = fork();
    if (pid1 == 0) {
        for (int i = 0; i < NCHILD; i++) {
            msg.mtype = 111;
            memset(msg.mtext, '\0', MSGSIZE);
            sprintf(msg.mtext, "Hello child %d", i);
            // send message to other child processes
            msgsnd(msgid, &msg, MSGSIZE, 0);


            // display the message
            printf("[%d] Data sent is : %s \n", i, msg.mtext);
        }

        for (int i = 0; i < NCHILD; i++) {
            msg.mtype = 222;
            memset(msg.mtext, '\0', MSGSIZE);
            sprintf(msg.mtext, "Message %d", i);
            // send message to other child processes
            msgsnd(msgid, &msg, MSGSIZE, 0);

            // display the message
            printf("[%d] Data sent is : %s \n", i, msg.mtext);
        }

        for (int i = 0; i < NCHILD; i++) {
            msg.mtype = 333;
            memset(msg.mtext, '\0', MSGSIZE);
            sprintf(msg.mtext, "Bye %d", i);
            // send message to other child processes
            msgsnd(msgid, &msg, MSGSIZE, 0);

                // display the message
                printf("[%d] Data sent is : %s \n", i, msg.mtext);
        }

        exit(0);
    } else if (pid1 < 0) {
        printf("fork1 error\n");
        return -1;
    }

    // receiver child processes
    for (int j = 0; j < NCHILD; j++) {
        if ((pid2 = fork()) == 0) {
            // receive message
            msgrcv(msgid, &msg, MSGSIZE, 222, 0);


            // display the message
            printf("[%d] Data received is : %s \n", j, msg.mtext);

            exit(0);
        } else if (pid2 < 0) {
            printf("fork2 error\n");
            return -1;
        }
    }

    while (wait(NULL) > 0);

    // to destroy the message queue
    msgctl(msgid, IPC_RMID, NULL);


    return 0;
}