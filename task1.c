#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

void toProperCase(char *str) 
{
    str[0] = toupper(str[0]);
    for (int i = 1; str[i]; i++) 
    {
        str[i] = tolower(str[i]);
    }
}

int main() 
{
    srand(time(0));
    char *choices[] = {"Rock", "Paper", "Scissors"};
    char userChoice[10];
    char playAgain;

    do {
        printf("Enter Rock, Paper, or Scissors: ");
        scanf("%s", userChoice);
        
        toProperCase(userChoice);
        
        if (strcmp(userChoice, "Rock") != 0 && strcmp(userChoice, "Paper") != 0 && strcmp(userChoice, "Scissors") != 0) {
            printf("Invalid choice! Please enter Rock, Paper, or Scissors.\n");
            continue;
        }
        int compIndex = rand() % 3;
        char *compChoice = choices[compIndex];
        printf("Computer chose: %s\n", compChoice);

        if (strcmp(userChoice, compChoice) == 0) 
        {
            printf("It's a Tie!\n");
        } 
        else if ((strcmp(userChoice, "Rock") == 0 && strcmp(compChoice, "Scissors") == 0) ||
                   (strcmp(userChoice, "Scissors") == 0 && strcmp(compChoice, "Paper") == 0) ||
                   (strcmp(userChoice, "Paper") == 0 && strcmp(compChoice, "Rock") == 0)) {
            printf("You Win!\n");
        }
        else 
        {
            printf("Computer Wins!\n");
        }

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
    } 
    while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
