#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>



int main() {
    pid_t pid;
    int status;
    const int numberOfChildren = 10;

    //Array of commands
    char *commands[][10] = {
        {"ls", "-l", NULL}, //Command to the list directory contents
        {"echo", "Hello Hieu Luong", NULL}, //command
        {"date", NULL,NULL},//Command to the list directory contents
        {"pwd", NULL, NULL},//Command to print the current working directory
        {"whoami",NULL,NULL},//Command to print the current user
        {"uptime",NULL,NULL},//Command to check the work up to now
        {"dp","-h",NULL},//Command to check disk space usage
        {"echo","This is Lab2 from CS470", NULL},//Command
        {"ps","aux",NULL},//command to show process status
        {"echo","Thank you for watching", NULL},//Command
    };
    printf("Parent process PID: %d\n", getpid());




    //For the child process
    for(int i=0; i<numberOfChildren; i++) {
        pid = fork();
        if(pid <0) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }else if (pid ==0) {
            printf("Child process PID: %d -Executing command: %s\n", getpid(), commands[i][0]);
            execvp(commands[i][0], commands[i]);
            perror("Exec failed");
            exit(EXIT_FAILURE);
        }
    }

    //Parent
    printf("print out history: ---------\n");
    while((pid=wait(&status))>0) {
        //First of all check the child process when it is finished or not
        if (WIFEXITED(status)) {
            printf("Parent process: Child with PID %d finished with the exit status %d\n", pid, WEXITSTATUS(status));
        }else if (WIFSIGNALED(status)) {
            printf("Parent proccess: Child with PID %d was terminated by the signal %d\n",pid, WTERMSIG(status));
        }else {
            printf("Parent process: Child with PID %d finished in an unknown manner\n", pid);
        }
    }
    printf("Parent process: All child process have completed");
    return EXIT_SUCCESS;




}