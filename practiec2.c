
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {

    if (fork() != 0) {

        execlp("/bin/rm", "rm", "abc.txt", (char *)NULL);

        printf("\nAFTER EXEC\n");

    } else {

        sleep(3);

        printf("\nBYE\n");

    }

    printf("\nTHE END\n");

    return 0;
}
