/*

    Program: tictactoe.c
    Programmer: Eugene Kim
    About: 
        * First is to create a structure of game tic-tac-toe
            * mode 1 User vs Computer
            * mode 2 User vs User via same keyboard
            * mode 3 user vs user via MQTT
        * Then Use MQTT to communicate with other end user to 
           play game together


*/
#include <stdio.h> 
#include <time.h>


// function prototypes
void makeMove();
void displayBoard();
void resetBoard();
void player1Move();
void player2Move(); // this function is for the user 2, other end user
int checkWinner(); 
int isFull();


// global variables
char board[3][3];
char winner;
const char O = 'O';
const char X ='X';

int main()
{




    return 0;
}