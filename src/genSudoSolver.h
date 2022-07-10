#ifndef GENSUDOSOLVER_H_
#define GENSUDOSOLVER_H_
#include <vector>
using std::vector;
namespace genSudoSolver {
    // Defines all the necessary parameters for the genetic algorithm
    void geneticSolver(int pop_size, float s_rate, float ran_s_rate, int num_children, int max_num_generations, float mutation_rate, vector<vector<int> > board, int boardSize);
    // Function to create the initial population of puzzles
    vector<vector<vector<int> > > initialPopulation(int pop_size, vector<vector<int> > board, int boardSize);
}
#endif