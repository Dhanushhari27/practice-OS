#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *runner1(void *param) {
    pthread_t td = pthread_self();

    printf("\n%lu\n", (unsigned long)td);

    pthread_exit(NULL);
}

int main(void) {
    pthread_t tid1, tid2, tid3;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&tid1, &attr, runner1, NULL);
    pthread_create(&tid2, &attr, runner1, NULL);

    printf("\n1:: %d\n", pthread_equal(tid1, tid2));

    tid3 = pthread_self();

    printf("\n2:: %d\n", pthread_equal(tid3, pthread_self()));

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_attr_destroy(&attr);

    printf("\nMain Thread Done, PID = %d\n", (int)getpid());

    return 0;
}