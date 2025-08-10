#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sort_desc(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <num1> <num2> ...\n", argv[0]);
        return 1;
    }

    int n = argc - 1;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i+1]);
    }

    pid_t pid = fork();

    if (pid == 0) {
        sort_desc(arr, n);
        printf("Sorted array in descending order:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        exit(0);
    } else if (pid > 0) {
        wait(NULL);
        printf("Odd/Even status:\n");
        for (int i = 0; i < n; i++) {
            if (arr[i] % 2 == 0)
                printf("%d is even\n", arr[i]);
            else
                printf("%d is odd\n", arr[i]);
        }
    } else {
        perror("fork");
        return 1;
    }

    return 0;
}