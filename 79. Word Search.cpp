#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<bool>> flag;
    bool dfs(int i, int j, int depth, vector<vector<char>>& board, string& word){
        if (depth == word.size() - 1) return true;
        flag[i][j] = true;
        bool ans = false;
        if (i > 0 && board[i - 1][j] == word[depth + 1] && !flag[i - 1][j]) ans = ans || dfs(i - 1, j, depth + 1, board, word);
        if (i < board.size() - 1 && board[i + 1][j] == word[depth + 1] && !flag[i + 1][j]) ans = ans || dfs(i + 1, j, depth + 1, board, word);
        if (j > 0 && board[i][j - 1] == word[depth + 1] && !flag[i][j - 1]) ans = ans || dfs(i, j - 1, depth + 1, board, word);
        if (j < board[0].size() - 1 && board[i][j + 1] == word[depth + 1] && !flag[i][j + 1]) ans = ans || dfs(i, j + 1, depth + 1, board, word);
        flag[i][j] = false;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        if (board[0].size() == 0) return false;
        if (word == "") return true;
        flag.resize(board.size());
        for (int i = 0; i < board.size(); ++i){
            flag[i].resize(board[i].size());
        }
        for (int i = 0; i < board.size(); ++i){
            for (int j = 0; j < board[0].size(); ++j){
                if (board[i][j] == word[0]){
                    if (dfs(i, j, 0, board, word)) return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<char>> board;
    vector<char> temp;
    temp.push_back('A');
    temp.push_back('B');
    temp.push_back('C');
    temp.push_back('E');
    board.push_back(temp);
    temp[0] = 'S'; temp[1] = 'F'; temp[2] = 'C'; temp[3] = 'S';
    board.push_back(temp);
    temp[0] = 'A'; temp[1] = 'D'; temp[2] = 'E'; temp[3] = 'E';
    board.push_back(temp);
    cout << s.exist(board, "ABCB");
    return 0;
}
