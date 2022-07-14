#include "./sudosolver.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;
using namespace std::chrono;

bool sudoSolver::numberInColumn(const int boardSize, vector<vector<int> > board, int c, int n) { // checks if a number is in the column
    for(int r = 0; r < boardSize; ++r) {
        if(board[r][c] == n) return true;
    }
    return false;
}

bool sudoSolver::numberInRow(const int boardSize, vector<vector<int> > board, int r, int n) { // checks if a number is in the row
    for(int c = 0; c < boardSize; ++c) {
        if(board[r][c] == n) return true;
    }
    return false;
}

bool sudoSolver::numberInBox(vector<vector<int> > board, int startR, int startC, int n) { // checks if a number is in the box
    for(int r = startR; r < startR + 3; ++r) {
        for(int c = startC; c < startC + 3; ++c) {
            if(board[r][c] == n) return true;
        }
    }
    return false;
}

bool sudoSolver::isLegalPlacement(int row, int col, int value, int boardSize, vector<vector<int> > board) { // check if you can put a number
    return (!numberInColumn(boardSize, board, col, value) && !numberInRow(boardSize, board, row, value) && !numberInBox(board, (row - row % 3), (col - col % 3), value));
}

pair<int, int> sudoSolver::findUnassignedSlots(vector<vector<int> > &board) { // finds empty slots on the board
    pair<int, int> tmp;
    for(int r = 0; r < board.size(); ++r) {
        for(int c = 0; c < board.size(); ++c) {
            if(board[r][c] == 0) {
                tmp.first = r, tmp.second = c;
                return tmp;
            }
        }
    }
    tmp.first = -1, tmp.second = -1;
    return tmp;
}

int sudoSolver::countUnassignedSlots(vector<vector<int> > board) { // counts number of empty slots on the board
    int cnt = 0;
    for(int r = 0; r < board.size(); ++r) {
        for(int c = 0; c < board.size(); ++c) {
            if(board[r][c] == 0) {
                ++cnt;
            }
        }
    }
    return cnt;
}

bool sudoSolver::solveSudoku(const int boardSize, vector<vector<int> > &board, vector<int> allowedNums) { // Board includes sudoku puzzle with 0's in place of empty spots
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(std::begin(allowedNums), std::end(allowedNums), std::default_random_engine(seed));
    pair<int, int> check = findUnassignedSlots(board);
    if(check.first == -1 && check.second == -1) return true; // Sudoku is filled
    for(auto n : allowedNums) { // Loop through possible numbers
        if(isLegalPlacement(check.first, check.second, n, boardSize, board)) {
            board[check.first][check.second] = n;
            pair<int, int> end = findUnassignedSlots(board);
            if(solveSudoku(boardSize, board, allowedNums)) { // Backtracking here
                auto end = high_resolution_clock::now();
                return true;
            }
            board[check.first][check.second] = 0;
        }
    }
    return false;
}

int sudoSolver::isOneSolution(int row, int col, vector<vector<int> > board, int count, int boardSize) {
    if(row == 9) {
        row = 0;
        if (++col == boardSize)
            return count + 1;
    }
    if(board[row][col] != 0)
        return isOneSolution(row + 1, col, board, count, boardSize);
    for(int val = 1; val <= boardSize && count < 2; ++val) {
        if(isLegalPlacement(row, col, val, boardSize, board)) {
            board[row][col] = val;
            count = isOneSolution(row + 1, col, board, count, boardSize);
        }
    }
    board[row][col] = 0;
    return count;
}