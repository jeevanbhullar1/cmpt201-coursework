/*Write a program that does the following:

It receives user input from the keyboard that is the full path of a program to run.
e.g., "/usr/bin/ls", "/usr/bin/nvim", or "/usr/bin/ip", etc.
You do not need to handle commandline arguments (such as /usr/bin/ls -l -a).
It executes the command the user typed in.
It repeats the above two steps forever.
Use fork(), exec(), and waitpid().


*/

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {

  while (1) {
    size_t len = 0;
    char *input = NULL;
    ssize_t getline(char **restrict lineptr, size_t *restrict n, FILE *restrict stream);

    printf("Enter programs to run: ");
    getline(&input, &len, stdin);
    input[strcspn(input, "\n")] = '\0';

    pid_t pid = fork();
    if (pid == 0) {
      // child process
      execl(input, input, NULL);
      perror("execl");
    } else if (pid > 0) {
      // parent process
      waitpid(pid, NULL, 0);
      perror("parent");
    } else {
      // fork failed
      perror("fork");
    }
  }
}
