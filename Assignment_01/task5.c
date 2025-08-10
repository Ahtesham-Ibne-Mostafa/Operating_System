#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid == 0) {
        printf("2. Child process ID: %d\n", getpid());

        for (int i = 0; i < 3; i++) {
            pid_t grandchild_pid = fork();
            if (grandchild_pid == 0) {
                printf("3. Grand Child process ID: %d\n", getpid());
                _exit(0);
            }
        }
        for (int i = 0; i < 3; i++) {
            wait(NULL);
        }
        _exit(0);
    } else if (child_pid > 0) {
        printf("1. Parent process ID : 0\n");
        wait(NULL);
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}