#include "getWinner.h"

// this code looks really dumb but for some reason it's measurably computationally faster
int getWinner(char matrix[7][6]) {
        if (matrix[0][0] == 'X' and  matrix[1][0] == 'X' and  matrix[2][0] == 'X' and  matrix[3][0] == 'X'){return 1;}
        if (matrix[0][0] == 'O' and  matrix[1][0] == 'O' and  matrix[2][0] == 'O' and  matrix[3][0] == 'O'){return -1;}
        if (matrix[1][0] == 'X' and  matrix[2][0] == 'X' and  matrix[3][0] == 'X' and  matrix[4][0] == 'X'){return 1;}
        if (matrix[1][0] == 'O' and  matrix[2][0] == 'O' and  matrix[3][0] == 'O' and  matrix[4][0] == 'O'){return -1;}
        if (matrix[2][0] == 'X' and  matrix[3][0] == 'X' and  matrix[4][0] == 'X' and  matrix[5][0] == 'X'){return 1;}
        if (matrix[2][0] == 'O' and  matrix[3][0] == 'O' and  matrix[4][0] == 'O' and  matrix[5][0] == 'O'){return -1;}
        if (matrix[3][0] == 'X' and  matrix[4][0] == 'X' and  matrix[5][0] == 'X' and  matrix[6][0] == 'X'){return 1;}
        if (matrix[3][0] == 'O' and  matrix[4][0] == 'O' and  matrix[5][0] == 'O' and  matrix[6][0] == 'O'){return -1;}
        if (matrix[0][1] == 'X' and  matrix[1][1] == 'X' and  matrix[2][1] == 'X' and  matrix[3][1] == 'X'){return 1;}
        if (matrix[0][1] == 'O' and  matrix[1][1] == 'O' and  matrix[2][1] == 'O' and  matrix[3][1] == 'O'){return -1;}
        if (matrix[1][1] == 'X' and  matrix[2][1] == 'X' and  matrix[3][1] == 'X' and  matrix[4][1] == 'X'){return 1;}
        if (matrix[1][1] == 'O' and  matrix[2][1] == 'O' and  matrix[3][1] == 'O' and  matrix[4][1] == 'O'){return -1;}
        if (matrix[2][1] == 'X' and  matrix[3][1] == 'X' and  matrix[4][1] == 'X' and  matrix[5][1] == 'X'){return 1;}
        if (matrix[2][1] == 'O' and  matrix[3][1] == 'O' and  matrix[4][1] == 'O' and  matrix[5][1] == 'O'){return -1;}
        if (matrix[3][1] == 'X' and  matrix[4][1] == 'X' and  matrix[5][1] == 'X' and  matrix[6][1] == 'X'){return 1;}
        if (matrix[3][1] == 'O' and  matrix[4][1] == 'O' and  matrix[5][1] == 'O' and  matrix[6][1] == 'O'){return -1;}
        if (matrix[0][2] == 'X' and  matrix[1][2] == 'X' and  matrix[2][2] == 'X' and  matrix[3][2] == 'X'){return 1;}
        if (matrix[0][2] == 'O' and  matrix[1][2] == 'O' and  matrix[2][2] == 'O' and  matrix[3][2] == 'O'){return -1;}
        if (matrix[1][2] == 'X' and  matrix[2][2] == 'X' and  matrix[3][2] == 'X' and  matrix[4][2] == 'X'){return 1;}
        if (matrix[1][2] == 'O' and  matrix[2][2] == 'O' and  matrix[3][2] == 'O' and  matrix[4][2] == 'O'){return -1;}
        if (matrix[2][2] == 'X' and  matrix[3][2] == 'X' and  matrix[4][2] == 'X' and  matrix[5][2] == 'X'){return 1;}
        if (matrix[2][2] == 'O' and  matrix[3][2] == 'O' and  matrix[4][2] == 'O' and  matrix[5][2] == 'O'){return -1;}
        if (matrix[3][2] == 'X' and  matrix[4][2] == 'X' and  matrix[5][2] == 'X' and  matrix[6][2] == 'X'){return 1;}
        if (matrix[3][2] == 'O' and  matrix[4][2] == 'O' and  matrix[5][2] == 'O' and  matrix[6][2] == 'O'){return -1;}
        if (matrix[0][3] == 'X' and  matrix[1][3] == 'X' and  matrix[2][3] == 'X' and  matrix[3][3] == 'X'){return 1;}
        if (matrix[0][3] == 'O' and  matrix[1][3] == 'O' and  matrix[2][3] == 'O' and  matrix[3][3] == 'O'){return -1;}
        if (matrix[1][3] == 'X' and  matrix[2][3] == 'X' and  matrix[3][3] == 'X' and  matrix[4][3] == 'X'){return 1;}
        if (matrix[1][3] == 'O' and  matrix[2][3] == 'O' and  matrix[3][3] == 'O' and  matrix[4][3] == 'O'){return -1;}
        if (matrix[2][3] == 'X' and  matrix[3][3] == 'X' and  matrix[4][3] == 'X' and  matrix[5][3] == 'X'){return 1;}
        if (matrix[2][3] == 'O' and  matrix[3][3] == 'O' and  matrix[4][3] == 'O' and  matrix[5][3] == 'O'){return -1;}
        if (matrix[3][3] == 'X' and  matrix[4][3] == 'X' and  matrix[5][3] == 'X' and  matrix[6][3] == 'X'){return 1;}
        if (matrix[3][3] == 'O' and  matrix[4][3] == 'O' and  matrix[5][3] == 'O' and  matrix[6][3] == 'O'){return -1;}
        if (matrix[0][4] == 'X' and  matrix[1][4] == 'X' and  matrix[2][4] == 'X' and  matrix[3][4] == 'X'){return 1;}
        if (matrix[0][4] == 'O' and  matrix[1][4] == 'O' and  matrix[2][4] == 'O' and  matrix[3][4] == 'O'){return -1;}
        if (matrix[1][4] == 'X' and  matrix[2][4] == 'X' and  matrix[3][4] == 'X' and  matrix[4][4] == 'X'){return 1;}
        if (matrix[1][4] == 'O' and  matrix[2][4] == 'O' and  matrix[3][4] == 'O' and  matrix[4][4] == 'O'){return -1;}
        if (matrix[2][4] == 'X' and  matrix[3][4] == 'X' and  matrix[4][4] == 'X' and  matrix[5][4] == 'X'){return 1;}
        if (matrix[2][4] == 'O' and  matrix[3][4] == 'O' and  matrix[4][4] == 'O' and  matrix[5][4] == 'O'){return -1;}
        if (matrix[3][4] == 'X' and  matrix[4][4] == 'X' and  matrix[5][4] == 'X' and  matrix[6][4] == 'X'){return 1;}
        if (matrix[3][4] == 'O' and  matrix[4][4] == 'O' and  matrix[5][4] == 'O' and  matrix[6][4] == 'O'){return -1;}
        if (matrix[0][5] == 'X' and  matrix[1][5] == 'X' and  matrix[2][5] == 'X' and  matrix[3][5] == 'X'){return 1;}
        if (matrix[0][5] == 'O' and  matrix[1][5] == 'O' and  matrix[2][5] == 'O' and  matrix[3][5] == 'O'){return -1;}
        if (matrix[1][5] == 'X' and  matrix[2][5] == 'X' and  matrix[3][5] == 'X' and  matrix[4][5] == 'X'){return 1;}
        if (matrix[1][5] == 'O' and  matrix[2][5] == 'O' and  matrix[3][5] == 'O' and  matrix[4][5] == 'O'){return -1;}
        if (matrix[2][5] == 'X' and  matrix[3][5] == 'X' and  matrix[4][5] == 'X' and  matrix[5][5] == 'X'){return 1;}
        if (matrix[2][5] == 'O' and  matrix[3][5] == 'O' and  matrix[4][5] == 'O' and  matrix[5][5] == 'O'){return -1;}
        if (matrix[3][5] == 'X' and  matrix[4][5] == 'X' and  matrix[5][5] == 'X' and  matrix[6][5] == 'X'){return 1;}
        if (matrix[3][5] == 'O' and  matrix[4][5] == 'O' and  matrix[5][5] == 'O' and  matrix[6][5] == 'O'){return -1;}
        if (matrix[0][0] == 'X' and  matrix[0][1] == 'X' and  matrix[0][2] == 'X' and  matrix[0][3] == 'X'){return 1;}
        if (matrix[0][0] == 'O' and  matrix[0][1] == 'O' and  matrix[0][2] == 'O' and  matrix[0][3] == 'O'){return -1;}
        if (matrix[0][1] == 'X' and  matrix[0][2] == 'X' and  matrix[0][3] == 'X' and  matrix[0][4] == 'X'){return 1;}
        if (matrix[0][1] == 'O' and  matrix[0][2] == 'O' and  matrix[0][3] == 'O' and  matrix[0][4] == 'O'){return -1;}
        if (matrix[0][2] == 'X' and  matrix[0][3] == 'X' and  matrix[0][4] == 'X' and  matrix[0][5] == 'X'){return 1;}
        if (matrix[0][2] == 'O' and  matrix[0][3] == 'O' and  matrix[0][4] == 'O' and  matrix[0][5] == 'O'){return -1;}
        if (matrix[1][0] == 'X' and  matrix[1][1] == 'X' and  matrix[1][2] == 'X' and  matrix[1][3] == 'X'){return 1;}
        if (matrix[1][0] == 'O' and  matrix[1][1] == 'O' and  matrix[1][2] == 'O' and  matrix[1][3] == 'O'){return -1;}
        if (matrix[1][1] == 'X' and  matrix[1][2] == 'X' and  matrix[1][3] == 'X' and  matrix[1][4] == 'X'){return 1;}
        if (matrix[1][1] == 'O' and  matrix[1][2] == 'O' and  matrix[1][3] == 'O' and  matrix[1][4] == 'O'){return -1;}
        if (matrix[1][2] == 'X' and  matrix[1][3] == 'X' and  matrix[1][4] == 'X' and  matrix[1][5] == 'X'){return 1;}
        if (matrix[1][2] == 'O' and  matrix[1][3] == 'O' and  matrix[1][4] == 'O' and  matrix[1][5] == 'O'){return -1;}
        if (matrix[2][0] == 'X' and  matrix[2][1] == 'X' and  matrix[2][2] == 'X' and  matrix[2][3] == 'X'){return 1;}
        if (matrix[2][0] == 'O' and  matrix[2][1] == 'O' and  matrix[2][2] == 'O' and  matrix[2][3] == 'O'){return -1;}
        if (matrix[2][1] == 'X' and  matrix[2][2] == 'X' and  matrix[2][3] == 'X' and  matrix[2][4] == 'X'){return 1;}
        if (matrix[2][1] == 'O' and  matrix[2][2] == 'O' and  matrix[2][3] == 'O' and  matrix[2][4] == 'O'){return -1;}
        if (matrix[2][2] == 'X' and  matrix[2][3] == 'X' and  matrix[2][4] == 'X' and  matrix[2][5] == 'X'){return 1;}
        if (matrix[2][2] == 'O' and  matrix[2][3] == 'O' and  matrix[2][4] == 'O' and  matrix[2][5] == 'O'){return -1;}
        if (matrix[3][0] == 'X' and  matrix[3][1] == 'X' and  matrix[3][2] == 'X' and  matrix[3][3] == 'X'){return 1;}
        if (matrix[3][0] == 'O' and  matrix[3][1] == 'O' and  matrix[3][2] == 'O' and  matrix[3][3] == 'O'){return -1;}
        if (matrix[3][1] == 'X' and  matrix[3][2] == 'X' and  matrix[3][3] == 'X' and  matrix[3][4] == 'X'){return 1;}
        if (matrix[3][1] == 'O' and  matrix[3][2] == 'O' and  matrix[3][3] == 'O' and  matrix[3][4] == 'O'){return -1;}
        if (matrix[3][2] == 'X' and  matrix[3][3] == 'X' and  matrix[3][4] == 'X' and  matrix[3][5] == 'X'){return 1;}
        if (matrix[3][2] == 'O' and  matrix[3][3] == 'O' and  matrix[3][4] == 'O' and  matrix[3][5] == 'O'){return -1;}
        if (matrix[4][0] == 'X' and  matrix[4][1] == 'X' and  matrix[4][2] == 'X' and  matrix[4][3] == 'X'){return 1;}
        if (matrix[4][0] == 'O' and  matrix[4][1] == 'O' and  matrix[4][2] == 'O' and  matrix[4][3] == 'O'){return -1;}
        if (matrix[4][1] == 'X' and  matrix[4][2] == 'X' and  matrix[4][3] == 'X' and  matrix[4][4] == 'X'){return 1;}
        if (matrix[4][1] == 'O' and  matrix[4][2] == 'O' and  matrix[4][3] == 'O' and  matrix[4][4] == 'O'){return -1;}
        if (matrix[4][2] == 'X' and  matrix[4][3] == 'X' and  matrix[4][4] == 'X' and  matrix[4][5] == 'X'){return 1;}
        if (matrix[4][2] == 'O' and  matrix[4][3] == 'O' and  matrix[4][4] == 'O' and  matrix[4][5] == 'O'){return -1;}
        if (matrix[5][0] == 'X' and  matrix[5][1] == 'X' and  matrix[5][2] == 'X' and  matrix[5][3] == 'X'){return 1;}
        if (matrix[5][0] == 'O' and  matrix[5][1] == 'O' and  matrix[5][2] == 'O' and  matrix[5][3] == 'O'){return -1;}
        if (matrix[5][1] == 'X' and  matrix[5][2] == 'X' and  matrix[5][3] == 'X' and  matrix[5][4] == 'X'){return 1;}
        if (matrix[5][1] == 'O' and  matrix[5][2] == 'O' and  matrix[5][3] == 'O' and  matrix[5][4] == 'O'){return -1;}
        if (matrix[5][2] == 'X' and  matrix[5][3] == 'X' and  matrix[5][4] == 'X' and  matrix[5][5] == 'X'){return 1;}
        if (matrix[5][2] == 'O' and  matrix[5][3] == 'O' and  matrix[5][4] == 'O' and  matrix[5][5] == 'O'){return -1;}
        if (matrix[6][0] == 'X' and  matrix[6][1] == 'X' and  matrix[6][2] == 'X' and  matrix[6][3] == 'X'){return 1;}
        if (matrix[6][0] == 'O' and  matrix[6][1] == 'O' and  matrix[6][2] == 'O' and  matrix[6][3] == 'O'){return -1;}
        if (matrix[6][1] == 'X' and  matrix[6][2] == 'X' and  matrix[6][3] == 'X' and  matrix[6][4] == 'X'){return 1;}
        if (matrix[6][1] == 'O' and  matrix[6][2] == 'O' and  matrix[6][3] == 'O' and  matrix[6][4] == 'O'){return -1;}
        if (matrix[6][2] == 'X' and  matrix[6][3] == 'X' and  matrix[6][4] == 'X' and  matrix[6][5] == 'X'){return 1;}
        if (matrix[6][2] == 'O' and  matrix[6][3] == 'O' and  matrix[6][4] == 'O' and  matrix[6][5] == 'O'){return -1;}
        if (matrix[0][3] == 'X' and  matrix[1][2] == 'X' and  matrix[2][1] == 'X' and  matrix[3][0] == 'X'){return 1;}
        if (matrix[0][3] == 'O' and  matrix[1][2] == 'O' and  matrix[2][1] == 'O' and  matrix[3][0] == 'O'){return -1;}
        if (matrix[3][3] == 'X' and  matrix[2][2] == 'X' and  matrix[1][1] == 'X' and  matrix[0][0] == 'X'){return 1;}
        if (matrix[3][3] == 'O' and  matrix[2][2] == 'O' and  matrix[1][1] == 'O' and  matrix[0][0] == 'O'){return -1;}
        if (matrix[0][4] == 'X' and  matrix[1][3] == 'X' and  matrix[2][2] == 'X' and  matrix[3][1] == 'X'){return 1;}
        if (matrix[0][4] == 'O' and  matrix[1][3] == 'O' and  matrix[2][2] == 'O' and  matrix[3][1] == 'O'){return -1;}
        if (matrix[3][4] == 'X' and  matrix[2][3] == 'X' and  matrix[1][2] == 'X' and  matrix[0][1] == 'X'){return 1;}
        if (matrix[3][4] == 'O' and  matrix[2][3] == 'O' and  matrix[1][2] == 'O' and  matrix[0][1] == 'O'){return -1;}
        if (matrix[0][5] == 'X' and  matrix[1][4] == 'X' and  matrix[2][3] == 'X' and  matrix[3][2] == 'X'){return 1;}
        if (matrix[0][5] == 'O' and  matrix[1][4] == 'O' and  matrix[2][3] == 'O' and  matrix[3][2] == 'O'){return -1;}
        if (matrix[3][5] == 'X' and  matrix[2][4] == 'X' and  matrix[1][3] == 'X' and  matrix[0][2] == 'X'){return 1;}
        if (matrix[3][5] == 'O' and  matrix[2][4] == 'O' and  matrix[1][3] == 'O' and  matrix[0][2] == 'O'){return -1;}
        if (matrix[1][3] == 'X' and  matrix[2][2] == 'X' and  matrix[3][1] == 'X' and  matrix[4][0] == 'X'){return 1;}
        if (matrix[1][3] == 'O' and  matrix[2][2] == 'O' and  matrix[3][1] == 'O' and  matrix[4][0] == 'O'){return -1;}
        if (matrix[4][3] == 'X' and  matrix[3][2] == 'X' and  matrix[2][1] == 'X' and  matrix[1][0] == 'X'){return 1;}
        if (matrix[4][3] == 'O' and  matrix[3][2] == 'O' and  matrix[2][1] == 'O' and  matrix[1][0] == 'O'){return -1;}
        if (matrix[1][4] == 'X' and  matrix[2][3] == 'X' and  matrix[3][2] == 'X' and  matrix[4][1] == 'X'){return 1;}
        if (matrix[1][4] == 'O' and  matrix[2][3] == 'O' and  matrix[3][2] == 'O' and  matrix[4][1] == 'O'){return -1;}
        if (matrix[4][4] == 'X' and  matrix[3][3] == 'X' and  matrix[2][2] == 'X' and  matrix[1][1] == 'X'){return 1;}
        if (matrix[4][4] == 'O' and  matrix[3][3] == 'O' and  matrix[2][2] == 'O' and  matrix[1][1] == 'O'){return -1;}
        if (matrix[1][5] == 'X' and  matrix[2][4] == 'X' and  matrix[3][3] == 'X' and  matrix[4][2] == 'X'){return 1;}
        if (matrix[1][5] == 'O' and  matrix[2][4] == 'O' and  matrix[3][3] == 'O' and  matrix[4][2] == 'O'){return -1;}
        if (matrix[4][5] == 'X' and  matrix[3][4] == 'X' and  matrix[2][3] == 'X' and  matrix[1][2] == 'X'){return 1;}
        if (matrix[4][5] == 'O' and  matrix[3][4] == 'O' and  matrix[2][3] == 'O' and  matrix[1][2] == 'O'){return -1;}
        if (matrix[2][3] == 'X' and  matrix[3][2] == 'X' and  matrix[4][1] == 'X' and  matrix[5][0] == 'X'){return 1;}
        if (matrix[2][3] == 'O' and  matrix[3][2] == 'O' and  matrix[4][1] == 'O' and  matrix[5][0] == 'O'){return -1;}
        if (matrix[5][3] == 'X' and  matrix[4][2] == 'X' and  matrix[3][1] == 'X' and  matrix[2][0] == 'X'){return 1;}
        if (matrix[5][3] == 'O' and  matrix[4][2] == 'O' and  matrix[3][1] == 'O' and  matrix[2][0] == 'O'){return -1;}
        if (matrix[2][4] == 'X' and  matrix[3][3] == 'X' and  matrix[4][2] == 'X' and  matrix[5][1] == 'X'){return 1;}
        if (matrix[2][4] == 'O' and  matrix[3][3] == 'O' and  matrix[4][2] == 'O' and  matrix[5][1] == 'O'){return -1;}
        if (matrix[5][4] == 'X' and  matrix[4][3] == 'X' and  matrix[3][2] == 'X' and  matrix[2][1] == 'X'){return 1;}
        if (matrix[5][4] == 'O' and  matrix[4][3] == 'O' and  matrix[3][2] == 'O' and  matrix[2][1] == 'O'){return -1;}
        if (matrix[2][5] == 'X' and  matrix[3][4] == 'X' and  matrix[4][3] == 'X' and  matrix[5][2] == 'X'){return 1;}
        if (matrix[2][5] == 'O' and  matrix[3][4] == 'O' and  matrix[4][3] == 'O' and  matrix[5][2] == 'O'){return -1;}
        if (matrix[5][5] == 'X' and  matrix[4][4] == 'X' and  matrix[3][3] == 'X' and  matrix[2][2] == 'X'){return 1;}
        if (matrix[5][5] == 'O' and  matrix[4][4] == 'O' and  matrix[3][3] == 'O' and  matrix[2][2] == 'O'){return -1;}
        if (matrix[3][3] == 'X' and  matrix[4][2] == 'X' and  matrix[5][1] == 'X' and  matrix[6][0] == 'X'){return 1;}
        if (matrix[3][3] == 'O' and  matrix[4][2] == 'O' and  matrix[5][1] == 'O' and  matrix[6][0] == 'O'){return -1;}
        if (matrix[6][3] == 'X' and  matrix[5][2] == 'X' and  matrix[4][1] == 'X' and  matrix[3][0] == 'X'){return 1;}
        if (matrix[6][3] == 'O' and  matrix[5][2] == 'O' and  matrix[4][1] == 'O' and  matrix[3][0] == 'O'){return -1;}
        if (matrix[3][4] == 'X' and  matrix[4][3] == 'X' and  matrix[5][2] == 'X' and  matrix[6][1] == 'X'){return 1;}
        if (matrix[3][4] == 'O' and  matrix[4][3] == 'O' and  matrix[5][2] == 'O' and  matrix[6][1] == 'O'){return -1;}
        if (matrix[6][4] == 'X' and  matrix[5][3] == 'X' and  matrix[4][2] == 'X' and  matrix[3][1] == 'X'){return 1;}
        if (matrix[6][4] == 'O' and  matrix[5][3] == 'O' and  matrix[4][2] == 'O' and  matrix[3][1] == 'O'){return -1;}
        if (matrix[3][5] == 'X' and  matrix[4][4] == 'X' and  matrix[5][3] == 'X' and  matrix[6][2] == 'X'){return 1;}
        if (matrix[3][5] == 'O' and  matrix[4][4] == 'O' and  matrix[5][3] == 'O' and  matrix[6][2] == 'O'){return -1;}
        if (matrix[6][5] == 'X' and  matrix[5][4] == 'X' and  matrix[4][3] == 'X' and  matrix[3][2] == 'X'){return 1;}
        if (matrix[6][5] == 'O' and  matrix[5][4] == 'O' and  matrix[4][3] == 'O' and  matrix[3][2] == 'O'){return -1;}
        return 0;
    }