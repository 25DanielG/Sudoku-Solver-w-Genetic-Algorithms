#include "./genSudoSolver.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
bool genSudoSolver::geneticSolver(const int pop_size, const int s_rate, const int ran_s_rate, const int num_children, const int mutation_rate, const int n_restart_after, const int max_generation_number, const vector<vector<int> > board, const int boardSize, int numRestarts) {
    cout << "Entered genetic algorithm." << endl;
    int generationNumber = 0, prevMaxFitness = 0, prevMaxGeneration = 0;
    vector<boardFitness> currentPopulation = makeInitialPopulation(pop_size, board, boardSize);
    ++generationNumber;
    cout << "Made initial population." << endl;
    while(true) {
        if(generationNumber >= max_generation_number) { // Restarts after hard cap on generations
            cout << "Restarting since " << max_generation_number << " generations reached." << endl;
        }
        for(auto &v : currentPopulation) {
            v.fitnessScore = calculateFitness(v.singleBoard, boardSize);
        }
        cout << "Calculated fitness levels." << endl;
        sort(currentPopulation.begin(), currentPopulation.end(), compareFunction);
        if(currentPopulation[currentPopulation.size() - 1].fitnessScore > prevMaxFitness) {
            prevMaxFitness = currentPopulation[currentPopulation.size() - 1].fitnessScore;
            prevMaxGeneration = generationNumber;
        } else if(generationNumber - prevMaxGeneration >= n_restart_after) { // Restarts after # of generations w/out improvement
            cout << "Restarting after " << n_restart_after << " generations without improvement." << endl;
            return false;
        }
        if(currentPopulation[currentPopulation.size() - 1].fitnessScore == 81) { // there is a solution
            cout << "Found a solution" << endl << "-----------------" << endl;
            for(int i = 0; i < boardSize; ++i) {
                for(int j = 0; j < boardSize; ++j) {
                    cout << currentPopulation[currentPopulation.size() - 1].singleBoard[i][j] << " ";
                }
                cout << endl;
            }
            return true;
        }
        cout << "Generation number: " << generationNumber << "; Number of restarts: " << numRestarts << "; Best fitness level: " << currentPopulation[currentPopulation.size() - 1].fitnessScore << "; Worst fitness level: " << currentPopulation[0].fitnessScore << "; Pop size: " << currentPopulation.size() << endl;
        currentPopulation = formSubsequentPopulation(pop_size, s_rate, ran_s_rate, currentPopulation, board, boardSize, num_children, mutation_rate);
        cout << "Formed subsequent population." << endl;
        ++generationNumber;
    }
}

vector<genSudoSolver::boardFitness> genSudoSolver::makeInitialPopulation(const int pop_size, const vector<vector<int> > board, const int boardSize) { // Makes the initial population
    vector<boardFitness> population(pop_size);
    vector<int> availableNumbers(boardSize, 0); // vector containing the available numbers
    for(int i = 1; i <= boardSize; ++i) {
        availableNumbers[i - 1] = i;
    }
    int availableNumbersSize = availableNumbers.size();
    for(int pop = 0; pop < pop_size; ++pop) { // Loop to generate initial population size
        population[pop].singleBoard = board;
        for(int rowRos = 0; rowRos < boardSize; rowRos += 3) { // vertical position (0, 3, 6)
            for(int colPos = 0; colPos < boardSize; colPos += 3) { // horizontal position (0, 3, 6)
                availableNumbersSize = availableNumbers.size();
                for(int i = rowRos; i < rowRos + 3; ++i) {
                    for(int j = colPos; j < colPos + 3; ++j) {
                        if(population[pop].singleBoard[i][j] != 0) {
                            vector<int>::iterator it = find(availableNumbers.begin(), availableNumbers.end(), population[pop].singleBoard[i][j]); // Removes a number if its already in the box
                            int tmp = *it;
                            availableNumbers.erase(it);
                            availableNumbers.push_back(tmp);
                            --availableNumbersSize;
                        }
                    }
                }
                for(int i = rowRos; i < rowRos + 3; ++i) {
                    for(int j = colPos; j < colPos + 3; ++j) {
                        if(population[pop].singleBoard[i][j] == 0) { // Generates index that points to an array of possible numbers
                            std::random_device ranDevice; // Generates the random numbers to constantly make a different sudoku
                            std::mt19937 gen2(ranDevice());
                            std::uniform_int_distribution<int> boardDist(0, availableNumbersSize - 1);
                            int tmpIndex = boardDist(gen2);
                            population[pop].singleBoard[i][j] = availableNumbers[tmpIndex];
                            int tmp = availableNumbers[tmpIndex]; // Moves tmpIndex element to end
                            availableNumbers.erase(availableNumbers.begin() + tmpIndex);
                            availableNumbers.push_back(tmp);
                            --availableNumbersSize;
                        }
                    }
                }
            }
        }
    }
    return population;
}

