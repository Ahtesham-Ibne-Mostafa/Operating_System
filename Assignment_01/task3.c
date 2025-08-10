#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

void log_process() {
    FILE *fp = fopen("process_count.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "1\n");
        fclose(fp);
    }
}

int main() {
    pid_t original_pid = getpid();

    pid_t a = fork();
    if (a == -1) exit(1);
    if (a == 0) log_process();

    pid_t b = fork();
    if (b == -1) exit(1);
    if (b == 0) log_process();

    pid_t c = fork();
    if (c == -1) exit(1);
    if (c == 0) log_process();

    if (a > 0 && (a % 2 == 1)) {
        pid_t extra_a = fork();
        if (extra_a == 0) log_process();
    }
    if (b > 0 && (b % 2 == 1)) {
        pid_t extra_b = fork();
        if (extra_b == 0) log_process();
    }
    if (c > 0 && (c % 2 == 1)) {
        pid_t extra_c = fork();
        if (extra_c == 0) log_process();
    }

    log_process();

    while (wait(NULL) > 0);

    if (getpid() == original_pid) {
        sleep(1);
        FILE *fp = fopen("process_count.txt", "r");
        if (fp != NULL) {
            int count = 0;
            char ch;
            while ((ch = fgetc(fp)) != EOF) {
                if (ch == '\n') count++;
            }
            fclose(fp);
            printf("Total number of processes created: %d\n", count);
            remove("process_count.txt");
        } else {
            printf("Could not open process count file.\n");
        }
    }

    return 0;
}
