#pragma once

#include <vector>

class Board {
private:
    int Result;
    char matrix[7][6];
    std::vector<int> possibleMoves;
    std::vector<int> moves;
    int height[7];

public:
    Board();
    void add(int input);
    void Print();
    bool notFinished();
    std::vector<int>& getPossibleMoves();
    std::vector<int>& getMoves();
    int getResult();
};
