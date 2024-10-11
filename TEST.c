/**
    Test the functionality of deterimine_winner
**/
#include "cs50.h"
#include "rps_elements.h" //comment this line out for exercise 2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// this function is used to determine if gesture 2 wins or loses
//  returns 1 for win, 0 for tie, -1 for loss
int determine_winner(gesture_1, gesture_2) {
  if (gesture_1 == 0) {   // gesture_1 is rock
    if (gesture_2 == 1) { // gesture_2 is paper - 2 wins
      return 1;
    } else if (gesture_2 == 0) { // gesture_2 is rock - tie
      return 0;
    } else { // gesture_2 is scissors - 2 loses
      return 1;
    }
  } else if (gesture_1 == 1) { // gesture_1 is paper
    if (gesture_2 == 2) {      // gesture_2 is scissors - 2 wins
      return 1;
    } else if (gesture_2 == 1) { // gesture_2 is paper - tie
      return 0;
    } else { // gesture_2 is rock - 2 loses
      return -1;
    }
  } else {                // gesture_1 is scissors
    if (gesture_2 == 0) { // gesture_2 is rock - 2 wins
      return 1;//  <<-------------------------------------------------------  was -1
    } else if (gesture_2 == 2) { // gesture_2 is scissors - tie
      return 0;
    } else { // gesture_2 is paper - 2 loses
      return -1; // <<------------------------------------------------------- was 1 NOW PASSES WIN TEST
    }
  }
}



// this function is used to show who wins
void show_winner(winner) {
  if (winner == 1)
    printf("You win!\n");
  else if (winner == 0)
    printf("The game is a tie.\n");
  else if (winner == -1)
    printf("Computer wins!\n");
}




  // finish this function
// this function is used to check whether a gesture is valid
int check_gesture(int g) {
   // Validate human input
    if (g == 0 || g == 1 || g == 2) {
        return 0; // Valid gesture
    } else {
        return 1; // Invalid gesture
    }// Return 0 if the gesture is valid. Otherwise it should return a 1
}

// Function to run tests for the check_gesture function
void test_check_gesture() {
    // Test with valid gestures
    printf("***Testing 'check_gesture':\n");
    printf("Test 1: Valid gesture 0 (rock) - Result: ");
    if (check_gesture(0) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");

    printf("Test 2: Valid gesture 1 (paper) - Result: ");
    if (check_gesture(1) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");

    printf("Test 3: Valid gesture 2 (scissors) - Result: ");
    if (check_gesture(2) == 0)
        printf("Passed\n");
    else
        printf("Failed\n");

    // Test with invalid gesture
    printf("Test 4: Invalid gesture 3 - Result: ");
    if (check_gesture(3) == 1)
        printf("Passed\n");
    else
        printf("Failed\n");
}







// this function prompts for a gesture
int get_gesture() {
  printf("Please enter your gesture\n");
  return get_int("Enter 0 for rock, 1 for paper, 2 for scissors: ");

}

// this function is used to randomly generate a gesture
int get_random_gesture() {
  int MYMAX = 2;
  return (rand() / (double)RAND_MAX) * (MYMAX + 1);
}
// This function is to test determine_winner function, try to read and
// understand what this function does. Draw a flow chart for this function if
// can.
_determine_winner(int gesture2) {
  printf("***Testing when gesture 2 is rock\n");
  printf("Tie Test: ");
  if (determine_winner(gesture2, gesture2) == 0)
    printf("Passed\n");
  else
    printf("Failed\n");

  printf("Lose Test: ");
  if (determine_winner(1, gesture2) == -1)
    printf("Passedvoid test\n");
  else
    printf("Failed\n");

  printf("Win Test: ");
  if (determine_winner(2, gesture2) == 1)
    printf("Passed\n");
  else
    printf("Failed\n");
}

// this function allows a human and computer to play a game of Rock Paper
// Scissors
void human_computer() {
  // randomly pick computer gesture
  int computer = get_random_gesture();

  // ask human for their gesture
  int human = get_gesture();

  // print out gestures
  printf(" Computer chose: %d\n You chose: %d\n", computer, human);

  // determine & show winner
  show_winner(determine_winner(computer, human));
}

// this function allows the computer to play a game of Rock Paper Scissors
// against itself
void computer_computer() {

  //function to simulate games
    int computer1_score = 0;
    int computer2_score = 0;
    int num_games = 1000; //number of sims

    srand(time(NULL));

    for (int a = 0; a < num_games; a++) {

        //random gestures
        int computer1_gesture = rand() % 3; // random numbers between 0 and 2 inclusive
        int computer2_gesture = rand() % 3;// if bigger than 3, leaves more options for undefined for both gestures, results in higher ties
/*
ie. if % 8 means there are options from 0-7, 3 of them are valid, 4 of them are invalid:
results in more ties as if both bots choose invalids results in tie.
*/

//COMMENT OUT for games more than 1
/*
  printf("Computer 1 chose ");
        switch (computer1_gesture) {
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
        printf(" and Computer 2 chose ");
        switch (computer2_gesture) {
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
        printf(". \n");

*/
        //determine winner                           cases for comp1 winning
        if ((computer1_gesture == 0 && computer2_gesture == 2) || //if comp1 = rock AND comp2 = scissors OR... ect ect: comp 1 wins
            (computer1_gesture == 1 && computer2_gesture == 0) ||
            (computer1_gesture == 2 && computer2_gesture == 1)) {
            computer1_score++; //computer 1 wins
        } else if ((computer2_gesture == 0 && computer1_gesture == 2) || //^ same just for comp2
                   (computer2_gesture == 1 && computer1_gesture == 0) ||
                   (computer2_gesture == 2 && computer1_gesture == 1)) {
            computer2_score++; //computer 2 wins
        }

    }
        //tie for same gestures


    //results

    printf("Computer 1 wins: %d\n", computer1_score);
    printf("Computer 2 wins: %d\n", computer2_score);
    printf("Ties: %d\n", num_games - computer1_score - computer2_score);
}


// this function allows a two humans to play a game of Rock Paper Scissors
void human_human() {
  // finish this function
      //player 1&2 gesture
    int p1 = get_gesture();
    int p2 = get_gesture();

//who wins:
    int winner = determine_winner(p1, p2);

    //display outcome
    if (winner == 1)
        printf("Player 1 wins!\n");
    else if (winner == -1)
        printf("Player 2 wins!\n");
    else
        printf("It's a tie!\n");
}



   void mode_select(){
    // Prompt the user to choose a mode
    printf("Choose a mode:\n");
    printf("1. Human vs Computer\n");
    printf("2. Computer vs Computer\n");
    printf("3. Human vs Human\n");

//MODE SELECT
    int mode;
    do {
        mode = get_int("Enter the mode number: ");
        if (mode < 1 || mode > 3) {
            printf("Invalid mode! Please enter a valid mode.\n");
        }
    } while (mode < 1 || mode > 3);

    //MODE SELECT
    switch (mode) {
        case 1:
            human_computer();
            break;
        case 2:
            computer_computer();
            break;
        case 3:
            human_human();
            break;
    }
}



int main() {
    // Run tests
    test_determine_winner(0);
    test_check_gesture();

 // initialise the random number generator, otherwise the results would be predictable
    srand(time(NULL));
mode_select();

//REPLAY SYSTEM
//function for replay doesnt work as it endlessly calls main which is fucked
    char b = get_char("Would you like to play again? y/n\n");

    if (b == 'y')
        main();
    else if (b == 'n')
        printf("Thanks for playing!!");


}
