#include <stdio.h>
#include <stdlib.h>

int main(){

    int x[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("Enter value of temperature in celcious [%d]: ", i);
        scanf("%d", &x[i]);
        if (x[i] < -10 || x[i] > 50) {
            printf("Sensor Error-Invalid Reading and stop\n");
            break; // Stop the loop on invalid input
        }
        else {
            printf("ok\n");
        }
    }

    return 0;
}
// This program reads temperature values in Celsius from the user, checks if they are within a valid