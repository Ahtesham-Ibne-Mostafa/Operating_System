#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "a");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char input[MAX_INPUT_SIZE];

    printf("Enter strings to write to the file (enter \"-1\" to stop):\n");

    while (1) {
        printf("Input: ");
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            fprintf(stderr, "Error reading input.\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "-1") == 0) {
            break;
        }

        fprintf(file, "%s\n", input);
    }

    fclose(file);
    printf("Data written to file '%s'.\n", argv[1]);

    return 0;
}
