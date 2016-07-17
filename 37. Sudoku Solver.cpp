#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
private:
    bool canRow[10][10];
    bool canCol[10][10];
    bool canBlock[10][10];
    bool dfs(int row, int col, vector<vector<char> >&board){
        if (row == 9) return true;
        int nextRow = row, nextCol = col + 1;
        if (nextCol == 9){
            nextCol = 0;
            nextRow++;
        }
        if (board[row][col] != '.'){
            return dfs(nextRow, nextCol, board);
        }
        for (int i = 1; i <= 9; ++i){
            int indexBlock = 3 * (row / 3) + (col / 3);
            if (canRow[row][i] && canCol[col][i] && canBlock[indexBlock][i]){
                canRow[row][i] = false;
                canCol[col][i] = false;
                canBlock[indexBlock][i] = false;
                board[row][col] = i + '0';

                bool b_find = dfs(nextRow, nextCol, board);

                canRow[row][i] = true;
                canCol[col][i] = true;
                canBlock[indexBlock][i] = true;
                if (b_find) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char> >& board) {
        for (int i = 0; i < 9; ++i){
            for (int j = 1; j <= 9; ++j){
                canRow[i][j] = true;
                canCol[i][j] = true;
                canBlock[i][j] = true;
            }
        }
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 9; ++j){
                if (board[i][j] != '.'){
                    int digit = board[i][j] - '0';
                    canRow[i][digit] = false;
                    canCol[j][digit] = false;
                    int indexBlock= 3 * (i / 3) + (j / 3);
                    canBlock[indexBlock][digit] = false;
                }
            }
        }
        dfs(0, 0, board);
        return;
    }
};

int main(){
    Solution s;
    vector<char> temp;
    vector<vector<char> >board;
    for (int i = 0; i < 9; ++i){
        temp.clear();
        for (int j = 0; j < 9; ++j){
            char ch = cin.get();
            temp.push_back(ch);
        }
        board.push_back(temp);
        cin.get();
    }
    s.solveSudoku(board);
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            cout << board[i][j];
        }
        cout << endl;
    }
    return 0;
}
