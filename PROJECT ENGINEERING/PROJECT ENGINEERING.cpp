
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define SPOCK 3
#define LIZARD 4

#define WATER 3
#define FIRE 4
#define SPONGE 5
#define AIR 6

#define HUMAN 7
#define GUN 8

#define WOLF 9
#define DEVIL 10


#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int check_gesture(int g, int mode);
int determine_winner(int mode, int player, int comp);
int get_gesture(int mode);
int get_random_gesture(int mode);
void play_game(int mode);
void mode_select();
void replay_game();

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
int check_gesture(int g, int mode) {
    // Validate human input based on the mode
    switch (mode) {//                                            |
    case 1: // Mode 1: 5 gestures                           |
        if (g >= 0 && g <= 4) {// g is between 0-4 ect      |
            return 0; // Valid gesture                      |
        }
        else {     //                                     V
            printf("\e[1;91mInvalid gesture! Please enter a number between 0 and 4.\e[0m\n");
            return 1; // Invalid gesture
        }
        break;
    case 2: // Mode 2: 7 gestures
        if (g >= 0 && g <= 6) {
            return 0; // Valid gesture
        }
        else {
            printf("\e[1;91mInvalid gesture! Please enter a number between 0 and 6.\e[0m\n");
            return 1; // Invalid gesture
        }
        break;
    case 3: // Mode 3: 9 gestures
        if (g >= 0 && g <= 8) {
            return 0; // Valid gesture
        }
        else {
            printf("\e[1;91mInvalid gesture! Please enter a number between 0 and 8.\e[0m\n");
            return 1; // Invalid gesture
        }
        break;
    case 4: // Mode 4: 11 gestures
        if (g >= 0 && g <= 10) {
            return 0; // Valid gesture
        }
        else {
            printf("\e[1;91mInvalid gesture! Please enter a number between 0 and 10.\e[0m\n");
            return 1; // Invalid gesture
        }
        break;
        // Add more cases for other modes as needed
    default:
        printf("Invalid mode!\n");
        return 1; // Invalid mode
    }
}                      //                                                                                       1 of 5 conditions for player winning
// Function to determine if gesture 2 wins or loses                                                                             |
// Returns 1 for win, 0 for tie, -1 for loss                                                             |----------------------|----------------------|
int determine_winner(int mode, int player, int comp) {// NEW ALGORITHM!!!!!  if players gesture is rock, AND the computers gesture is scissors OR lizard, return -1
    int result = 0;

    switch (mode) {
    case 1:
        if (player == comp) {
            result = 0; // Tie
        }
        else if ((player == ROCK && (comp == SCISSORS || comp == LIZARD)) || // just code the conditions for human winning, otherwise computer wins or if result is zero then replay round
            (player == PAPER && (comp == ROCK || comp == SPOCK)) ||
            (player == SCISSORS && (comp == PAPER || comp == LIZARD)) ||
            (player == LIZARD && (comp == SPOCK || comp == PAPER)) ||
            (player == SPOCK && (comp == ROCK || comp == SCISSORS))) {
            result = 1; // Human wins
        }
        else {
            result = -1; // Computer wins
        }
        break;

    case 2:
        if (player == comp) {
            result = 0; // Tie
        }
        else if ((player == ROCK && (comp == FIRE || comp == SCISSORS || comp == SPONGE)) ||
            (player == PAPER && (comp == ROCK || comp == AIR || comp == WATER)) ||
            (player == SCISSORS && (comp == PAPER || comp == AIR || comp == SPONGE)) ||
            (player == SPONGE && (comp == AIR || comp == PAPER || comp == WATER)) ||
            (player == FIRE && (comp == PAPER || comp == SCISSORS || comp == SPONGE)) ||
            (player == AIR && (comp == FIRE || comp == ROCK || comp == WATER)) ||
            (player == WATER && (comp == SCISSORS || comp == ROCK || comp == FIRE))) {
            result = 1; // Human wins
        }
        else {
            result = -1; // Computer wins
        }
        break;

    case 3:
        if (player == comp) {
            result = 0; // Tie
        }
        else if ((player == ROCK && (comp == FIRE || comp == SCISSORS || comp == SPONGE || comp == HUMAN)) ||
            (player == PAPER && (comp == ROCK || comp == AIR || comp == WATER || comp == GUN)) ||
            (player == SCISSORS && (comp == PAPER || comp == AIR || comp == SPONGE || comp == HUMAN)) ||
            (player == SPONGE && (comp == AIR || comp == PAPER || comp == WATER || comp == GUN)) ||
            (player == FIRE && (comp == PAPER || comp == SCISSORS || comp == SPONGE || comp == HUMAN)) ||
            (player == AIR && (comp == FIRE || comp == ROCK || comp == WATER || comp == GUN)) ||
            (player == WATER && (comp == SCISSORS || comp == ROCK || comp == FIRE || comp == GUN)) ||
            (player == HUMAN && (comp == PAPER || comp == AIR || comp == WATER || comp == SPONGE)) ||
            (player == GUN && (comp == SCISSORS || comp == ROCK || comp == FIRE || comp == HUMAN))) {
            result = 1; // Human wins
        }
        else {
            result = -1; // Computer wins
        }
        break;

    case 4:
        if (player == comp) {
            result = 0; // Tie
        }
        else if ((player == ROCK && (comp == FIRE || comp == SCISSORS || comp == SPONGE || comp == HUMAN || comp == WOLF)) ||
            (player == PAPER && (comp == ROCK || comp == AIR || comp == WATER || comp == GUN || comp == DEVIL)) ||
            (player == SCISSORS && (comp == PAPER || comp == AIR || comp == SPONGE || comp == HUMAN || comp == WOLF)) ||
            (player == SPONGE && (comp == AIR || comp == PAPER || comp == WATER || comp == GUN || comp == DEVIL)) ||
            (player == FIRE && (comp == PAPER || comp == SCISSORS || comp == SPONGE || comp == HUMAN || comp == WOLF)) ||
            (player == AIR && (comp == FIRE || comp == ROCK || comp == WATER || comp == GUN || comp == DEVIL)) ||
            (player == WATER && (comp == SCISSORS || comp == ROCK || comp == FIRE || comp == GUN || comp == DEVIL)) ||
            (player == HUMAN && (comp == PAPER || comp == AIR || comp == WATER || comp == SPONGE || comp == WOLF)) ||
            (player == GUN && (comp == SCISSORS || comp == ROCK || comp == FIRE || comp == HUMAN || comp == WOLF)) ||
            (player == WOLF && (comp == SPONGE || comp == PAPER || comp == AIR || comp == WATER || comp == DEVIL)) ||
            (player == DEVIL && (comp == SCISSORS || comp == ROCK || comp == FIRE || comp == GUN || comp == HUMAN))) {
            result = 1; // Human wins
        }
        else {
            result = -1; // Computer wins
        }
        break;

    default:
        printf("Invalid mode!\n");
        result = 2; // Return an invalid value to indicate an error
    }

    return result; // Return the result
}






