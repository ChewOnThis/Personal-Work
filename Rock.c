#include <stdio.h>
#include <cs50.h>

 string whowins(playera, playerb) {
    string winner;
        if (playera == 0) {
            if (playerb == 1) {
             winner = "Player 1 wins!";
            } else if (playerb == 0) {
                winner = "It's a tie!";
            } else {
                winner = "Player 2 wins!";
            }
        } else if (playera == 1) {
            if (playerb == 2) {
                winner = "Player 1 wins!";
            } else if (playerb == 1) {
                winner = "It's a tie!";
            } else {
                winner = "Player 2 wins!";
            }
        }  if (playera == 2) {
            if (playerb == 0) {
                winner = "Player 1 wins!";
            } else if (playerb == 2) {
                winner = "It's a tie!";
            } else {
                winner = "Player 2 wins!";
            }
        }
        return winner;
    }

int main()
{



    int playerb = get_int("Player 1, enter 0 for rock, 1 for paper, 2 for scissors: ");
int playera = get_int("Player 2 enter 0 for rock, 1 for paper, 2 for scissors: ");






string winner = whowins(playera,playerb);

    printf("Player 2 chose %d and Player 1 chose %d. %s\n",playera,playerb,winner);

    return 0;
}





