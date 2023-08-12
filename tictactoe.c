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
void displayBoard();
void resetBoard();
void player1Move();
void player2Move(); // this function is for the user 2, other end user
void comptuerMove();
void displayResult(int status);

int checkWinner(); 
int isFull();
int mode1(); 
int mode2();
int mode3();



// global variables
char board[9];
//char winner;
const char O = 'O';
const char X ='X';



int main()
{

    //variables
    int keepPlay = 1; // 0 = stop, 1 = continue


    printf("Welcome to the Tic-Tac-Toe!\n");
    for (int i = 0; i < 3; i++)
    {
        printf(".");
    }
    printf("\n");



    // Main game starts here
    do{
        // Every enter here is new start
        int status = 0; // 0=noWinner 1=user1 win, 2=user2 win, 3=tie
        int choice = 0;

        // menu
        printf("\n\n\n This is start of a new game!\n");
        printf("1) You vs Computer\n");
        printf("2) You vs Player2\n");
        printf("3) You vs Player3 (Other device)\n");
        printf("4) Quit\n");
        scanf("%d", &choice);

        if(choice == 1)
        {
            keepPlayer = mode1();
        }
        else if(choice == 2)
        {
            keepPlay = mode2();
        }
        else if(choice == 3)
        {
            keepPlay = mode3();
        }
        else if(choice == 4)
        {
            keepPlay = 0;

        }
        else
        {
            printf("Invaild input... \nEnter a valid input\n");
            keepPlay = 1;
        }

    } while (keepPlay == 1);


    printf("Thanks for playing...\n");

    return 0;
}

void player1Move()
{
    int input;
    printf("Player1's choice: ");
    scanf("%d",&input);

}

int mode1()
{
    // SEED RNG
    srand(time(0));

    int counter = 0; 
    int turn = 0;
    int haveWinner=0;

    while(haveWinner==0)
    {
        if(counter == 0)
        {
            player1Move();
        }
        else
        {
            comptuerMove();
        }
        displayBoard();
        haveWinner = checkWinner();
        counter == counter % 2;
    }
    displayResult(haveWinner);

    return 1;
    
}



void displayBoard()
{
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", board[6],board[7],board[8]);
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", board[3],board[4],board[5]);
    printf("+-----------+\n");
    printf("| %c | %c | %c |\n", board[0],board[1],board[2]);
    printf("+-----------+\n");
}

void resetBoard()
{
    for(int i = 0; i < 9; i++)
    {
        board[i] = ' ';
    }
}

void displayResult(int status)
{
    if(status == 1)
    {
        printf("CONGRATS YOU WON!!!!\n");
    }
    else if(status == 2)
    {
        printf("OOPS, Other player win... Try next time!\n");
    }
    else if(status == 3)
    {
        printf("It's a TIE!\n");
    }
}


int isFull()
{
    
    for(int i = 0; i < 9; i++)
    {
        if(board[i] == ' ')
        {
            // if any of the spot in board has whitespace, it is not full
            return 0;
        }
    }

    return 1; 
}


int checkWinner()
{
    // 0 = continue play, 1 = yes winner, -1 = tie

    if((board[0] == board[1]) && (board[0] == board[2]) && (board[0] != ' '))
    {
        winner = board[0];
        return 1;
    }
    else if((board[3] == board[4]) && (board[3] == board[5]) && (board[3] != ' '))
    {
        winner = board[3];
        return 1;
    }
    else if((board[6] == board[7]) && (board[6] == board[8]) && (board[6] != ' '))
    {
        winner = board[6];
        return 1;
    }
    else if((board[0] == board[3]) && (board[0] == board[6]) && (board[0] != ' '))
    {
        winner = board[0];
        return 1;
    }
    else if((board[1] == board[4]) && (board[1] == board[7]) && (board[1] != ' '))
    {
        winner = board[1];
        return 1;
    }
    else if((board[2] == board[5]) && (board[2] == board[8]) && (board[2] != ' '))
    {
        winner = board[2];
        return 1;
    }
    else if((board[0] == board[4]) && (board[0] == board[8]) && (board[0] != ' '))
    {
        winner = board[0];
        return 1;
    }
    else if((board[2] == board[4]) && (board[2] == board[6]) && (board[2] != ' '))
    {
        winner = board[3];
        return 1;
    }
    else
    {
        int full = 0;
        full = isFull();
        if(full == 1)
        {
            // board is full but no winner == tie
            return -1; 
        }
        return 0;

    }
}
