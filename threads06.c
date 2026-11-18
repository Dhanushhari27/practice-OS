#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

unsigned long sum = 0;

void *runner1(void *param) {
    for (unsigned long i = 0; i < 1000000; i++) {
        sum += i;
    }

    pthread_exit(NULL);
}

int main(void) {
    pthread_t tid;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid, &attr, runner1, NULL);

    pthread_join(tid, NULL);

    pthread_attr_destroy(&attr);

    printf("\nsum = %lu\n", sum);

    printf("\nMain Thread Done, PID = %d\n", (int)getpid());

    return 0;
}