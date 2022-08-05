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
    bool geneticSolver(const int pop_size, const int s_rate, const int ran_s_rate, const int num_children, const int mutation_rate, const int n_restart_after, const int max_generation_number, const vector<vector<int> > board, const int boardSize, int numRestarts);
    // Function to create the initial population of puzzles
    vector<boardFitness> makeInitialPopulation(const int pop_size, const vector<vector<int> > board, const int boardSize);
    // Function to make the next population
    vector<boardFitness> formSubsequentPopulation(const int pop_size, const int s_rate, const int ran_s_rate, vector<boardFitness> prevPopulation, const vector<vector<int> > board, const int boardSize, const int nb_children, const int mutation_rate);
    // Selects the parents for the next generation
    vector<boardFitness> selectParents(const int s_rate, const int ran_s_rate, vector<boardFitness> prevPopulation, const vector<vector<int> > board, const int boardSize);
    // Makes children from two parents
    vector<vector<int> > makeChild(vector<vector<int> > parentOne, vector<vector<int> > parentTwo, const vector<vector<int> > board, const int boardSize, const int nb_children, const int mutation_rate);
    // Mutates the child after a chance
    vector<vector<int> > mutateChild(vector<vector<int> > board, vector<vector<int> > child, const int boardSize);
    // Swaps to elements in 2d vectors
    vector<vector<int> > swapTwoElements(const int rowIndexOne, const int colIndexOne, const int rowIndexTwo, const int colIndexTwo, vector<vector<int> > first);
    bool numberInColumn(const int boardSize, const vector<vector<int> > board, const int row, const int col, const int n); // checks if a number is in the column
    bool numberInRow(const int boardSize, const vector<vector<int> > board, const int row, const int col, const int n); // checks if a number is in the row
    bool numberInBox(const vector<vector<int> > board, const int startR, int startC, int n); // checks if a number is in the box
    bool isLegalPlacement(const int row, const int col, const int value, const int boardSize, const vector<vector<int> > board); // check if you can put a number
    // Calculates the fitness of a board
    int calculateFitness(const vector<vector<int> > board, const int boardSize);
    bool compareFunction(const boardFitness a, const boardFitness b); // Compare function to sort
}
#endif