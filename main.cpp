#include <iostream>
#include <vector>
#include "./src/genSudoSolver.h"
using std::cout;
using std::endl;
using std::vector;
using std::cin;
const int boardSize = 9; // 3x3 box grid
int main() {
    vector<vector<int> > initialBoard(boardSize, vector<int>(boardSize, 0));
    for(int i = 0; i < boardSize; ++i) { // Reads in initial board
        for(int j = 0; j < boardSize; ++j) {
            int tmp;
            cin >> tmp;
            initialBoard[i][j] = tmp; // There must be zeros for unfilled slots
        }
    }
    cout << "Entered genetic algorithm." << endl;
    while(!genSudoSolver::geneticSolver(5000, 1250, 1250, 4, 1250, 30, initialBoard, boardSize));
}
/*
0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0
1 9 0 0 0 4 5 0 0
8 2 0 1 0 0 0 4 0
0 0 4 6 0 2 9 0 0
0 5 0 0 0 3 0 2 8
0 0 9 3 0 0 0 7 4
0 4 0 0 5 0 0 3 6
7 0 3 0 1 8 0 0 0

3 2 7 2 6 1 7 4 1 
6 8 4 3 7 5 8 9 6 
1 9 5 8 9 4 5 3 2 
8 2 9 1 4 8 6 4 5 
1 7 4 6 9 2 9 1 7 
3 5 6 7 5 3 3 2 8 
5 8 9 3 6 7 8 7 4 
2 4 6 2 5 9 2 3 6 
7 1 3 4 1 8 5 1 9

7 3 2 2 6 1 7 4 1 
6 8 5 9 7 8 2 9 8 
1 9 4 5 3 4 5 6 3 
8 2 7 1 9 5 5 4 1 
1 6 4 6 7 2 9 6 3 
3 5 9 4 8 3 7 2 8 
5 8 9 3 6 9 1 7 4 
6 4 1 7 5 2 8 3 6 
7 2 3 4 1 8 9 2 5
*/