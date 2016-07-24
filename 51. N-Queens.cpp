#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<bool> col;
    vector<bool> diagonal;
    vector<bool> diagonal2;
    vector<int> pos;
    vector<vector<int> > ans;

    void dfs(int depth, int n){
        if (depth == n){
            ans.push_back(pos);
            return;
        }
        for (int i = 0; i < n; ++i){
            if (!col[i] && !diagonal[depth + i] && !diagonal2[i - depth + n - 1]){
                pos[depth] = i;
                col[i] = true;
                diagonal[depth + i] = true;
                diagonal2[i - depth + n - 1] = true;
                dfs(depth + 1, n);
                col[i] = false;
                diagonal[depth + i] = false;
                diagonal2[i - depth + n - 1] = false;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        col.resize(n);
        diagonal.resize(n << 1);
        diagonal2.resize(n << 1);
        pos.resize(n);
        dfs(0, n);
        string temp;
        for (int i = 0; i < n; ++i) temp += '.';
        vector<string> matrix;
        for (int i = 0; i < n; ++i) matrix.push_back(temp);
        vector<vector<string> > matrixAns;
        for (int i = 0; i < ans.size(); ++i){
            for (int j = 0; j < n; ++j){
                matrix[j][ans[i][j]] = 'Q';
            }
            matrixAns.push_back(matrix);
            for (int j = 0; j < n; ++j){
                matrix[j][ans[i][j]] = '.';
            }
        }
        return matrixAns;
    }
};

int main(){
    Solution s;
    vector<vector<string> > ans = s.solveNQueens(4);
    for (int i = 0; i < ans.size(); ++i){
        for (int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << endl;
        }
        cout << endl;
    }
    return 0;
}
