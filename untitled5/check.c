//
// Created by Jai Narayana on 19-05-2021.
//

//header files and libraries
#include <stdio.h>
#include "check.h"
#include "make_moves.h"
#include "set_board.h"
#include "winner.h"

//global variables
char board[9][9];
char player1[20],player2[20];
int player1_score,player2_score;

//possiblemoves definition
void possiblemoves(char a,char b,int x,int y) {
    //local varaibles
    char c = '.';
    int flag = 0;
    int i = x;
    int j = y;


    if (board[x][y] == '.') { //checks if the entered position is empty

        if (board[i - 1][j - 1] == b) { //checks for left top diagonal position
            board[x][y] = a;  //changes the assigned to the white/black according to function called
            int i = x;
            int j = y;
            --i;
            --j;

            //checks if the coin is sandwiches the other colour
            while (i > 0 && j > 0 && board[i][j] == b) {
                --i;
                --j;
                if (board[i][j] == c) {
                    board[x][y] = '.';
                    break;
                }
            }
            flag = 1;
            if (board[i][j] == a) {
                i++;
                j++;
            }
            while (board[i][j] == b) {
                board[i][j] = a;
                if (i == x && j == y) {
                    break;
                }
                i++;
                j++;
            }

        }


        if (board[i - 1][j] == b) { //checks for vertical upward position
            board[x][y] = a; //changes the assigned to the white/black according to function called
            int i = x;
            int j = y;
            --i;

            //checks if the coin is sandwiches the other colour
            while (i > 0 && j > 0 && board[i][j] == b) {
                --i;
                if (board[i][j] == c) {
                    board[x][y] = '.';
                    break;
                }
            }
            flag = 1;
            if (board[i][j] == a) {
                i++;
            }
            while (board[i][j] == b) {

                board[i][j] = a;
                if (i == x && j == y) {
                    break;
                }
                i++;
            }
        }


        if (board[i - 1][j + 1] == b) {  //checks for top right diagonal  position
            board[x][y] = a;  //changes the assigned to the white/black according to function called
            int i = x;
            int j = y;
            --i;
            ++j;
            //checks if the coin is sandwiches the other colour
            while (i > 0 && j > 0 && board[i][j] == b) {
                --i;
                ++j;
                if (board[i][j] == c) {
                    board[x][y] = '.';
                    break;
                }
            }
            flag = 1;
            if (board[i][j] == a) {
                i++;
                j--;
            }
            while (board[i][j] == b) {

                board[i][j] = a;
                if (i == x && j == y) {
                    break;
                }
                i++;
                j--;
            }
        }


        if (board[i][j - 1] == b) {  //checks for mid left horizontal position
            board[x][y] = a;  //changes the assigned to the white/black according to function called
            int i = x;
            int j = y;
            --j;
            //checks if the coin is sandwiches the other colour
            while (i > 0 && j > 0 && i < 9 && j < 9 && board[i][j] == b) {
                --j;
                if (board[i][j] == c) {
                    board[x][y] = '.';
                    break;
                }
            }
            flag = 1;
            if (board[i][j] == a) {
                j++;
            }
            while (board[i][j] == b) {

                board[i][j] = a;
                if (i == x && j == y) {
                    break;
                }
                j++;
            }
        }


        if (board[i][j + 1] == b) { //checks for mid right horizontal postion
            board[x][y] = a; //changes the assigned to the white/black according to function called
            int i = x;
            int j = y;
            ++j;
            //checks if the coin is sandwiches the other colour
            while (i > 0 && j > 0 && i < 9 && j < 9 && board[i][j] == b) {
                ++j;
                if (board[i][j] == c) {
                    board[x][y] = '.';
                    break;
                }
            }
            flag = 1;
            if (board[i][j] == a) {
                j--;
            }
            while (board[i][j] == b) {

                board[i][j] = a;
                if (i == x && j == y) {
                    break;
                }
                j--;
            }
        }


        if (board[i + 1][j - 1] == b) {  // checks for bottom left diagonal position
            board[x][y] = a; //changes the assigned to the white/black according to function called
            int i = x;
            int j = y;
            ++i;
            --j;

            //checks if the coin is sandwiches the other colour
            while (i > 0 && j > 0 && i < 9 && j < 9 && board[i][j] == b) {
                ++i;
                --j;
                if (board[i][j] == c) {
                    board[x][y] = '.';
                    break;

                }
            }
            flag = 1;
            if (board[i][j] == a) {
                i--;
                j++;
            }
            while (board[i][j] == b) {
                board[i][j] = a;
                if (i == x && j == y) {
                    break;
                }
                i--;
                j++;
            }
        }


        if (board[i + 1][j] == b) { // checks for bottom mid vertical position
            board[x][y] = a; //changes the assigned to the white/black according to function called
            int i = x;
            int j = y;
            ++i;

            //checks if the coin is sandwiches the other colour
            while (i > 0 && j > 0 && i < 9 && j < 9 && board[i][j] == b) {
                ++i;
                if (board[i][j] == c) {
                    board[x][y] = '.';
                    break;
                }
            }
            flag = 1;
            if (board[i][j] == a) {
                i--;
            }

            while (board[i][j] == b) {
                board[i][j] = a;
                if (i == x && j == y) {
                    break;
                }
                i--;
            }
        }


        if (board[i + 1][j + 1] == b) { // checks for bottom right diagonal position
            board[x][y] = a; //changes the assigned to the white/black according to function called
            int i = x;
            int j = y;
            ++i;
            ++j;

            //checks if the coin is sandwiches the other colour
            while (i > 0 && j > 0 && i < 9 && j < 9 && board[i][j] == b) {
                ++i;
                ++j;
                if (board[i][j] == c) {
                    board[x][y] = '.';
                    break;
                }

            }
            flag = 1;
            if (board[i][j] == a) {
                j--;
                i--;
            }
            while (board[i][j] == b) {

                board[i][j] = a;
                if (i == x && j == y) {
                    break;
                }
                i--;
                j--;
            }
        }

        if (flag != 1) { //if nothing works checks if its a invalid input or the game has finished
            int empty=0;
            for(int i=1;i<9;i++){
                for(int j=1;j<9;j++)
                    if(board[i][j]=='.')
                    {
                        empty++;
                    }
                if(empty==0)
                {
                    printwinner();
                }
            }
            printf("Invalid Input\n");
            board[x][y]='.';
            if (a == 'B') {
                Bmakemove();
            }
            if (a == 'W') {
                Wmakemove();
            }

        }
        //else change the coin and print the board
        board[x][y] = a;
        printboard();

        //calls the other person based on who is playing
        if(a=='B'){

            Wmakemove();
        }
        if(a=='W'){

            Bmakemove();
        }
    }


}
