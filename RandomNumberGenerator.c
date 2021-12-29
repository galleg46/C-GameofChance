#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>


int main(int args, char* argv[]){
    int i = 0;
    char strSize = *argv[2];
    int size = atoi(&strSize);
    int arr[size];
    char input[size * 3];
    strcpy(input, argv[1]);

    char* element;
    element = strtok(input, ",");

    while(element != NULL){
        arr[i] = atoi(element);
        ++i;
        element = strtok(NULL, ",");
    }

    printf("\nA random number is being generated!\n");
    srand(time(NULL));

    int randomNum = rand() % 256;
    printf("The random number is: %d\n", randomNum);

    int winner = 256;
    for (int j = 0; j < size; ++j) {
        if (arr[j] > randomNum){
            if ((arr[j] - randomNum) < winner - randomNum){
                winner = arr[j];
            }
        }
    }

    if(winner < 256){
        printf("\nThe winner is %d!\n", winner);
    }
    else{
        printf("\nThere are no winners, it is a Tie!\n");
    }

    return 0;
}