#ifndef SUDOSOLVER_H_
#define SUDOSOLVER_H_
#include <vector>
using std::vector;
namespace sudoSolver {
    bool numberInColumn(int boardSize, vector<vector<int> > board, int c, int n); // checks if a number is in the column
    bool numberInRow(int boardSize, vector<vector<int> > board, int r, int n); // checks if a number is in the row
    bool numberInBox(vector<vector<int> > board, int startR, int startC, int n); // checks if a number is in the box
    bool isLegalPlacement(int row, int col, int value, int boardSize, vector<vector<int> > board); // check if you can put a number
    std::pair<int, int> findUnassignedSlots(vector<vector<int> > &board); // finds empty slots on the board
    int countUnassignedSlots(vector<vector<int> > board); // counts number of empty slots on the board
    bool solveSudoku(int boardSize, vector<vector<int> > &board, vector<int> allowedNums); // board includes sudoku puzzle with 0's in place of empty spots
    int isOneSolution(int row, int col, vector<vector<int> > board, int count, int boardSize); // checks if there is one solution to a sudoku puzzle
    // vectors are not reference for solvers in order to not break code
}
#endif