vector<genSudoSolver::boardFitness> genSudoSolver::formSubsequentPopulation(const int pop_size, const int s_rate, const int ran_s_rate, vector<boardFitness> prevPopulation, const vector<vector<int> > board, const int boardSize, const int nb_children, const int mutation_rate) { // Makes the next population
    vector<genSudoSolver::boardFitness> parents = selectParents(s_rate, ran_s_rate, prevPopulation, board, boardSize);
    cout << "Selected parents for subsequent generation." << endl;
    vector<genSudoSolver::boardFitness> children(pop_size);
    int childCnt = 0;
    for(int i = 0; i < parents.size(); i += 2) { // Makes all the children
        for(int j = 0; j < nb_children; ++j) {
            children[childCnt].singleBoard = makeChild(parents[i].singleBoard, parents[i + 1].singleBoard, board, boardSize, nb_children, mutation_rate);
            ++childCnt;
        }
    }
    return children;
}

vector<genSudoSolver::boardFitness> genSudoSolver::selectParents(const int s_rate, const int ran_s_rate, vector<boardFitness> prevPopulation, const vector<vector<int> > board, const int boardSize) { // Selects the parents for the next generation
    vector<genSudoSolver::boardFitness> selectedParents; // Requires the previous population that is already sorted
    for(int i = 0; i < s_rate; ++i) { // Picks and erases elements from the back to prevent having to erase elements from the beginning
        // Chooses the most fit parents
        selectedParents.push_back(*(prevPopulation.end() - 1));
        prevPopulation.erase(prevPopulation.end() - 1);
    }
    for(int i = 0; i < ran_s_rate; ++i) {
        // Chooses some parents randomly
        std::random_device ranDevice; // Generates the random numbers to constantly make a different sudoku
        std::mt19937 gen2(ranDevice());
        std::uniform_int_distribution<int> boardDist(0, prevPopulation.size() - 1);
        //cout << "Random parents population size: " << prevPopulation.size() << endl;
        int tmp = boardDist(gen2);
        selectedParents.push_back(prevPopulation[tmp]);
        genSudoSolver::boardFitness tmpElement = prevPopulation[tmp];
        prevPopulation[tmp] = *(prevPopulation.end() - 1);
        *(prevPopulation.end() - 1) = tmpElement;
        prevPopulation.erase(prevPopulation.end() - 1);
    }
    return selectedParents;
}

vector<vector<int> > genSudoSolver::makeChild(vector<vector<int> > parentOne, vector<vector<int> > parentTwo, const vector<vector<int> > board, const int boardSize, const int nb_children, const int mutation_rate) { // Makes children from two parents
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
    // Mutates a child with a chance
    std::random_device ranDevice; // Generates the random numbers to constantly make a different sudoku
    std::mt19937 gen2(ranDevice());
    std::uniform_int_distribution<int> boardDist(1, 100 / mutation_rate); // 0 corresponds to parentOne | 1 corresponds to parent 2
    int randomNum = boardDist(gen2);
    int cnt = 0;
    if(randomNum == 1) {
        child = mutateChild(board, child, boardSize);
    }
    return child;
}

