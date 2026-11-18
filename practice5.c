
#include <stdio.h>
#include <unistd.h>

int main() {

    int x = 10;

    if (fork() != 0) {

        x = x + 10;

        printf("\nPARENT:: %d\n", x);

    } else {

        sleep(3);

        printf("\nChild:: %d\n", x);

    }

    return 0;
}
