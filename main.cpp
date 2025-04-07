/*
PROG: Connect4_CPP
LANG: C++11
*/

// @BEGIN_OF_SOURCE_CODE

#include <conio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include "Board.h"

#define LL unsigned long long

#define maxTrials 5000000
#define exploration_constant 2

struct Node {
  Node* parent;
  std::vector<Node*> Children;
  double successes;
  int total;
  int moveHere;
  bool madeChildren;
  int player;  // 1 is first, -1 is second

  void init(int playerInput)  // ROOT NODE
  {
    parent = nullptr;
    successes = 0.0;
    total = 0;
    madeChildren = false;
    player = playerInput;
  }

  void init(Node* parentNode, int moveInput) {
    parent = parentNode;
    successes = 0.0;
    total = 0;
    moveHere = moveInput;
    madeChildren = false;
    player = -1 * parentNode->player;
  }

  void free_space() {
    if (madeChildren) {
      for (int i = 0; i < Children.size(); i++) {
        Children[i]->free_space();
      }
    }
    delete this;
  }

  void makeChildren(Board input) {
    madeChildren = true;
    //        cout << "THIS: " << this << endl;
    for (int i = 0; i < input.getPossibleMoves().size(); i++) {
      Node* tmpNode = new Node();
      tmpNode->init(this, input.getPossibleMoves()[i]);
      Children.push_back(tmpNode);
      //            cout << "PARENT OF CHILD: " << Children[i]->parent << endl;
      //            cout << "CHILD: " << &Children[i] << endl;
    }
  }

  double getUTC(int prevTotal, double constant) {
    if (total == 0) {
      return 100;
    }
    double underSquare = constant * (log(prevTotal)) / total;
    double result = (double)(successes / total) + sqrt(underSquare);
    return result;
  }

  Node* Select(double constant) {
    double bestUTC = -1;
    int bestIndex = -1;
    for (int i = 0; i < Children.size(); i++) {
      //            cout << "CHILD " << i << " UTC: " <<
      //            Children[i]->getUTC(total) << endl;
      if (Children[i]->getUTC(total, constant) > bestUTC) {
        bestUTC = Children[i]->getUTC(total, constant);
        bestIndex = i;
      }
    }
    //        cout << "BEST CHILD: " << &Children[bestIndex] << endl;
    return Children[bestIndex];
  }

  void Win() {
    successes += 1.0;
    total++;
    if (parent != nullptr) {
      parent->Lose();
    }
  }

  void Draw() {
    successes += 0.5;
    total++;
    if (parent != nullptr) {
      parent->Draw();
    }
  }

  void Lose() {
    total++;
    if (parent != nullptr) {
      parent->Win();
    }
  }

  Node* getRoot() {
    if (parent == nullptr) {
      return this;
    }
    return parent->getRoot();
  }

  int getMove() {
    int maxTotal = -1;
    int bestMove = -1;
    for (int i = 0; i < Children.size(); i++) {
      //            cout << "Children " << i << " Total:" << Children[i]->total
      //            << endl;
      if (Children[i]->total > maxTotal) {
        maxTotal = Children[i]->total;
        bestMove = Children[i]->moveHere;
      }
    }

    return bestMove;
  }
};

int MonteCarlo(Board input) {
  while (input.getPossibleMoves().size() > 0 && input.getResult() == 0) {
    int randomIndex = rand() % input.getPossibleMoves().size();
    input.add(input.getPossibleMoves()[randomIndex]);
  }
  return input.getResult();
}

struct AI {
  Node* Current;
  Board Real;
  Board Simulated;

  AI(Board input, int inputPlayer)  // blank board
  {
    Real = input;
    Simulated = input;
    Current = new Node();
    Current->init(inputPlayer);
  }

  void runSimulations() {
    Simulated = Real;
    //        cout << "CURRENT TOTAL: " << Current->total << endl;
    while (Current->madeChildren == true && Simulated.notFinished()) {
      //            cout << "THIS: " << this << endl;
      Current = Current->Select(exploration_constant);
      //            cout << "Selected Child: " << Current << endl;
      Simulated.add(Current->moveHere);
    }
    if (Simulated.notFinished()) {
      //            cout << "MAKING CHILDREN" << endl;
      Current->makeChildren(Simulated);
    }
    //        cout << "MADECHILDREN: " << Current->madeChildren << endl;
    int result = Simulated.getResult();
    if (result == 0) {
      result = MonteCarlo(Simulated);
    }
    if (result == -1 * Current->player) {
      Current->Win();
    } else if (result == 0) {
      Current->Draw();
    } else if (result == Current->player) {
      Current->Lose();
    }
    Current = Current->getRoot();
  }

  void addMove(int moveInput) {
    Real.add(moveInput);
    Node* tmpPointer;
    for (int i = 0; i < Current->Children.size(); i++) {
      if (Current->Children[i]->moveHere == moveInput) {
        tmpPointer = Current->Children[i];
        tmpPointer->parent = nullptr;
      } else {
        Current->Children[i]->free_space();
      }
    }
    Current = tmpPointer;
    return;
    std::cout << "CANNOT ADD MOVE" << std::endl;
  }

  int getMove() {
    Current = Current->getRoot();
    int moveInput = Current->getMove();
    addMove(moveInput);
    return moveInput;
  }
};

int main() {
  srand(time(NULL));
  Board Game;
  std::cout << "Enter which player you would like to be (1 for first, -1 for second)"
       << std::endl;
  int inputPlayer;
  std::cin >> inputPlayer;
  AI GameAI(Game, 1);

  double timer = 0;
  int totalRun = 0;
  while (Game.getResult() == 0) {
    if (Game.getMoves().size() % 2 == (inputPlayer == 1))  // COMPUTERS TURN
    {
      Game.Print();
      std::cout << "Heuristic: "
           << 1 - GameAI.Current->successes / GameAI.Current->total << std::endl;
      std::cout << "Making Calculations..." << std::endl;
      double start = time(0);
      while (time(0) - start <= 1) {
        GameAI.runSimulations();
      }
      totalRun = GameAI.Current->total;
      //            cout << "TOTAL: " << GameAI.Current->total << endl;
      for (int i = 0; i < GameAI.Current->Children.size(); i++) {
        //                cout << "TOTAL FOR CHILD " << i << ": " <<
        //                GameAI.Current->Children[i]->total << endl; cout <<
        //                GameAI.Current->Children[i]->successes/GameAI.Current->Children[i]->total
        //                << endl;//" " << GameAI.Current->Children[i]->total <<
        //                " " <<
        //                GameAI.Current->Children[i]->getUTC(GameAI.Current->total)
        //                << endl;
      }
      Game.add(GameAI.getMove());
    } else  // PLAYERS TURN
    {
      //            _getch();
      Game.Print();
      std::cout << "Leaves: " << totalRun << std::endl;
      std::cout << "Heuristic: " << GameAI.Current->successes / GameAI.Current->total
           << std::endl;
      int input;
      std::cout << "Enter your move: " << std::endl;
      while (true) {
        if (kbhit()) {
            std::cin >> input;
          break;
        }
        if (GameAI.Current->total < maxTrials) {
          GameAI.runSimulations();
        }
        if (GameAI.Current->total == maxTrials - 1) {
            std::cout << "Pondering Completed." << std::endl;
        }
      }
      Game.add(input);
      GameAI.addMove(input);
    }
  }
  Game.Print();
  std::cout << "Result: " << Game.getResult() << std::endl;
  _getch();
  return 0;
}

// @END_OF_SOURCE_CODE
