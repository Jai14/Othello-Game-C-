//
// Created by Jai Narayana on 18-05-2021.
//

//header files and libraries
#include <stdio.h>
#include <string.h>
#include "check.h"
#include "make_moves.h"


//Bmakemove definition
void Bmakemove(){
    //local variable
    int xaxis;
    int yaxis;
    char a,b;
    char alphabet[3];

    label1:
    printf("\nBLACK is playing\n");
    printf("Enter the move you want to make (alphabet with range a-h followed by number with range 1-8) :");
    scanf("%s",alphabet); //gets the move from user

    if(strlen(alphabet)!=2){  //checks if length of got from user is 2
        goto label1;
    }
    a = alphabet[0];
    b = alphabet[1];
    xaxis = b-'0';
    yaxis= a-'a'+1;
    xaxis= (int) xaxis;
    yaxis= (int) yaxis;
    if(xaxis<=8 && yaxis<=8 && xaxis>0 && yaxis>0) //checks if the move is within range
    {
        possiblemoves('B','W',xaxis,yaxis); //checks if the move is possible and if possible the coins are switched
        Wmakemove();
    }
    else {  //else the error is displayed
        printf("ERROR (Enter within range).\n");
        goto label1; //the program goes to label
    }

}


//Wmakemove definition
void Wmakemove(){
    //local variables
    int xaxis;
    int yaxis;
    char alphabet[3];
    char a,b ;

    label2:
    printf("\nWhite is playing\n");
    printf("Enter the move you want to make (alphabet with range a-h followed by number with range 1-8) :");
    scanf("%s",alphabet); //gets the move from user

    if(strlen(alphabet)!=2){ //checks if length of got from user is 2
        goto label2;
    }
    a = alphabet[0];
    b = alphabet[1];
    xaxis = b-'0';
    yaxis= a-'a'+1;
    xaxis= (int) xaxis;
    yaxis= (int) yaxis;
    if(xaxis<=8 && yaxis<=8 && xaxis>0 && yaxis>0) //checks if the move is within range
    {
        possiblemoves('W','B',xaxis,yaxis); //checks if the move is possible and if possible the coins are switched
        Bmakemove();
    }

    else{ //else the error is displayed
        printf("ERROR (Enter within range).\n");
        goto label2; //the program goes to label
    }

}
