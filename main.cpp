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

    // BACKTRACKING / GA
    bool backtrack = false;
    bool ga = true;

    // PARAMETERS
    const int populationSize = 20000; // Population size
    int selectionRateChance = 25; // Percent chance
    int randomRateChance = 25; // Percent chance
    int numberChildren = 4; // Number of children per pair of parents
    int mutationRate = 25; // Percent chance
    int restartAfterNImprovement = 25; // Restart after N generations without improvement
    int maxGenerationCap = 100; // Max generation cap

    int multiple = populationSize / 100;
    selectionRateChance *= multiple;
    randomRateChance *= multiple;
    int restartNumber = 0;
    // The mutation rate is less strict than the selection rate and random selection rate
    auto start = high_resolution_clock::now();
    // GA
    if(ga) {
        while(!genSudoSolver::geneticSolver(populationSize, selectionRateChance, randomRateChance, numberChildren, mutationRate, restartAfterNImprovement, maxGenerationCap, initialBoard, boardSize, restartNumber)) {
            ++restartNumber;
        }
    }
    
    // BACKTRACKING
    if(backtrack) {
        vector<int> allowedNums(boardSize, 0);
        for(int i = 0; i < boardSize; ++i) {
            allowedNums[i] = i + 1;
        }
        bool solvable = sudoSolver::solveSudoku(boardSize, initialBoard, allowedNums);
        cout << endl;
        for(int i = 0; i < boardSize; ++i) {
            for(int j = 0; j < boardSize; ++j) {
                cout << initialBoard[i][j] << " ";
            }
            cout << endl;
        }
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    cout << "Time taken for solution: " << duration.count() << " seconds with " << restartNumber << " restarts." << endl;
}