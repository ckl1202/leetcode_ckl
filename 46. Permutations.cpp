#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int> > ans;
    vector<int> temp;
    vector<bool> used;
    void dfs(int depth, int n, vector<int>& nums){
        if (depth == n){
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; ++i){
            if (!used[i]){
                used[i] = true;
                temp[depth] = nums[i];
                dfs(depth + 1, n, nums);
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int> > permute(vector<int>& nums) {
        temp.resize(nums.size());
        used.resize(nums.size());
        dfs(0, nums.size(), nums);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    vector<vector<int> > ans = s.permute(nums);
    for (int i = 0; i < ans.size(); ++i){
        for (int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
