
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    if (fork() != 0) {

        printf("\nPARENT:: %d\n", wait(NULL));

    } else {

        printf("\nCHILD PID:: %d\n", getpid());

        sleep(3);

        printf("\nChild:: %d\n", wait(NULL));

    }

    return 0;
}
