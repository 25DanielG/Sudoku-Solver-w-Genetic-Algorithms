#include <iostream>
#include <vector>
#include <chrono>
#include "./src/genSudoSolver.h"
using std::cout;
using std::endl;
using std::vector;
using std::cin;
using namespace std::chrono;
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
    //                                          25%   25%    10%
    auto start = high_resolution_clock::now();
    while(!genSudoSolver::geneticSolver(10000, 2500, 2500, 4, 10, 500, 10000, initialBoard, boardSize));
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    cout << "Time taken for solution: " << duration.count() << " seconds." << endl;
}
/*
----
EASY
----
0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0
1 9 0 0 0 4 5 0 0
8 2 0 1 0 0 0 4 0
0 0 4 6 0 2 9 0 0
0 5 0 0 0 3 0 2 8
0 0 9 3 0 0 0 7 4
0 4 0 0 5 0 0 3 6
7 0 3 0 1 8 0 0 0

Solved in 801 seconds (13 minutes 21 seconds)
                        26 generations
                        0 restarts
                        5000 population size

-----------
AI ESCARGOT
-----------
8 0 0 0 0 0 0 0 0
0 0 3 6 0 0 0 0 0
0 7 0 0 9 0 2 0 0 
0 5 0 0 0 7 0 0 0
0 0 0 0 4 5 7 0 0 
0 0 0 1 0 0 0 3 0
0 0 1 0 0 0 0 6 8
0 0 8 5 0 0 0 1 0
0 9 0 0 0 0 4 0 0

Ran out of patience after more than 300 generations
                                    2 restarts
                                    2 hours
                                    10000 population size
*/