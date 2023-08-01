/*

    Program: tictactoe.c
    Programmer: Eugene Kim
    About: 
        * User 1 = main player
        * User 2 = other end player
        * Computer player
        * First is to create a structure of game tic-tac-toe
            * mode 1 User vs Computer
            * mode 2 User vs User via same keyboard
            * mode 3 user vs user via MQTT
        * Then Use MQTT to communicate with other end user to 
           play game together


*/
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>


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

    // SEED RNG
    srand(time(0));

    //variables
    int keepPlay = 0; // 0 = stop, 1 = continue


    /*
        Outer do-while loop with listing menu
        inner do-while loop is continuous game play until other mode or exit

    */

    printf("Welcome to the Tic-Tac-Toe!\n");
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        delay(1000);
    }
    printf("\n");


    do{
        // Every enter here is new start
        int status = 0; // track the game status
        int 

        do{

        }

    } while (keepPlay == 1);




    return 0;
}


void displayBoard()
{
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", board[0][0],board[0][1],board[0][2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", board[1][0],board[1][1],board[1][2]);
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", board[2][0],board[2][1],board[2][2]);
    printf("+-----------+\n");
}

void resetBoard()
{
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            board[i][j] = ' ';
        }
    }
}


int isFull()
{
    
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j<3;++j)
        {
            if(board[i][j] == ' ')
            {
                // if encounter any open spot, then it not full
                return 0; 
            }
        }
    }

    return 1; 
}


int checkWinner()
{
    // initially 0 = progressing
    int result = 0; 
    int check; 

    if((board[0][0] == board[0][1]) && (board[0][1] == board[0][2]) && board[0][0] != ' ') 
    {
        // Column check start
        winner = board[0][0]; // store winning character 
        return 1;
    }
    else if((board[1][0] == board[1][1]) && (board[1][1] == board[1][2]) && board[1][0] != ' ') 
    {
        winner = board[1][0];
        return 1;    
    }
    else if((board[2][0] == board[2][1]) && (board[2][1] == board[2][2]) && board[2][0] != ' ')
    {
        winner = board[2][0];
        return 1; 
    } 
    else if((board[0][0] == board[1][0]) && (board[1][0] == board[2][0]) && board[0][0] != ' ')
    {
        // ROW check start
        winner = board[0][0];
        return 1; 
    }
    else if((board[0][1] == board[1][1]) && (board[1][1] == board[2][1]) && board[0][1] != ' ')
    {
        winner = board[0][1];
        return 1; 
    }
    else if((board[0][2] == board[1][2]) && (board[1][2] == board[2][2]) && board[0][2] != ' ')
    {
        winner = board[0][2];
        return 1; 
    }
    else if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[0][0] != ' ')
    {
        // diagnal check start
        winner = board[0][0];
        return 1; 
    }
    else if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[0][2] != ' ')
    {
        winner = board[0][2];
        return 1; 
    }
    else
    {
        check = isFull(); 

        //enter here if no match found
        if(check == 1)
        {
            //enter here when board is full, but no matching winner found
            return -1; // tie
        }
        else
        {
            return 0; //still progressing
        }

    }

    return result;
    


}