// Function to prompt for a gesture

// pass get_gesture an in c for switch
// Function to prompt for a gesture based on the selected mode
int get_gesture(int mode) {
    int gesture;
    int valid_input = 0; // Flag to track if the input is valid

    do {
        switch (mode) {
        case 1: {
            printf("\e[4;35mPlease enter your gesture:\e[0m\n");
            gesture = get_int("\e[0;35mEnter 0 for rock, 1 for paper, 2 for scissors, 3 for spock, 4 for lizard: \e[0m\n");
            break;
        }
        case 2: {
            printf("\e[4;35mPlease enter your gesture:\e[0m\n");
            gesture = get_int("\e[0;35m\n"
                "'0' for rock,'1' for paper, '2' for scissors, "
                "'3' for water, '4' for fire, '5' for sponge, '6' for air.\n\e[0m\n");
            break;
        }
        case 3: {
            printf("\e[4;35mPlease enter your gesture:\e[0m\n");
            gesture = get_int("\e[0;35m\n"
                "'0' for rock\n'1' for paper\n'2' for scissors\n"
                "'3' for water\n'4' for fire\n'5' for sponge\n"
                "'6' for air\n'7' for human\n'8' for gun\n\e[0m\n");
            break;
        }
        case 4: {
            printf("\e[4;35mPlease enter your gesture:\e[0m\n");
            gesture = get_int("\e[0;35m\n"
                "'0' for rock\n'1' for paper\n'2' for scissors\n"
                "'3' for water\n'4' for fire\n'5' for sponge\n"
                "'6' for air\n'7' for human\n'8' for gun\n"
                "'9' for wolf\n'10' for devil\n\e[0m\n");
            break;
        }
        default: {
            printf("Invalid mode selected!\n");
            return -1; // Return an invalid value to indicate an error
        }
        }
        // Check if the gesture is valid
        if (check_gesture(gesture, mode) == 0) {
            valid_input = 1; // Set the flag to indicate valid input
        }
        else {

        }
    } while (!valid_input); // Repeat until a valid input is received

    return gesture;
}

// Function to randomly generate a gesture
int get_random_gesture(int mode) {
    switch (mode) {
    case 1: // Mode 1: 5 gestures
        return rand() % 5; // Generate a random number between 0 and 4
        break;
    case 2: // Mode 2: 7 gestures
        return rand() % 7; // Generate a random number between 0 and 6
        break;
    case 3: // Mode 3: 9 gestures
        return rand() % 9; // Generate a random number between 0 and 8
        break;
    case 4: // Mode 4: 11 gestures
        return rand() % 11; // Generate a random number between 0 and 10
        break;
    default:
        printf("Invalid mode!\n");
        return -1; // Return an invalid gesture value
    }
}

