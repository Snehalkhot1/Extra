#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // or <unistd.h> for Linux

int main() {
    int i, frame[30], timeout = 5, delay = 0;
    int n;
    time_t t;

    printf("Enter the number of frames: ");
    scanf("%d", &n);

    printf("\nEnter the data for frames:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &frame[i]);
    }

    srand((unsigned) time(&t));

    for(i = 0; i < n; i++) {
        resend:
        printf("\nFrame sent = %d\tData = %d", i + 1, frame[i]);
        delay = rand() % 10;
        printf("\nDelay = %d\n", delay);

        if(delay < timeout) {
            printf("\nAcknowledgement received = %d\n", i + 1);
        } else {
            while(delay != timeout) {
                printf("\nWaiting...\t");
                Sleep(2000); // or sleep(2);
                delay--;
            }
            printf("\nTimeout\n");
            printf("\nResending Frame = %d\tData = %d\n", i + 1, frame[i]);
            goto resend;
        }
    }

    printf("\n\nAll data frames sent\n");
    return 0;
}