#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function

int mutex = 1;   // Mutex to control access
int full = 0;    // Number of full slots
int empty = 5;   // Number of empty slots
int x = 0;       // Item count

void producer() {
    // Produce an item
    --mutex;         // Lock the critical section
    ++full;          // Increase the count of full slots
    --empty;         // Decrease the count of empty slots
    x++;             // Increment item count
    printf("\nProducer produced item %d", x);
    ++mutex;         // Unlock the critical section
}

void consumer() {
    // Consume an item
    --mutex;         // Lock the critical section
    --full;          // Decrease the count of full slots
    ++empty;         // Increase the count of empty slots
    printf("\nConsumer consumed item %d", x);
    x--;             // Decrement item count
    ++mutex;         // Unlock the critical section
}

int main() {
    int n;

    printf("\n1. Press 1 for producer"
           "\n2. Press 2 for consumer"
           "\n3. Press 3 for exit");

    while (1) {
        printf("\nEnter Your Choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                if (mutex == 1 && empty > 0) {
                    producer();
                } else {
                    printf("Buffer is full! Cannot produce.");
                }
                break;

            case 2:
                if (mutex == 1 && full > 0) {
                    consumer();
                } else {
                    printf("Buffer is empty! Cannot consume.");
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice! Please enter 1, 2, or 3.");
        }
        // Optional sleep to simulate time taken for production/consumption
        sleep(1);
    }

    return 0;
