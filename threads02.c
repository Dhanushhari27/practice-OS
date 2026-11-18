#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *runner1(void *param) {
    pthread_t td = pthread_self();

    printf("\n%lu\n", (unsigned long)td);

    pthread_exit(NULL);
}

int main(void) {
    pthread_t tid[20];
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    for (int i = 0; i < 20; i++) {
        pthread_create(&tid[i], &attr, runner1, NULL);
    }

    for (int i = 0; i < 20; i++) {
        pthread_join(tid[i], NULL);
    }

    pthread_attr_destroy(&attr);

    printf("\nMain Thread Done, PID = %d\n", (int)getpid());

    return 0;
}