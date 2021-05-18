//
// Created by Jai Narayana on 19-05-2021.
//

//header files and libraries
#include <stdio.h>
#include <ctype.h>
#include <time.h>

//global varaibles
char board[9][9];
char player1[20],player2[20];
int player1_score,player2_score;

//printwinner definition
int printwinner(){
    //local variables
    FILE *ptr;
    time_t tm;
    time(&tm);
    ptr=fopen("C:\\Users\\Jai Narayana\\CLionProjects\\untitled5\\othello-results.txt","w"); //file path

    if(ptr == NULL)  //checks if the file pointer is null and prints the error message
    {
        printf("Error!");
        return 0;
    }

    //else prints the final board and winners score / winners name / time and date
    int number=1;
    char x='a';
    for(int i=1;i<9;i++)
    {
        fprintf(ptr,"%i ",number++);
        for(int j=1;j<9;j++){
            fprintf(ptr," %c ",board[i][j]);
        }
        fprintf(ptr,"\n");
    }
    fprintf(ptr,"  ");
    for(int i=1;i<9;i++)
    {
        fprintf(ptr," %c ",x++);
    }

    fprintf(ptr,"\n");
    if(player1_score>player2_score){
        fprintf(ptr,"%s is the winner\n",player1);
        fprintf(ptr,"%s score is %i\n",player1,player1_score);
    }
    else{
        fprintf(ptr,"%s is the winner\n",player2);
        fprintf(ptr,"%s score is %i\n",player2,player2_score);
    }
    fprintf(ptr,"%s", ctime(&tm));
    fclose(ptr);
    return 0;

}