vector<vector<int> > genSudoSolver::mutateChild(vector<vector<int> > board, vector<vector<int> > child, const int boardSize) { // Mutates the child
    std::random_device ranDevice; // Generates the random numbers to constantly make a different sudoku
    std::mt19937 gen2(ranDevice());
    std::uniform_int_distribution<int> boardDist(0, 8);
    int switchOne = boardDist(gen2);
    int rowPosOne = switchOne / 3;
    int colPosOne = switchOne - (3 * rowPosOne);
    int tmpOne = 0, tmpTwo = 0, rPosOne = 0, rPosTwo = 0, cPosOne = 0, cPosTwo = 0;
    while(true) {
        tmpOne = boardDist(gen2);
        tmpTwo = boardDist(gen2);
        //cout << tmpOne << " " << tmpTwo << endl;
        rPosOne = tmpOne / 3, rPosTwo = tmpTwo / 3;
        cPosOne = tmpOne - (3 * rPosOne), cPosTwo = tmpTwo - (3 * rPosTwo);
        if(board[3 * rowPosOne + rPosOne][3 * colPosOne + cPosOne] == 0 && board[3 * rowPosOne + rPosTwo][3 * colPosOne + cPosTwo] == 0) {
            break;
        }
    }
    int temporary = child[3 * rowPosOne + rPosOne][3 * colPosOne + cPosOne];
    child[3 * rowPosOne + rPosOne][3 * colPosOne + cPosOne] = child[3 * rowPosOne + rPosTwo][3 * colPosOne + cPosTwo];
    child[3 * rowPosOne + rPosTwo][3 * colPosOne + cPosTwo] = temporary;
    //child = swapTwoElements(3 * rowPosOne + rPosOne, 3 * colPosOne + cPosOne, 3 * rowPosOne + rPosTwo, 3 * colPosOne + cPosTwo, child);
    return child;
}

vector<vector<int> > genSudoSolver::swapTwoElements(const int rowIndexOne, const int colIndexOne, const int rowIndexTwo, const int colIndexTwo, vector<vector<int> > first) { // Swaps to elements in 2d vectors
    int tmp = first[rowIndexOne][colIndexOne];
    first[rowIndexOne][colIndexOne] = first[rowIndexTwo][colIndexTwo];
    first[rowIndexTwo][colIndexTwo] = tmp;
    return first;
}

bool genSudoSolver::numberInColumn(const int boardSize, const vector<vector<int> > board, const int row, const int col, const int n) { // checks if a number is in the column
    for(int r = 0; r < boardSize; ++r) {
        if(r == row) continue;
        if(board[r][col] == n) return true;
    }
    return false;
}

bool genSudoSolver::numberInRow(const int boardSize, const vector<vector<int> > board, const int row, const int col, const int n) { // checks if a number is in the row
    for(int c = 0; c < boardSize; ++c) {
        if(c == col) continue;
        if(board[row][c] == n) return true;
    }
    return false;
}

bool genSudoSolver::numberInBox(const vector<vector<int> > board, const int startR, int startC, int n) { // checks if a number is in the box
    for(int r = startR; r < startR + 3; ++r) {
        for(int c = startC; c < startC + 3; ++c) {
            if(board[r][c] == n) return true;
        }
    }
    return false;
}

bool genSudoSolver::isLegalPlacement(const int row, const int col, const int value, const int boardSize, const vector<vector<int> > board) { // check if you can put a number
    return (!numberInColumn(boardSize, board, row, col, value) && !numberInRow(boardSize, board, row, col, value) && !numberInBox(board, row - row % 3, col - col % 3, value));
}

int genSudoSolver::calculateFitness(const vector<vector<int> > board, const int boardSize) {
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
bool genSudoSolver::compareFunction(const genSudoSolver::boardFitness a, const genSudoSolver::boardFitness b) { // Compare function to sort
    return a.fitnessScore < b.fitnessScore;
}