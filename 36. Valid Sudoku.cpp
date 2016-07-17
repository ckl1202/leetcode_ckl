#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        bool flag[10];
        for (int i = 0; i < 9; ++i){
            memset(flag, 0, sizeof(flag));
            for (int j = 0; j < 9; ++j){
                if (board[i][j] != '.'){
                    int digit = board[i][j] - '0';
                    if (flag[digit]) return false;
                    flag[digit] = true;
                }
            }
        }
        for (int j = 0; j < 9; ++j){
            memset(flag, 0, sizeof(flag));
            for (int i = 0; i < 9; ++i){
                if (board[i][j] != '.'){
                    int digit = board[i][j] - '0';
                    if (flag[digit]) return false;
                    flag[digit] = true;
                }
            }
        }
        for (int i = 0; i < 9; i += 3){
            for (int j = 0; j < 9; j += 3){
                memset(flag, 0, sizeof(flag));
                for (int ii = i; ii < i + 3; ++ii){
                    for (int jj = j; jj < j + 3; ++jj){
                        if (board[ii][jj] != '.'){
                            int digit = board[ii][jj] - '0';
                            if (flag[digit]) return false;
                            flag[digit] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
