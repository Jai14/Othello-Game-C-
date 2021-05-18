//
// Created by Jai Narayana on 18-05-2021.
//

//header files
#include <stdio.h>

//global variables
char board[9][9];
char player1[20],player2[20];
int player1_score,player2_score;

//getname definition
void getname(){
    printf("Enter PLAYER-1/BLACK COIN name :");
    scanf("%s",player1); //takes the player 1 name
    printf("Enter PLAYER-2/WHITE COIN name :");
    scanf("%s",player2); //takes the player 2 name
}

//countWB definition
void countWB(){
    int count1=0;
    int count2=0;
    for(int i=1;i<9;i++){  //for all the position in board
        for(int j=1;j<9;j++){
            if(board[i][j]=='W') //checks if its white
            {
                count2++;
            }
            if(board[i][j]=='B') //checks if its black
            {
                count1++;
            }
        }
    }
    player1_score=count1; //sets the black points to player 1
    player2_score=count2; //sets the white points to player 2
    printf("[W = %i / B = %i]\n",count1,count2); //prints the statement
}

//printboard definition
void printboard(){
    char x='a';
    int number=1;

    //prints the board according to the template
    for(int i=1;i<9;i++)
    {
        printf("%i ",number++);
        for(int j=1;j<9;j++){
            printf(" %c ",board[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for(int i=1;i<9;i++)
    {
        printf(" %c ",x++);
    }

    printf("\n");
    countWB(); //updates the point
}

//initial definition
void initial(){
    //for all position board gets initialized to dot/'.'
    for(int i=1;i<9;i++){
        for(int j=1;j<9;j++){
            board[i][j]='.';
        }
    }

    //the middle of the board gets initialized to proceed play
    board[4][5]='B';
    board[5][4]='B';
    board[5][5]='W';
    board[4][4]='W';

    printboard(); //prints the board to start play
}




