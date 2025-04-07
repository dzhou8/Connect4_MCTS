#include "Board.h"
#include "getWinner.h"

#include <iostream>
#include <algorithm>

#include <windows.h>
void SetColor(int value) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

Board::Board() {
  Result = 0;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 6; j++) {
      matrix[i][j] = ' ';
    }
    possibleMoves.push_back(i);
    height[i] = 0;
  }
}

void Board::add(int input) {
  if (moves.size() % 2 == 0) {
    matrix[input][height[input]] = 'X';
  } else {
    matrix[input][height[input]] = 'O';
  }
  moves.push_back(input);
  height[input]++;
  if (height[input] > 5) {
    possibleMoves.erase(
        remove(possibleMoves.begin(), possibleMoves.end(), input),
        possibleMoves.end());
  }
  Result = getWinner(matrix);
}

void Board::Print() {
  system("cls");
  for (int i = 0; i < 13; i++) {
    std::cout << "-";
  }
  std::cout << std::endl;
  for (int i = 5; i >= 0; i--) {
    for (int j = 0; j < 7; j++) {
      if (matrix[j][i] == 'X') {
        SetColor(2);  // Green
        std::cout << matrix[j][i] << " ";
      } else if (matrix[j][i] == 'O') {
        SetColor(4);  // Red
        std::cout << matrix[j][i] << " ";
      } else {
        std::cout << matrix[j][i] << " ";
      }
      SetColor(7);  // Default color
    }
    std::cout << std::endl;
  }
  for (int i = 0; i < 13; i++) {
    std::cout << "-";
  }
  std::cout << std::endl;
  for (int i = 0; i < 7; i++) {
    std::cout << i << " ";
  }
  std::cout << std::endl << std::endl;
  if (moves.size() > 0) {
    std::cout << "Last Move: " << moves[moves.size() - 1] << std::endl;
  }
  std::cout << "Possible Moves: ";
  for (int i = 0; i < possibleMoves.size(); i++) {
    std::cout << possibleMoves[i] << " ";
  }
  std::cout << std::endl;
}

bool Board::notFinished() {
  if (Result != 0) {
    return false;
  } else if (moves.size() == 42) {
    return false;
  }
  return true;
}

std::vector<int>& Board::getPossibleMoves() { return possibleMoves; }

std::vector<int>& Board::getMoves() { return moves; }

int Board::getResult() { return Result; }