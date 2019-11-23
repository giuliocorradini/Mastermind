#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum colors {EMPTY, RED, GREEN, YELLOW, BLUE, ORANGE, PURPLE};
char *color_strings[] = {"EMPTY", "RED", "GREEN", "YELLOW", "BLUE", "ORANGE", "PURPLE"};

char elementIsIn(char, char*);

int main() {
    char guess[9][4];
    char code[4];
    int i, j, k;

    int correct, wrong; //place

    char win = 0;

    srand(time(NULL));
    for(i=0; i<4; i++)
        code[i] = rand() % 6 + 1; // Colors go from 1 to 6

    // Populate guesses array with EMPTY color
    for(i=0; i<9; i++)
        for(j=0; j<4; j++)
            guess[i][j] = EMPTY;


    printf("COLOR TABLE:\n"
           "RED\t1\n"
           "GREEN\t2\n"
           "YELLOW\t3\n"
           "BLUE\t4\n"
           "ORANGE\t5\n"
           "PURPLE\t6\n\n");

    for(i=0; i<9 && !win; i++) {
        printf("Guess %d\n", i+1);
        for(j=0; j<4; j++) {
            printf("Enter color of pos%d: ", j);
            scanf("%d", &k);
            guess[i][j]=k;
        }

        // Check guess against the code
        correct = 0;
        wrong = 0;
        for(j=0; j<4; j++) {
            if(code[j] == guess[i][j]) {
                correct++;
            } else if (elementIsIn(guess[i][j], code)) {
                wrong++;
            }
        }

        if(correct == 4) {
            win = 1;
        } else {
            printf("%d correct position\n%d wrong position\n", correct, wrong);
        }
    }

    if(win) {
        printf("You guessed the code!\n");
    } else {
        printf("You didn't guess the code. It was ");
        for(i=0; i<4; i++)
            printf("%s", color_strings[code[i]]);
        printf("\n");
    }


    return 0;
}

char elementIsIn(char element, char* seq) {
    int i, found=0;
    for(i=0; i<4 && !found; i++) {
        if(element == seq[i])
            found=0;
    }
    return found;
}