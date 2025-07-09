#include <stdio.h>
#include <stdlib.h>

int main() {

    int x[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Enter value for x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    //printf("Values in the array:%s\n",x);
int j= 0;
    while (j < 5) {
        if (x[j] < 0) {
            printf("Value at x[%d] is negative: %d\n", j, x[j]);
        } else if (x[j] == 0) {
            printf("Value at x[%d] is zero: %d\n", j, x[j]);
        } else if (x[j] > 10) {
            printf("Value at x[%d] is greater than 10: %d\n", j, x[j] + 10);
        } else {
            printf("Value at x[%d] is between 0 and 10: %d\n", j, x[j]);
        }
        j++;
    }


    return 0;
}