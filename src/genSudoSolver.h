#ifndef GENSUDOSOLVER_H_
#define GENSUDOSOLVER_H_
#include <vector>
#include <algorithm>
#include <iostream>
using std::vector;
namespace genSudoSolver {
    struct boardFitness {
        vector<vector<int> > singleBoard;
        int fitnessScore;
    };
    // Defines all the necessary parameters for the genetic algorithm
    bool geneticSolver(int pop_size, int s_rate, int ran_s_rate, int num_children, int mutation_rate, int n_restart_after, int max_generation_number, vector<vector<int> > board, int boardSize);
    // Function to create the initial population of puzzles
    vector<boardFitness> makeInitialPopulation(int pop_size, vector<vector<int> > board, int boardSize);
    // Function to make the next population
    vector<boardFitness> formSubsequentPopulation(int pop_size, int s_rate, int ran_s_rate, vector<boardFitness> prevPopulation, vector<vector<int> > board, int boardSize, int nb_children, int mutation_rate);
    // Selects the parents for the next generation
    vector<boardFitness> selectParents(int s_rate, int ran_s_rate, vector<boardFitness> prevPopulation, vector<vector<int> > board, int boardSize);
    // Makes children from two parents
    vector<vector<int> > makeChild(vector<vector<int> > parentOne, vector<vector<int> > parentTwo, vector<vector<int> > initialBoard, int boardSize, int nb_children, int mutation_rate);
    // Mutates the child after a chance
    vector<vector<int> > mutateChild(vector<vector<int> > child, int boardSize);
    // Swaps to elements in 2d vectors
    vector<vector<int> > swapTwoElements(int rowIndexOne, int colIndexOne, int rowIndexTwo, int colIndexTwo, vector<vector<int> > first);
    bool numberInColumn(const int boardSize, vector<vector<int> > board, int row, int col, int n); // checks if a number is in the column
    bool numberInRow(const int boardSize, vector<vector<int> > board, int row, int col, int n); // checks if a number is in the row
    bool numberInBox(vector<vector<int> > board, int startR, int startC, int n); // checks if a number is in the box
    bool isLegalPlacement(int row, int col, int value, int boardSize, vector<vector<int> > board); // check if you can put a number
    // Calculates the fitness of a board
    int calculateFitness(vector<vector<int> > board, int boardSize);
    bool compareFunction(boardFitness a, boardFitness b); // Compare function to sort
}
#endif