/*
ID: dzhouwave
PROG: Connect4MCTS
LANG: C++11
*/

// @BEGIN_OF_SOURCE_CODE

#include <conio.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <iomanip>

#define INT_MAX 2147483647
#define INT_MIN -2147483647
#define pi acos(-1.0)
//#define N 1000000
#define LL unsigned long long

#define maxTrials 5000000
#define exploration_constant 2
using namespace std;

//#define cin fin
//ifstream fin ("name.in");
//#define cout fout
//ofstream fout ("name.out");

struct Board
{
    int Result;
    char matrix[7][6];
    vector<int> possibleMoves;
    vector<int> moves;
    int height[7];

    Board()
    {
        Result = 0;
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                matrix[i][j] = ' ';
            }
            possibleMoves.push_back(i);
            height[i] = 0;
        }
    }

    void add(int input)
    {
        if(moves.size() % 2 == 0)
        {
            matrix[input][height[input]] = 'X';
        }
        else
        {
            matrix[input][height[input]] = 'O';
        }
        moves.push_back(input);
        height[input]++;
        if(height[input] > 5)
        {
            possibleMoves.erase(remove(possibleMoves.begin(), possibleMoves.end(), input), possibleMoves.end());
        }
        Result = getResult();
    }

    int getResult()
    {
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

    void Print()
    {
        system("cls");
        for(int i = 0; i < 13; i++)
        {
            cout << "-";
        }
        cout << endl;
        for(int i = 5; i >= 0; i--)
        {
            for(int j = 0; j < 7; j++)
            {
                cout << matrix[j][i] << " ";
            }
            cout << endl;
        }
        for(int i = 0; i < 13; i++)
        {
            cout << "-";
        }
        cout << endl;
        for(int i = 0; i < 7; i++)
        {
            cout << i << " ";
        }
        cout << endl << endl;
        if(moves.size() > 0)
        {
            cout << "Last Move: " << moves[moves.size()-1] << endl;
        }
        cout << "Possible Moves: ";
        for(int i = 0; i < possibleMoves.size(); i++)
        {
            cout << possibleMoves[i] << " ";
        }
        cout << endl;
    }

    bool notFinished()
    {
        if(Result != 0)
        {
            return false;
        }
        else if(moves.size() == 42)
        {
            return false;
        }
        return true;
    }
};

struct Node
{
    Node * parent;
    vector<Node*> Children;
    double successes;
    int total;
    int moveHere;
    bool madeChildren;
    int player; //1 is first, -1 is second

    void init(int playerInput) //ROOT NODE
    {
        parent = nullptr;
        successes = 0.0;
        total = 0;
        madeChildren = false;
        player = playerInput;
    }

    void init(Node * parentNode, int moveInput)
    {
        parent = parentNode;
        successes = 0.0;
        total = 0;
        moveHere = moveInput;
        madeChildren = false;
        player = -1*parentNode->player;
    }

    void free_space()
    {
        if(madeChildren)
        {
            for(int i = 0; i < Children.size(); i++)
            {
                Children[i]->free_space();
            }
        }
        delete this;
    }

    void makeChildren(Board input)
    {
        madeChildren = true;
//        cout << "THIS: " << this << endl;
        for(int i = 0; i < input.possibleMoves.size(); i++)
        {
            Node* tmpNode = new Node();
            tmpNode->init(this, input.possibleMoves[i]);
            Children.push_back(tmpNode);
//            cout << "PARENT OF CHILD: " << Children[i]->parent << endl;
//            cout << "CHILD: " << &Children[i] << endl;
        }
    }

    double getUTC(int prevTotal, double constant)
    {
        if(total == 0)
        {
            return 100;
        }
        double underSquare = constant*(log(prevTotal))/total;
        double result = (double) (successes/total) + sqrt(underSquare);
        return result;
    }

    Node* Select(double constant)
    {
        double bestUTC = -1;
        int bestIndex = -1;
        for(int i = 0; i < Children.size(); i++)
        {
//            cout << "CHILD " << i << " UTC: " << Children[i]->getUTC(total) << endl;
            if(Children[i]->getUTC(total, constant) > bestUTC)
            {
                bestUTC = Children[i]->getUTC(total, constant);
                bestIndex = i;
            }
        }
//        cout << "BEST CHILD: " << &Children[bestIndex] << endl;
        return Children[bestIndex];
    }

    void Win()
    {
        successes+=1.0;
        total++;
        if(parent != nullptr)
        {
            parent->Lose();
        }
    }

    void Draw()
    {
        successes += 0.5;
        total++;
        if(parent != nullptr)
        {
            parent->Draw();
        }
    }

    void Lose()
    {
        total++;
        if(parent != nullptr)
        {
            parent->Win();
        }
    }

