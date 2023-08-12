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
void mqttPlayerMove();
void comptuerMove();
void displayResult(int status);

int checkWinner(); 
int isFull();
int mode1(); 
int mode2();
int mode3();



// global variables
char board[9];
char winner;
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

    printf("How the board is lay out\n");
    printf("+-----------+\n");
    printf("| 7 | 8 | 9 |\n");
    printf("+-----------+\n");
    printf("| 4 | 5 | 6 |\n");
    printf("+-----------+\n");
    printf("| 1 | 2 | 3 |\n");
    printf("+-----------+\n");

    // Main game starts here
    do{
        // Every enter here is new start
        resetBoard();
        winner = ' ';
        int choice = 0;

        // menu
        printf("\n\n\nThis is start of a new game!\n");
        printf("1) You vs Computer\n");
        printf("2) You vs Player2\n");
        printf("3) You vs Player3 (Other device)\n");
        printf("4) Quit\n");
        scanf("%d", &choice);

        if(choice == 1)
        {
            keepPlay = mode1();
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
    int validate = 0;
    printf("Player1's choice: ");
    do{
        scanf("%d",&input);
        if((input > 0) && (input < 10) && (board[input-1] == ' '))
        {
            // validated
            board[input-1] = 'X';
            validate=1;
        }
        else
        {
            printf("Please enter correct input...\n");
            validate =0;
        }
    } while(validate == 0);

}

void player2Move()
{
    int input;
    int validate = 0;
    printf("Player2's choice: ");
    do{
        scanf("%d",&input);
        if((input > 0) && (input < 10) && (board[input-1] == ' '))
        {
            // validated
            board[input-1] = 'O';
            validate=1;
        }
        else
        {
            printf("Please enter correct input...\n");
            validate =0;
        }
    } while(validate == 0);

}

void comptuerMove()
{
    int input;
    int validate = 0;
    do{
        input = rand() % 9;
        if(board[input-1] == ' ')
        {
            board[input] = 'O';
            validate = 1;
        } 
    }while(validate == 0); 
}


int mode1()
{
    // SEED RNG
    srand(time(NULL));

    int counter = 0; 
    int turn = 0;
    int haveWinner=0;

    while(haveWinner==0)
    {
        counter = counter % 2;
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
        counter++;
        
    }
    displayResult(haveWinner);

    return 1;
    
}

int mode2()
{
    // SEED RNG
    srand(time(NULL));

    int counter = 0; 
    int turn = 0;
    int haveWinner=0;

    while(haveWinner==0)
    {
        counter = counter % 2;
        if(counter == 0)
        {
            player1Move();
        }
        else
        {
            player2Move();
        }
        displayBoard();
        haveWinner = checkWinner();
        counter++;
        
    }
    displayResult(haveWinner);

    return 1;
    
}

int mode3()
{
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
    if(status == -1)
    {
        printf("It's a TIE!\n");
    }
    else if(winner == 'X')
    {
        printf("Congrats! You WON the game!!!!\n");
    }
    else
    {
        printf("Player2 WON!!\n");
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
