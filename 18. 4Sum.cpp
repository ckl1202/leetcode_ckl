#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; ++j){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = nums.size() - 1;
                while (l < r){
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[l]);
                        temp.push_back(nums[r]);
                        if (ans.size() == 0 || temp != ans[ans.size() - 1]){
                            ans.push_back(temp);
                        }
                    }
                    if (sum >= target){
                        --r;
                        while (r > l + 1 && nums[r + 1] == nums[r]) --r;
                    }
                    else{
                        ++l;
                        while (r > l + 1 && nums[l - 1] == nums[l]) ++l;
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(-2);
    nums.push_back(2);
    nums.push_back(-2);
    vector<vector<int> > ans = s.fourSum(nums, 0);
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << ' ' << ans[i][3] << endl;
    }
    return 0;
}