    Node* getRoot()
    {
        if(parent == nullptr)
        {
            return this;
        }
        return parent->getRoot();
    }

    int getMove()
    {
        int maxTotal = -1;
        int bestMove = -1;
        for(int i = 0; i < Children.size(); i++)
        {
//            cout << "Children " << i << " Total:" << Children[i]->total << endl;
            if(Children[i]->total > maxTotal)
            {
                maxTotal = Children[i]->total;
                bestMove = Children[i]->moveHere;
            }
        }

        return bestMove;
    }
};

int MonteCarlo(Board input)
{
    while(input.possibleMoves.size() > 0 && input.Result == 0)
    {
        int randomIndex = rand() % input.possibleMoves.size();
        input.add(input.possibleMoves[randomIndex]);
    }
    return input.Result;
}

struct AI
{
    Node * Current;
    Board Real;
    Board Simulated;

    AI(Board input, int inputPlayer) //blank board
    {
        Real = input;
        Simulated = input;
        Current = new Node();
        Current->init(inputPlayer);
    }

    void runSimulations()
    {
        Simulated = Real;
//        cout << "CURRENT TOTAL: " << Current->total << endl;
        while(Current->madeChildren == true && Simulated.notFinished())
        {
//            cout << "THIS: " << this << endl;
            Current = Current->Select(exploration_constant);
//            cout << "Selected Child: " << Current << endl;
            Simulated.add(Current->moveHere);
        }
        if(Simulated.notFinished())
        {
//            cout << "MAKING CHILDREN" << endl;
            Current->makeChildren(Simulated);
        }
//        cout << "MADECHILDREN: " << Current->madeChildren << endl;
        int result = Simulated.Result;
        if(result == 0)
        {
            result = MonteCarlo(Simulated);
        }
        if(result == -1*Current->player)
        {
            Current->Win();
        }
        else if(result == 0)
        {
            Current->Draw();
        }
        else if(result == Current->player)
        {
            Current->Lose();
        }
        Current = Current->getRoot();
    }

    void addMove(int moveInput)
    {
        Real.add(moveInput);
        Node* tmpPointer;
        for(int i = 0; i < Current->Children.size(); i++)
        {
            if(Current->Children[i]->moveHere == moveInput)
            {
                tmpPointer = Current->Children[i];
                tmpPointer->parent = nullptr;
            }
            else
            {
                Current->Children[i]->free_space();
            }
        }
        Current = tmpPointer;
        return;
        cout << "CANNOT ADD MOVE" << endl;
    }

    int getMove()
    {
        Current = Current->getRoot();
        int moveInput = Current->getMove();
        addMove(moveInput);
        return moveInput;
    }
};

int main()
{
    srand(time(NULL));
    Board Game;
    cout << "Enter which player you would like to be (1 for first, -1 for second)" << endl;
    int inputPlayer;
    cin >> inputPlayer;
    AI GameAI(Game, 1);

    double timer = 0;
    int totalRun = 0;
    while(Game.Result == 0)
    {
        if(Game.moves.size() % 2 == (inputPlayer == 1)) //COMPUTERS TURN
        {
            Game.Print();
            cout << "Heuristic: " << 1 - GameAI.Current->successes/GameAI.Current->total << endl;
            cout << "Making Calculations..." << endl;
            double start = time(0);
            while(time(0)-start <= 10)
            {
                GameAI.runSimulations();
            }
            totalRun = GameAI.Current->total;
//            cout << "TOTAL: " << GameAI.Current->total << endl;
            for(int i = 0; i < GameAI.Current->Children.size(); i++)
            {
//                cout << "TOTAL FOR CHILD " << i << ": " << GameAI.Current->Children[i]->total << endl;
//                cout << GameAI.Current->Children[i]->successes/GameAI.Current->Children[i]->total << endl;//" " << GameAI.Current->Children[i]->total << " " << GameAI.Current->Children[i]->getUTC(GameAI.Current->total) << endl;
            }
            Game.add(GameAI.getMove());
        }
        else //PLAYERS TURN
        {
//            _getch();
            Game.Print();
            cout << "Leaves: " << totalRun << endl;
            cout << "Heuristic: " << GameAI.Current->successes/GameAI.Current->total << endl;
            int input;
            cout << "Enter your move: " << endl;
            while(true)
            {
                if(kbhit())
                {
                    cin >> input;
                    break;
                }
                if(GameAI.Current->total < maxTrials)
                {
                    GameAI.runSimulations();
                }
                if(GameAI.Current->total == maxTrials-1)
                {
                    cout << "Pondering Completed." << endl;
                }
            }
            Game.add(input);
            GameAI.addMove(input);
        }
    }
    Game.Print();
    cout << "Result: " << Game.Result << endl;
    _getch();
    return 0;
}

// @END_OF_SOURCE_CODE
