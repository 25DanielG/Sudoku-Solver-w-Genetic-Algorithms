#include "./genSudoSolver.h"
#include<iostream>
#include <vector>
#include <random>
using std::vector;
using std::cout;
void geneticSolver(int pop_size, float s_rate, float ran_s_rate, int num_children, int max_num_generations, float mutation_rate, vector<vector<int> > board, int boardSize) {

}
vector<vector<vector<int> > > initialPopulation(int pop_size, vector<vector<int> > board, int boardSize) {
    vector<vector<vector<int> > > population;
    for(int pop = 0; pop < pop_size; ++pop) { // Loop to generate initial population size
        population[pop] = board;
        for(int i = 0; i < boardSize; ++i) {
            for(int j = 0; j < boardSize; ++j) {
                if(population[pop][i][j] == 0) {
                    std::random_device ranDevice; // Generates the random numbers to constantly make a different sudok
                    std::mt19937 gen2(ranDevice());
                    std::uniform_int_distribution<int> boardDist(1, 9);
                    int tmp = boardDist(gen2);
                    population[pop][i][j] = tmp;
                }
            }
        }
    }
}