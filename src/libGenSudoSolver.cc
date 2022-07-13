#include "./genSudoSolver.h"
#include<iostream>
#include <vector>
#include <random>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
bool genSudoSolver::geneticSolver(int pop_size, int s_rate, int ran_s_rate, int num_children, int mutation_rate, int n_restart_after, vector<vector<int> > board, int boardSize) {
    int generationNumber = 0;
    vector<boardFitness> currentPopulation = makeInitialPopulation(pop_size, board, boardSize);
    ++generationNumber;
    cout << "Made initial population." << endl << "Example of two generated boards:" << endl;
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            cout << currentPopulation[0].singleBoard[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            cout << currentPopulation[1].singleBoard[i][j] << " ";
        }
        cout << endl;
    }
    while(true) {
        if(generationNumber >= n_restart_after) {
            return false; // stop condition
        }
        for(auto &v : currentPopulation) {
            v.fitnessScore = calculateFitness(v.singleBoard, boardSize);
        }
        cout << "Calculated fitness levels." << endl;
        sort(currentPopulation.begin(), currentPopulation.end(), compareFunction);
        if(currentPopulation[0].fitnessScore == 81) { // there is a solution
            cout << "Found a solution" << endl << "-----------------" << endl;
            for(int i = 0; i < boardSize; ++i) {
                for(int j = 0; j < boardSize; ++j) {
                    cout << currentPopulation[0].singleBoard[i][j] << " ";
                }
                cout << endl;
            }
            return true;
        }
        cout << "Generation number: " << generationNumber << "; Best fitness level: " << currentPopulation[0].fitnessScore << "; Worst fitness level: " << currentPopulation[currentPopulation.size() - 1].fitnessScore << " Pop size: " << currentPopulation.size() << endl;
        currentPopulation = formSubsequentPopulation(pop_size, s_rate, ran_s_rate, currentPopulation, board, boardSize, num_children);
        cout << "Formed subsequent population." << endl;
        ++generationNumber;
    }
}
vector<genSudoSolver::boardFitness> genSudoSolver::makeInitialPopulation(int pop_size, vector<vector<int> > board, int boardSize) { // Makes the initial population
    vector<boardFitness> population(pop_size);
    for(int pop = 0; pop < pop_size; ++pop) { // Loop to generate initial population size
        population[pop].singleBoard = board;
        for(int i = 0; i < boardSize; ++i) {
            for(int j = 0; j < boardSize; ++j) {
                if(population[pop].singleBoard[i][j] == 0) {
                    std::random_device ranDevice; // Generates the random numbers to constantly make a different sudok
                    std::mt19937 gen2(ranDevice());
                    std::uniform_int_distribution<int> boardDist(1, 9);
                    int tmp = boardDist(gen2); // make array of elements left and choose out of them
                    if(!numberInBox(population[pop].singleBoard, i - i % 3, j - j % 3, tmp))
                        population[pop].singleBoard[i][j] = tmp;
                    else --j; // restart the part of that loop to generate a better number that has no repetition in each box
                }
            }
        }
    }
    return population;
}

vector<genSudoSolver::boardFitness> genSudoSolver::formSubsequentPopulation(int pop_size, int s_rate, int ran_s_rate, vector<genSudoSolver::boardFitness> prevPopulation, vector<vector<int> > board, int boardSize, int nb_children) { // Makes the next population
    vector<genSudoSolver::boardFitness> parents = selectParents(s_rate, ran_s_rate, prevPopulation, board, boardSize);
    cout << "Selected parents for subsequent generation." << endl;
    vector<genSudoSolver::boardFitness> children(pop_size);
    int childCnt = 0;
    for(int i = 0; i < parents.size(); i += 2) { // Makes all the children
        for(int j = 0; j < nb_children; ++j) {
            children[childCnt].singleBoard = makeChild(parents[i].singleBoard, parents[i + 1].singleBoard, board, boardSize, nb_children);
            ++childCnt;
        }
    }
    return children;
}

vector<genSudoSolver::boardFitness> genSudoSolver::selectParents(int s_rate, int ran_s_rate, vector<genSudoSolver::boardFitness> prevPopulation, vector<vector<int> > board, int boardSize) { // Selects the parents for the next generation
    vector<genSudoSolver::boardFitness> selectedParents; // Requires the previous population that is already sorted
    cout << "Initial make parents pop size: " << prevPopulation.size() << endl;
    for(int i = 0; i < s_rate; ++i) {
        // Chooses the most fit parents
        selectedParents.push_back(prevPopulation[i]);
        prevPopulation.erase(prevPopulation.begin());
    }
    cout << "Selected the best parents." << endl;
    cout << "After selected parents pop size: " << prevPopulation.size() << endl;
    for(int i = 0; i < ran_s_rate; ++i) {
        // Chooses some parents randomly
        std::random_device ranDevice; // Generates the random numbers to constantly make a different sudoku
        std::mt19937 gen2(ranDevice());
        std::uniform_int_distribution<int> boardDist(0, prevPopulation.size() - 1);
        //cout << "Random parents population size: " << prevPopulation.size() << endl;
        int tmp = boardDist(gen2);
        selectedParents.push_back(prevPopulation[tmp]);
        prevPopulation.erase(prevPopulation.begin() + tmp);
    }
    cout << "Selected the randomized parents." << endl;
    cout << "After randomized parents pop size: " << prevPopulation.size() << endl;
    return selectedParents;
}

