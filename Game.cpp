#include <bits/stdc++.h>
using namespace std;

class Board {
  int Result;
  char matrix[7][6];
  vector<int> possibleMoves;
  vector<int> moves;
  int height[7];

  Board() {
    Result = 0;
    for (int i = 0; i < 7; i++) {
      for (int j = 0; j < 6; j++) {
        matrix[i][j] = ' ';
      }
      possibleMoves.push_back(i);
      height[i] = 0;
    }
  }

  void add(int input) {
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
    Result = getResult();
  }

  void Print() {
    system("cls");
    for (int i = 0; i < 13; i++) {
      cout << "-";
    }
    cout << endl;
    for (int i = 5; i >= 0; i--) {
      for (int j = 0; j < 7; j++) {
        if (matrix[j][i] == 'X') {
          SetColor(2);  // Green
          cout << matrix[j][i] << " ";
        } else if (matrix[j][i] == 'O') {
          SetColor(4);  // Red
          cout << matrix[j][i] << " ";
        } else {
          cout << matrix[j][i] << " ";
        }
        SetColor(7);  // Default color
      }
      cout << endl;
    }
    for (int i = 0; i < 13; i++) {
      cout << "-";
    }
    cout << endl;
    for (int i = 0; i < 7; i++) {
      cout << i << " ";
    }
    cout << endl << endl;
    if (moves.size() > 0) {
      cout << "Last Move: " << moves[moves.size() - 1] << endl;
    }
    cout << "Possible Moves: ";
    for (int i = 0; i < possibleMoves.size(); i++) {
      cout << possibleMoves[i] << " ";
    }
    cout << endl;
  }

  bool notFinished() {
    if (Result != 0) {
      return false;
    } else if (moves.size() == 42) {
      return false;
    }
    return true;
  }
};