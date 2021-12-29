#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int args, char* argv[]) {
    printf("Lets play a game of chance! Enter the number of integers "
           "you would like to input: ");

    int size;
    int i = 0;
    int winner;

    scanf("%d", &size);
    char input[(size * 3)];
    printf("Enter %d integers between 0 and 255, seperated by commas no spaces: \n", size);
    scanf("%s", input);

    pid_t pid;
    pid = fork();

    char str_Size[5];
    sprintf(str_Size, "%d", size);

    char *nums[] = {"NumberGenerator", input, str_Size, NULL};

    if (pid < 0){
        fprintf(stderr, "The fork() failed");
        return 1;
    }
    else if (pid == 0){
        execv("NumberGenerator", nums);
        return 1;
    }
    else{
        wait(NULL);
        printf("\nComplete\n");
    }

    return 0;
}
