#include <iostream>
#include <vector>
#include <chrono>
#include "./src/genSudoSolver.h"
#include "./src/sudosolver.h"
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

    // PARAMETERS
    const int populationSize = 10000; // Population size
    int selectionRateChance = 25; // Percent chance
    int randomRateChance = 25; // Percent chance
    int numberChildren = 4; // Number of children per pair of parents
    int mutationRate = 10; // Percent chance
    int restartAfterNImprovement = 25; // Restart after N generations without improvement
    int maxGenerationCap = 100; // Max generation cap

    int multiple = populationSize / 100;
    selectionRateChance *= multiple;
    randomRateChance *= multiple;
    int restartNumber = 0;
    // The mutation rate is less strict than the selection rate and random selection rate

    // GA
    auto start = high_resolution_clock::now();
    while(!genSudoSolver::geneticSolver(populationSize, selectionRateChance, randomRateChance, numberChildren, mutationRate, restartAfterNImprovement, maxGenerationCap, initialBoard, boardSize, restartNumber)) {
        ++restartNumber;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    
    // BACKTRACKING
    /*
    vector<int> allowedNums(boardSize, 0);
    for(int i = 0; i < boardSize; ++i) {
        allowedNums[i] = i + 1;
    }
    auto start = high_resolution_clock::now();
    bool solvable = sudoSolver::solveSudoku(boardSize, initialBoard, allowedNums);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    cout << endl;
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            cout << initialBoard[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << "Time taken for solution: " << duration.count() << " seconds with " << restartNumber << " restarts." << endl;
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

Solved in 801 seconds (13 minutes 21 seconds), 26 generations, 0 restarts, 5000 population size GA
Solved in 551 seconds (9 minutes 11 seconds), 19 generations, 0 restarts, 10000 population size GA
Solved in 0 seconds BACKTRACKING

------
MEDIUM
------
7 0 0 0 3 6 0 4 0
0 4 0 1 0 0 0 7 0
3 0 0 0 0 0 1 0 0
5 3 0 0 0 0 0 0 0
2 0 9 6 4 0 0 0 0
0 6 0 9 7 0 0 8 0
0 2 0 7 0 4 0 0 5
0 0 0 0 0 8 0 0 4
0 5 4 0 6 9 0 0 1

Solved in 0 seconds BACKTRACKING

----
HARD
----
0 0 0 2 0 0 0 6 3
3 0 0 0 0 5 4 0 1
0 0 1 0 0 3 9 8 0
0 0 0 0 0 0 0 9 0
0 0 0 5 3 8 0 0 0
0 3 0 0 0 0 0 0 0
0 2 6 3 0 0 5 0 0
5 0 3 7 0 0 0 0 8
4 7 0 0 0 1 0 0 0

Solved in 0 seconds BACKTRACKING

------
EXPERT
------
0 0 1 6 0 0 0 0 2
0 4 0 0 3 0 8 0 0
6 5 0 0 0 0 0 0 3
2 0 0 0 7 3 0 0 0
0 0 0 9 0 1 2 0 0
0 0 0 0 4 0 9 0 0
8 0 3 1 0 0 0 0 0
0 7 0 0 0 0 0 0 8
9 1 0 0 0 0 0 0 7

Solved in 0 seconds BACKTRACKING

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

Ran out of patience after more than ~25000 generations, ~28 restarts, 8.5 hours, 10000 population size
*/