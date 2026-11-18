#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *runner1(void *param) {
    int *p = (int *)param;

    printf("\n%d\n", *p);

    pthread_exit(NULL);
}

int main(void) {
    pthread_t tid[20];
    int arr[20];

    for (int i = 0; i < 20; i++) {
        arr[i] = (i + 1) * 10;
    }

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    for (int i = 0; i < 20; i++) {
        if (i % 2 == 0) {
            pthread_create(&tid[i], &attr, runner1, &arr[i]);
        } else {
            arr[i] = arr[i] - 1000;
            pthread_create(&tid[i], &attr, runner1, &arr[i]);
        }
    }

    for (int i = 0; i < 20; i++) {
        pthread_join(tid[i], NULL);
    }

    pthread_attr_destroy(&attr);

    printf("\nMain Thread Done, PID = %d\n", (int)getpid());

    return 0;
}