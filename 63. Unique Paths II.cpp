#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        vector<vector<int> > ans(m);
        int n = obstacleGrid[0].size();
        for (int i = 0; i < m; ++i) ans[i].resize(n);
        ans[0][0] = 1;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (i > 0) ans[i][j] += ans[i - 1][j];
                if (j > 0) ans[i][j] += ans[i][j - 1];
                if (obstacleGrid[i][j] == 1) ans[i][j] = 0;
            }
        }
        return ans[m - 1][n - 1];
    }
};

int main(){
    Solution s;
    vector<vector<int> > _map;
    _map.resize(3);
    for (int i = 0; i < 3; ++i) _map[i].resize(3);
    _map[1][1] = 1;
    cout << s.uniquePathsWithObstacles(_map);
    return 0;
}
