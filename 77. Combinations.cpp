#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> temp;
    vector<vector<int>> ans;
    void dfs(int depth, int pos, int n, int k){
        if (depth == k){
            ans.push_back(temp);
            return;
        }
        for (int i = pos; i < n; ++i){
            temp[depth] = i + 1;
            dfs(depth + 1, i + 1, n, k);
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        temp.resize(k);
        dfs(0, 0, n, k);
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> ans = s.combine(4, 2);
    for (int i = 0; i < ans.size(); ++i){
        for (int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
