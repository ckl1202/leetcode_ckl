#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        if (matrix[0].size() == 0) return ans;

        int n = matrix.size();
        int m = matrix[0].size();
        int total = n * m;

        int up = 0, down = n - 1, left = 0, right = m - 1;
        int x = 0, y = 0;
        int dx = 0, dy = 1;

        for (int i = 0; i < total; ++i){
            ans.push_back(matrix[x][y]);
            if (dx == 0 && dy == 1 && y == right){
                ++up;
                dx = 1; dy = 0;
            }
            if (dx == 1 && dy == 0 && x == down){
                --right;
                dx = 0; dy = -1;
            }
            if (dx == 0 && dy == -1 && y == left){
                --down;
                dx = -1; dy = 0;
            }
            if (dx == -1 && dy == 0 && x == up){
                ++left;
                dx = 0; dy = 1;
            }
            x += dx; y += dy;
        }
        return ans;
    }
};

int main(){
    Solution s;
    int n = 3, m = 5;
    vector<vector<int> > matrix(n);
    for (int i = 0; i < n; ++i) matrix[i].resize(m);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            matrix[i][j] = i * m + j + 1;
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    vector<int> ans = s.spiralOrder(matrix);
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    return 0;
}
