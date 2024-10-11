#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "cs50.h"



/*switch (x) {

  case 0:
    printf("You picked rock\n");
    break;
  case 1:
    printf("You picked paper\n");
    break;
  case 2:
    printf("You picked scissors\n");
  default:
    printf("Enter a valid integer, choose 0, 1 or 2!\n");
    int check_int();
    }
return x;
}
*/

int determine_winner(int gesture_1, int gesture_2) {
    if (gesture_1 == gesture_2) // condition for tie
        return 0; // Tie
    else if ((gesture_1 == 0 && gesture_2 == 2) || // conditions for human winning, otherwise computer wins
             (gesture_1 == 1 && gesture_2 == 0) ||
             (gesture_1 == 2 && gesture_2 == 1))
        return 1; // Human wins
    else
        return -1; // Computer wins
}//from comp1000 '&&' AND operator, comp1000 '||' OR operator




int determine_winner(gesture_1, gesture_2) {
    if (gesture_1 == 0) {               // gesture_1 is rock
        if (gesture_2 == 1) {           // gesture_2 is paper - 2 wins
            return 1;
        } else if (gesture_2 == 0) {    // gesture_2 is rock - tie
            return 0;
        } else {                        // gesture_2 is scissors - 2 loses
            return -1;
        }
    } else if (gesture_1 == 1) {        // gesture_1 is paper
        if (gesture_2 == 2) {           // gesture_2 is scissors - 2 wins
            return 1;
        } else if (gesture_2 == 1) {    // gesture_2 is paper - tie
            return 0;
        } else {                        // gesture_2 is rock - 2 loses
            return -1;
        }
    } else {                            // gesture_1 is scissors
        if (gesture_2 == 0) {           // gesture_2 is rock - 2 wins
            return 1;
        } else if (gesture_2 == 2) {    // gesture_2 is scissors - tie
            return 0;
        } else {                        // gesture_2 is paper - 2 loses
            return -1;
        }
    }
}


// Function prototypes
int determine_winner(int gesture_1, int gesture_2);
int get_valid_input();

int main() {
    int computer;
    int human;
    int human_score = 0;
    int computer_score = 0;
    int rounds = 0; // rounds score

    // randomly pick computer gesture
    srand(time(NULL));

    // Best of three rounds
    while (rounds < 3 && human_score < 2 && computer_score < 2) {
        // ask human for their gesture
        human = get_valid_input();

        // randomly pick computer gesture
        computer = rand() % 3;

        // determine winner
        int winner = determine_winner(computer, human);

        // show outcome of game
        printf("The computer chose ");
        switch (computer) {
            case 0:
                printf("rock");
                break;
            case 1:
                printf("paper");
                break;
            case 2:
                printf("scissors");
                break;
        }
        printf(" and you chose ");
        switch (human) {
            case 0:
                printf("rock");
                break;
            case 1:
                printf("paper");
                break;
            case 2:
                printf("scissors");
                break;
        }
        printf(". ");

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

    // Show winner of best of three
    if (human_score > computer_score)
        printf("Congratulations! You win the game!\n");
    else if (human_score < computer_score)
        printf("Computer wins the game!\n");
    else
        printf("The game ends in a tie!\n");

    return 0;
}



int get_valid_input() {
    int input;
    printf("Please enter your gesture\n");
    input = get_int("Enter 0 for rock, 1 for paper, 2 for scissors: \n");

    // Validate human input
    while (input < 0 || input > 2) {
        printf("Invalid input! Please enter 0, 1, or 2.\n");
        input = get_int("Enter 0 for rock, 1 for paper, 2 for scissors: \n");
    }

    return input;
}
