#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int depth, int n, vector<int>&nums){
        if (depth == n){
            ans.push_back(temp);
            return;
        }
        dfs(depth + 1, n, nums);
        temp.push_back(nums[depth]);
        dfs(depth + 1, n, nums);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums.size(), nums);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    for (int i = 1; i <= 3; ++i) nums.push_back(i);
    vector<vector<int>> ans = s.subsets(nums);
    for (int i = 0; i < ans.size(); ++i){
        for (int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
