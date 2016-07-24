#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<bool> col;
    vector<bool> diagonal;
    vector<bool> diagonal2;
    int ans;

    void dfs(int depth, int n){
        if (depth == n){
            ++ans;
            return;
        }
        for (int i = 0; i < n; ++i){
            if (!col[i] && !diagonal[depth + i] && !diagonal2[i - depth + n - 1]){
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
    int totalNQueens(int n) {
        col.resize(n);
        diagonal.resize(n << 1);
        diagonal2.resize(n << 1);
        ans = 0;
        dfs(0, n);
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.totalNQueens(4);
    return 0;
}
