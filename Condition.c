#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    printf("Value of X: ");
    scanf("%d", &x);

    if (x < 0) {
        printf("value is negative\n");
    }
    else if (x == 0) {
        printf("value of x is : %d\n", x);
    }
    else if (x > 10) {
        printf("value of x  is : %d\n", x+10);
    }

    return 0;
}