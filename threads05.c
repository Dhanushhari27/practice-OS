#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

unsigned long s = 0;
unsigned long m = 1;

void *runner1(void *param) {
    unsigned long p = strtoul((char *)param, NULL, 10);

    for (unsigned long i = 1; i <= p; i++) {
        s += i;
    }

    pthread_exit(NULL);
}

void *runner2(void *param) {
    unsigned long x = strtoul((char *)param, NULL, 10);

    for (unsigned long i = 1; i <= x; i++) {
        m *= i;
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t tid1, tid2;
    pthread_attr_t attr;

    if (argc < 3) {
        printf("Usage: %s number1 number2\n", argv[0]);
        return 1;
    }

    pthread_attr_init(&attr);

    pthread_create(&tid1, &attr, runner1, argv[1]);
    pthread_create(&tid2, &attr, runner2, argv[2]);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_attr_destroy(&attr);

    printf("\n sum = %lu\n", s);
    printf("\n product = %lu\n", m);

    printf("\nMain Thread Done, PID = %d\n", (int)getpid());

    return 0;
}