vector<vector<int> > genSudoSolver::makeChild(vector<vector<int> > parentOne, vector<vector<int> > parentTwo, vector<vector<int> > initialBoard, int boardSize, int nb_children) { // Makes children from two parents
    vector<int> genes(boardSize, 0);
    for(int i = 0; i < boardSize; ++i) {
        std::random_device ranDevice; // Generates the random numbers to constantly make a different sudoku
        std::mt19937 gen2(ranDevice());
        std::uniform_int_distribution<int> boardDist(0, 1); // 0 corresponds to parentOne | 1 corresponds to parent 2
        int whichParent = boardDist(gen2);
        genes[i] = whichParent; // Makes a vector telling which boxes belon to which parents
    }
    vector<vector<int> > child(boardSize, vector<int>(boardSize, 0));
    int geneCnt = 0;
    for(int rowRos = 0; rowRos < boardSize; rowRos += 3) { // vertical position (0, 3, 6)
        for(int colPos = 0; colPos < boardSize; colPos += 3) { // horizontal position (0, 3, 6)
            if(genes[geneCnt] == 0) {
                for(int i = rowRos; i < rowRos + 3; ++i) {
                    for(int j = colPos; j < colPos + 3; ++j) {
                        child[i][j] = parentOne[i][j];
                    }
                }
            } else {
                for(int i = rowRos; i < rowRos + 3; ++i) {
                    for(int j = colPos; j < colPos + 3; ++j) {
                        child[i][j] = parentTwo[i][j];
                    }
                }
            }
            ++geneCnt;
        }
    }
    return child;
}

/*
0, 1, 2     3, 4, 5     6, 7, 8
-------------------------------
1, 2, 3,    4, 5, 6,    7, 8, 9
1, 2, 3,    4, 5, 6,    7, 8, 9
1, 2, 3,    4, 5, 6,    7, 8, 9

1, 2, 3,    4, 5, 6,    7, 8, 9
1, 2, 3,    4, 5, 6,    7, 8, 9
1, 2, 3,    4, 5, 6,    7, 8, 9

1, 2, 3,    4, 5, 6,    7, 8, 9
1, 2, 3,    4, 5, 6,    7, 8, 9
1, 2, 3,    4, 5, 6,    7, 8, 9

0, 1, 2
if index % 3 == 0 restart
some way to tell where to start
horizontal start (boxes: 1, 2, 3)
column start (columns: 1, 2, 3)

if(horizontal start gets bigger than boadSize / 3 (9 / 3) == 3)
then move one vertical down
if vertical gets bigger than boardSize / 3 (9 / 3) == 3 then you are done
*/

vector<vector<int> > genSudoSolver::mutateChild(vector<vector<int> > child, int boardSize) { // Mutates the child   
    std::random_device ranDevice; // Generates the random numbers to constantly make a different sudok
    std::mt19937 gen2(ranDevice());
    std::uniform_int_distribution<int> boardDist(0, 8); // 0 corresponds to parentOne | 1 corresponds to parent 2
    int switchOne = boardDist(gen2), switchTwo = boardDist(gen2);
    int horiPosOne, vertPosOne, horoPosTwo, vertPosTwo;
}

bool genSudoSolver::numberInColumn(const int boardSize, vector<vector<int> > board, int row, int col, int n) { // checks if a number is in the column
    for(int r = 0; r < boardSize; ++r) {
        if(r == row) continue;
        if(board[r][col] == n) return true;
    }
    return false;
}

bool genSudoSolver::numberInRow(const int boardSize, vector<vector<int> > board, int row, int col, int n) { // checks if a number is in the row
    for(int c = 0; c < boardSize; ++c) {
        if(c == col) continue;
        if(board[row][c] == n) return true;
    }
    return false;
}

bool genSudoSolver::numberInBox(vector<vector<int> > board, int startR, int startC, int n) { // checks if a number is in the box
    for(int r = startR; r < startR + 3; ++r) {
        for(int c = startC; c < startC + 3; ++c) {
            if(board[r][c] == n) return true;
        }
    }
    return false;
}

bool genSudoSolver::isLegalPlacement(int row, int col, int value, int boardSize, vector<vector<int> > board) { // check if you can put a number
    return (!numberInColumn(boardSize, board, row, col, value) && !numberInRow(boardSize, board, row, col, value) && !numberInBox(board, row - row % 3, col - col % 3, value));
}

int genSudoSolver::calculateFitness(vector<vector<int> > board, int boardSize) {
    int fitness = 0;
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            if(!numberInColumn(boardSize, board, i, j, board[i][j]) && !numberInRow(boardSize, board, i, j, board[i][j])) {
                ++fitness;
            }
        }
    }
    return fitness;
}
bool genSudoSolver::compareFunction(genSudoSolver::boardFitness a, genSudoSolver::boardFitness b) { // Compare function to sort
    return a.fitnessScore > b.fitnessScore;
}