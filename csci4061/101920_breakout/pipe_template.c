// -----------------------------------------------------------------------------
// Pipes
//
// Write a program that creates a child process and pipes the string
// "hello child" to the child to be printed. The parent should wait for the
// child to terminate
//
// Template: Implement the TODOs
//
// Expected output:
// Parent Sending: hello child
// Child Received: hello child
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  // Open pipe
  // TODO
  int ends[2];
  pipe(ends);

  char string_to_send[] = "hello child";
  int bytes_to_send_recv = strlen(string_to_send) + 1;

  // Create child process
  pid_t pid = fork();
  if (pid < 0) {
    // Error
    fprintf(stderr, "ERROR: Failed to fork\n");
  }
  else if (pid > 0) {
    // Parent
    printf("Parent Sending: %s\n", string_to_send);

    // Parent doesn't need read file descriptor
    // TODO
    close(ends[0]);
    // Write the string to the pipe
    // TODO
    write(ends[1], string_to_send, bytes_to_send_recv);
    // Done writing
    // TODO
    close(ends[1]);
    // Wait for child to terminate
    wait(NULL);
  }
  else {
    // Child

    char *recv_buffer = malloc(bytes_to_send_recv);

    // Child doesn't need write file descriptor
    // TODO
    close(ends[1]);
    // Read the string from the pipe
    // TODO
    read(ends[0], recv_buffer, bytes_to_send_recv);
    // Done reading
    // TODO
    close(ends[0]);
    // Print result
    printf("Child Received: %s\n", recv_buffer);
    free(recv_buffer);
  }

  return 0;
}
