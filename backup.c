
/*
FAILED/LOST (1 round) BOLD RED
WON/PASSED BOLD GREEN (1 round)
REVERSE RED/GREEN FOR LOSS/WIN BEST OF 3
no coloured gestures cos up to 11 variants and no colours
p1 = blue
p2 = yellow
computer 1 yellow
comp 2 cyan


****RULES OF PROJECT

*The winner of the game is to be determined by the best
of three rounds

*if 2 players have same gesture and is tie, replay the round


*If one player wins the first two rounds, the winner is
already clear and the game should end and declare the winner.

Your program must do the following for each round of the game:

** Prompt player to enter number:

Rock = 0, Paper = 1, Scissors = 2, Spock = 3, and Lizard = 4.

** DISPLAY GESTURE chosen by the COMPUTER.

The display should have the following format:
The computer chose: X (Yyy), where X is the number and Yy is the gesture. Note that the first
letter of the gesture name should be capitalised.

For example, if the computer chose Rock,
then the output should say: The computer chose: 0 (Rock).


** Display the winner as follows.

o If the human player won, display: You win!
o If the computer won, display: Computer wins!
o If it is a tie, display: It’s a tie!


EXTENSION
Extend your program so that it is able to play variants of the game with 7, 9, or 11 gestures
(you must implement all variants)

If we want to keep increasing the number of hand gestures, using a set of statements to determine
the winner becomes cumbersome. Derive a new algorithm for determining the winner. (Hint: It can
be done mathematically).
*/
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define LIZARD 3
#define SPOCK 4

#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to determine if gesture 2 wins or loses
// Returns 1 for win, 0 for tie, -1 for loss
int determine_winner(int player, int comp) {
    if (player == comp) // condition for tie
        return 0; // Tie
    else if ((player == ROCK && (comp == SCISSORS || comp == LIZARD)) || // conditions for human winning, otherwise computer wins
             (player == PAPER && (comp == ROCK || comp == SPOCK)) ||
             (player == SCISSORS && (comp == PAPER || comp == LIZARD)) ||
             (player == LIZARD && (comp == SPOCK || comp == PAPER)) ||
             (player == SPOCK && (comp == 0 || comp == SCISSORS)))
        return 1; // Human wins
    else
        return -1; // Computer wins
}

// Function to show who wins
void show_winner(int winner) {
    if (winner == 1)
        printf("You win!\n");
    else if (winner == 0)
        printf("The game is a tie.\n");
    else if (winner == -1)
        printf("Computer wins!\n");
}

// Function to check whether a gesture is valid
int check_gesture(int g) {
    // Validate human input
    if (g == 0 || g == 1 || g == 2 || g == 3 || g == 4) {
        return 0; // Valid gesture
    } else {
        return 1; // Invalid gesture
    }
}

// Function to prompt for a gesture
int get_gesture() {
    printf("Please enter your gesture\n");
    int x = get_int("Enter 0 for rock, 1 for paper, 2 for scissors, 3 for lizard, 4 for spock: ");
    return check_gesture(x) ? get_gesture() : x;
}

// Function to randomly generate a gesture
int get_random_gesture() {
    int MYMAX = 2;
    return (rand() / (double)RAND_MAX) * (MYMAX + 1);
}

// Function to test determine_winner function
void test_determine_winner(int gesture2) {
    printf("***Testing when gesture 2 is rock\n");
    printf("Tie Test: ");
    if (determine_winner(gesture2, gesture2) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");

    printf("Lose Test: ");
    if (determine_winner(1, gesture2) == -1)
        printf("Passed\n");
    else
        printf("Failed\n");

    printf("Win Test: ");
    if (determine_winner(2, gesture2) == 1)
        printf("Passed\n");
    else
        printf("Failed\n");
}

// Function to allow a human and computer to play a game of Rock Paper Scissors
void FiveGestures() {
    int human_score = 0;
    int computer_score = 0;
    int rounds = 0;
//module that does the switches for each selected mode, and best of three in those functions, not main
    // randomly pick computer gesture

    srand(time(NULL));
//mode_select();
    // Best of three rounds
    while (rounds < 3 && human_score < 2 && computer_score < 2) {
        // Ask human for their gesture and randomly pick computer gesture
        FiveGestures();
//if mode = 5 get_gesture_five ect
        int human = get_gesture();
        int computer = get_random_gesture();

        // Show outcome of game
        printf("\e[0;37mThe \e[1;33mComputer\e[0;37m chose \e[1;33m");
        switch (computer) {
            case 0:
                printf("Rock");
                break;
            case 1:
                printf("Paper");
                break;
            case 2:
                printf("Scissors");
                break;
            case 3:
                printf("Lizard");
                break;
            case 4:
                printf("Spock");
                break;
        }

        printf(" \e[0;37mand \e[1;34myou \e[0;37mchose\e[1;34m ");

        switch (human) {
            case 0:
                printf("Rock");
                break;
            case 1:
                printf("Paper");
                break;
            case 2:
                printf("Scissors");
                break;
            case 3:
                printf("Lizard");
                break;
            case 4:
                printf("Spock");
                break;
        }
        printf(". \e[0;37m");

        int winner = determine_winner(computer, human);
        if (winner == 1) {
            human_score++;
            printf("You win this round!\n");
        } else if (winner == -1) {
            computer_score++;
            printf("Computer wins this round!\n");
        } else {
            printf("It's a tie!\n");
        }

        rounds++;
    }
//SHOW SCORE
    // Show winner of best of three
    if (human_score > computer_score)
        printf("\e[0;92mCongratulations! You win the game!\n");
    else if (human_score < computer_score)
        printf("\e[0;91mComputer wins the game!\n");
    else
        printf("The game ends in a tie!\n");


}

 void mode_select(){


    int mode;
    do {
        mode = get_int("Choose a mode:\n1. 5 gestures\n2. 7 gestures\n3. 9 gestures\n4. 11 gestures\n");
        if (mode < 1 || mode > 4) {
            printf("Invalid mode! Please enter a valid mode.\n");
        }
    } while (mode < 1 || mode > 4);

    //MODE SELECT
    switch (mode) {
        case 1:
            FiveGestures();
            break;
            /*
        case 2:
            SevenGestures();
            break;
        case 3:
            NineGestures();
            break;
        case 4:
            ElevenGestures();
            break;
*/
    }

}


// Main function
int main() {

mode_select();

    // Replay system
    char b = get_char("\e[0;35mWould you like to play again? \e[4;35my/n\n\n");

    if (b == 'y')
        main();
    else if (b == 'n')
        printf("\e[0;95mThanks for playing!!\n\n");

    return 0;
}
