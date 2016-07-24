#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n);
        for (int i = 0; i < n; ++i) ans[i].resize(n);
        int up = 0, down = n - 1, left = 0, right = n - 1;
        int x = 0, y = 0;
        int dx = 0, dy = 1;
        for (int i = 1; i <= n * n; ++i){
            ans[x][y] = i;
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
    vector<vector<int> > ans = s.generateMatrix(5);
    for (int i = 0 ; i < ans.size(); ++i){
        for (int j = 0; j < ans.size(); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
