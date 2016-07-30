#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        vector<vector<int>> ans(m);
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) ans[i].resize(n);
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (i != 0 || j != 0){
                    int _min = 2147483647;
                    if (i > 0) _min = ans[i - 1][j];
                    if (j > 0 && ans[i][j - 1] < _min) _min = ans[i][j - 1];
                    ans[i][j] = _min + grid[i][j];
                }
                else ans[i][j] = grid[0][0];
            }
        }

        return ans[m - 1][n - 1];
    }
};

int main(){
    cout << 01100;
}
