/**
    This program implements the game Rock Paper Scissors.
**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cs50.h"







// this function is used to determine if gesture 2 wins or loses
//  returns 1 for win, 0 for tie, -1 for loss





// this is the function that gets executed when the program starts
int main() {
    int computer;
    int human;
    int winner;



    // randomly pick computer gesture
    srand(time(NULL));
    computer = (rand() / ((double) RAND_MAX + 1)) * 3;

    // ask human for their gesture

    printf("Please enter your gesture\n");
    human = get_int("Enter 0 for rock, 1 for paper, 2 for scissors: \n");
    // Validate human input
while (human < 0 || human > 2) {
    printf("Invalid input! Please enter 0, 1, or 2.\n");
    human = get_int("Enter 0 for rock, 1 for paper, 2 for scissors: \n");
}

    if (human == 1)
        printf("You chose paper\n");
    else if (human == 2)
        printf("You chose scissors\n");
    if (human == 0)
        printf("You chose rock\n");
    else if (human>2)
    printf("Invalid!\n");
    human = get_int("Enter 0 for rock, 1 for paper, 2 for scissors: \n");




    // determine winner (calls determine_winner function described above)
    winner = determine_winner(computer,human);

    // show outcome of game
    printf("The computer chose %d and you chose %d.\n",computer,human);
    if (winner == 1)
        printf("You win!\n");
    else if (winner == 0)
        printf("The game is a tie.\n");
    else if (winner == -1)
        printf("Computer wins!\n");




    char replay = get_char("Would you like to play again? y/n\n");

    if (replay == 'y')
        main();
    else if (replay == 'n')
        printf("Thanks for playing!!");


    return 0;
}

