#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 1 // Size of the buffer (1 for this example)

int buffer[BUFFER_SIZE]; // Shared buffer
int in = 0; // Index for the next produced item
int out = 0; // Index for the next consumed item

sem_t empty; // Semaphore to count empty slots in the buffer
sem_t full;  // Semaphore to count full slots in the buffer
pthread_mutex_t mutex; // Mutex for critical section

void* producer(void* param) {
    for (int i = 1; i <= 20; i += 2) { // Produce odd numbers (1, 3, ..., 19)
        sem_wait(&empty); // Decrement empty count
        pthread_mutex_lock(&mutex); // Enter critical section

        // Produce an odd number
        buffer[in] = i;
        printf("Producer produced: %d\n", buffer[in]);
        in = (in + 1) % BUFFER_SIZE; // Circular increment

        pthread_mutex_unlock(&mutex); // Exit critical section
        sem_post(&full); // Increment full count

        sleep(1); // Simulate time taken to produce
    }
    return NULL;
}

void* consumer(void* param) {
    for (int i = 0; i < 10; i++) { // Consume 10 items
        sem_wait(&full); // Decrement full count
        pthread_mutex_lock(&mutex); // Enter critical section

        // Consume an odd number and produce the next even number
        int odd_number = buffer[out];
        int even_number = odd_number + 1; // Process to produce an even number
        printf("Consumer consumed: %d (produced even: %d)\n", odd_number, even_number);
        out = (out + 1) % BUFFER_SIZE; // Circular increment

        pthread_mutex_unlock(&mutex); // Exit critical section
        sem_post(&empty); // Increment empty count

        sleep(1); // Simulate time taken to consume
    }
    return NULL;
}
