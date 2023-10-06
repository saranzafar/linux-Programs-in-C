#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_BUFFER_SIZE 10

int buffer[MAX_BUFFER_SIZE];
int in = 0;
int out = 0;
int bufsize = MAX_BUFFER_SIZE;

sem_t mutex, full, empty;

void *producer(void *arg)
{
    int produce;
    for (int i = 0; i < bufsize; i++)
    {
        produce = i; // You can change how items are produced here
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = produce;
        printf("Produced: %d\n", produce);
        in = (in + 1) % bufsize;
        sem_post(&mutex);
        sem_post(&full);
    }
    return NULL;
}

void *consumer(void *arg)
{
    int consume;
    for (int i = 0; i < bufsize; i++)
    {
        sem_wait(&full);
        sem_wait(&mutex);
        consume = buffer[out];
        printf("Consumed: %d\n", consume);
        out = (out + 1) % bufsize;
        sem_post(&mutex);
        sem_post(&empty);
    }
    return NULL;
}

int main()
{
    pthread_t produce_tid, consume_tid;
    int choice;

    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, bufsize);

    printf("1. Produce\t2. Consume\t3. Exit\n");

    pthread_create(&produce_tid, NULL, producer, NULL);
    pthread_create(&consume_tid, NULL, consumer, NULL);

    pthread_join(produce_tid, NULL);
    pthread_join(consume_tid, NULL);

    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}
