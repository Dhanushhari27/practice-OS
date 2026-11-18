
#include <stdio.h>
#include <unistd.h>

int main() {

    if (fork() == 0) {
        printf("\nBAD\n");
    }

    printf("\nHELLO\n");

    return 0;
}
