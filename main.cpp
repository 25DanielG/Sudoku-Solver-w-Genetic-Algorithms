#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::cin;
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

}