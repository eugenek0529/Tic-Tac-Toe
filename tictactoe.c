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
void displayResult(int status);

int checkWinner(); 
int isFull();
int mode1(); 
int mode2();
int mode3();



// global variables
char board[3][3];
char winner;
const char O = 'O';
const char X ='X';



int main()
{

    //variables
    int keepPlay = 1; // 0 = stop, 1 = continue

    /*
        Outer do-while loop with listing menu
        inner do-while loop is continuous game play until other mode or exit

    */

    //game loadimg (use of delauy, 1 sec = 1000 ms)
    printf("Welcome to the Tic-Tac-Toe!\n");
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        delay(1000);
    }
    printf("\n");



    // Main game starts here
    do{
        // Every enter here is new start
        int status = 0; // 1=user1 win, 2=user2 win, 3=tie
        int choice;

        // menu
        printf("1) You vs Computer\n");
        printf("2) You vs Player2\n");
        printf("3) You vs Player3 (Other device)\n");
        printf("4) Quit\n");
        scanf("%d", &choice);

        if(choice == 1)
        {
            status = mode1();
            displayResult(status);
        }
        else if(choice == 2)
        {
            status = mode2()
            displayResult(status);
        }
        else if(choice == 3)
        {
            status = mode3();
            displayResult(status)
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


    Printf("Thanks for playing...\n");

    return 0;
}

int mode1()
{
    // SEED RNG
    srand(time(0));

    int counter = 2; 
    int turn = 0;
    int winner;

    do{

        
    }
    
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
