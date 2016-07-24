#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> temp;
    vector<vector<int> > ans;
    vector<bool> used;
    void dfs(int depth, int pos, int n, vector<int>& nums){
        if (depth == n){
            ans.push_back(temp);
            return;
        }
        if (depth > 0 && nums[depth] != nums[depth - 1]){
            pos = 0;
        }
        for (int i = pos; i < n; ++i){
            if (used[i]) continue;
            used[i] = true;
            temp[i] = nums[depth];
            dfs(depth + 1, i + 1, n, nums);
            used[i] = false;
        }
    }

public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        temp.resize(nums.size());
        used.resize(nums.size());
        dfs(0, 0, nums.size(), nums);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    vector<vector<int> > ans = s.permuteUnique(nums);
    for (int i = 0; i < ans.size(); ++i){
        for (int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