void play_game(mode) {
    //module that does the switches for each selected mode, and best of three in those functions, not main
    // randomly pick computer gesture


    //mode_select();
    // Best of three rounds
    //while it has been less than 3 rounds AND the players score is still below 2 AND comps score below 2, do the following:
    //makes sure that if either the computer or the player win 2 rounds the automatically win the game
    // Ask human for their gesture and randomly pick computer gesture

    int human_score = 0;
    int computer_score = 0;
    int rounds = 0;
    srand(time(NULL));
    // Best of three rounds
    while (rounds < 3 && human_score < 2 && computer_score < 2) {
        // Display round number
        printf("\e[0;96m\nRound %d/3:\e[0m\n\n", rounds + 1);

        // Get gestures
        int human = get_gesture(mode);
        int computer = get_random_gesture(mode);

        // Display chosen gestures
        printf("\e[0;37mThe \e[0;31mComputer\e[0;37m chose \e[0;31m");
        if (mode == 1) {
            switch (computer) {
            case 0:
                printf("Rock (0)");
                break;
            case 1:
                printf("Paper (1)");
                break;
            case 2:
                printf("Scissors (2)");
                break;
            case 3:
                printf("Spock (3)");
                break;
            case 4:
                printf("Lizard (4)");
                break;
            }

            printf(" \e[0;37mand \e[1;92mYou \e[0;37mchose\e[1;92m ");

            switch (human) {
            case 0:
                printf("Rock (0)");
                break;
            case 1:
                printf("Paper (1)");
                break;
            case 2:
                printf("Scissors (2)");
                break;
            case 3:
                printf("Spock (3)");
                break;
            case 4:
                printf("Lizard (4)");
                break;
            }
            printf(". \e[0m");

        }

        else if (mode == 2 || mode == 3 || mode == 4) {

            switch (computer) {
            case 0:
                printf("Rock (0)");
                break;
            case 1:
                printf("Paper (1)");
                break;
            case 2:
                printf("Scissors (2)");
                break;
            case 3:
                printf("Water (3)");
                break;
            case 4:
                printf("Fire (4)");
                break;
            case 5:
                printf("Sponge (5)");
                break;
            case 6:
                printf("Air (6)");
                break;
            case 7:
                printf("Human (7)");
                break;
            case 8:
                printf("Gun (8)");
                break;
            case 9:
                printf("Wolf (9)");
                break;
            case 10:
                printf("Devil (10)");
                break;
            }

            printf(" \e[0;37mand \e[1;92mYou \e[0;37mchose\e[1;92m ");
            switch (human) {
            case 0:
                printf("Rock (0)");
                break;
            case 1:
                printf("Paper (1)");
                break;
            case 2:
                printf("Scissors (2)");
                break;
            case 3:
                printf("Water (3)");
                break;
            case 4:
                printf("Fire (4)");
                break;
            case 5:
                printf("Sponge (5)");
                break;
            case 6:
                printf("Air (6)");
                break;
            case 7:
                printf("Human (7)");
                break;
            case 8:
                printf("Gun (8)");
                break;
            case 9:
                printf("Wolf (9)");
                break;
            case 10:
                printf("Devil (10)");
                break;
            }
            printf(". \e[0m");

        }

        //was tripped up cos i had a break statement below 'printf(". \e[0m");' which just ended the function and went straight to replay_game in mode_select
        //SHOW SCORE
        // Show winner of best of three
              // Determine winner and update scores
        int winner = determine_winner(mode, computer, human);
        if (winner == -1) {
            human_score++;
            rounds++;//makes rounds go up in either case of the human winning or computer, but not if its a tie, so the round replays
            printf("\n\n\e[1;92mYou win this round!\e[0m\n");
        }
        else if (winner == 1) {
            computer_score++;
            rounds++;
            printf("\n\n\e[0;31mComputer wins this round!\e[0m\n");
        }
        else {
            printf("\n\n\e[1;93mIt's a tie! Replaying the round!\e[0m\n");
        }


    }

    // Display final winner
    if (human_score > computer_score) {
        printf("\n\e[1;92mCongratulations! You win the game!\e[0m\n\n");
    }
    else if (human_score < computer_score) {
        printf("\e[1;91mComputer wins the game!\e[0m\n");
    }
}




void mode_select() {
    int mode;
    do {
        mode = get_int("\e[4;35mChoose a mode:\e[0m\n\n\e[0;95mPress '1' for 5 gestures\nPress '2' for 7 gestures\nPress '3' for 9 gestures\nPress '4' for 11 gestures\e[0m\n");
        if (mode < 1 || mode > 4) {
            printf("\e[1;91mInvalid mode! Please enter a valid mode.\n");
        }
    } while (mode < 1 || mode > 4);
    play_game(mode);
    replay_game();
}




void replay_game() {
    char q;
    do {
        printf("\e[0;35mWould you like to play again? \e[4;35my/n\n\n");
        q = get_char("");
        if (q != 'y' && q != 'n') {
            printf("\e[0;31mInvalid input! Please enter 'y' or 'n'.\n\n");
        }
    } while (q != 'y' && q != 'n');

    if (q == 'y') {
        printf("\n\n");
        mode_select(); // Restart the game
    }
    else {
        printf("\e[0m\e[1;93mThanks for playing!!\e[0m\n\n");
    }
}


int main() {
    srand(time(NULL)); // Seed the random number generator

    // Play the game
    mode_select();

    // Replay the game if the player wants to play again


    return 0;
}
