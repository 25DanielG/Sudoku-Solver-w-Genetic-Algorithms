#include "./genSudoSolver.h"
#include<iostream>
#include <vector>
#include <random>
#include <algorithm>
using std::vector;
using std::cout;
void genSudoSolver::geneticSolver(int pop_size, int s_rate, int ran_s_rate, int num_children, int max_num_generations, int mutation_rate, int n_restart_after, vector<vector<int> > board, int boardSize) {
    int generationNumber = 0;
    vector<boardFitness> initialPopulation = makeInitialPopulation(pop_size, board, boardSize);
    ++generationNumber;
    for(auto v : initialPopulation) {
        v.fitnessScore = calculateFitness(v.singleBoard, boardSize);
    }
    sort(initialPopulation.begin(), initialPopulation.end(), compareFunction);
    
}
vector<genSudoSolver::boardFitness> genSudoSolver::makeInitialPopulation(int pop_size, vector<vector<int> > board, int boardSize) { // Makes the initial population
    vector<boardFitness> population;
    for(int pop = 0; pop < pop_size; ++pop) { // Loop to generate initial population size
        population[pop].singleBoard = board;
        for(int i = 0; i < boardSize; ++i) {
            for(int j = 0; j < boardSize; ++j) {
                if(population[pop].singleBoard[i][j] == 0) {
                    std::random_device ranDevice; // Generates the random numbers to constantly make a different sudok
                    std::mt19937 gen2(ranDevice());
                    std::uniform_int_distribution<int> boardDist(1, 9);
                    int tmp = boardDist(gen2);
                    if(!numberInBox(population[pop].singleBoard, i - i % 3, j - j % 3, tmp))
                        population[pop].singleBoard[i][j] = tmp;
                    else --j; // restart the part of that loop to generate a better number that has no repetition in each box
                }
            }
        }
    }
    return population;
}

vector<genSudoSolver::boardFitness> genSudoSolver::formSubsequentPopulation(int pop_size, int s_rate, int ran_s_rate, vector<genSudoSolver::boardFitness> prevPopulation, vector<vector<int> > board, int boardSize) { // Makes the next population
    vector<boardFitness> population;
    
    return population;
}

vector<genSudoSolver::boardFitness> genSudoSolver::selectParents(int s_rate, int ran_s_rate, vector<genSudoSolver::boardFitness> prevPopulation, vector<vector<int> > board, int boardSize) { // Selects the parents for the next generation
    for(auto v : prevPopulation) {

    }
}

vector<vector<int> > genSudoSolver::makeChild(vector<vector<int> > parentOne, vector<vector<int> > parentTwo, vector<vector<int> > initialBoard, int boardSize, int nb_children) { // Makes children from two parents

}

bool genSudoSolver::numberInColumn(const int boardSize, vector<vector<int> > board, int c, int n) { // checks if a number is in the column
    for(int r = 0; r < boardSize; ++r) {
        if(board[r][c] == n) return true;
    }
    return false;
}

bool genSudoSolver::numberInRow(const int boardSize, vector<vector<int> > board, int r, int n) { // checks if a number is in the row
    for(int c = 0; c < boardSize; ++c) {
        if(board[r][c] == n) return true;
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
    return (!numberInColumn(boardSize, board, col, value) && !numberInRow(boardSize, board, row, value) && !numberInBox(board, (row - row % 3), (col - col % 3), value));
}

int genSudoSolver::calculateFitness(vector<vector<int> > board, int boardSize) {
    int fitness = 0;
    for(int i = 0; i < boardSize; ++i) {
        for(int j = 0; j < boardSize; ++j) {
            if(isLegalPlacement(i, j, board[i][j], boardSize, board)) ++fitness;
        }
    }
    return fitness;
}
bool compareFunction(genSudoSolver::boardFitness a, genSudoSolver::boardFitness b) { // Compare function to sort
    return a.fitnessScore > b.fitnessScore;
}