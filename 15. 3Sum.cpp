#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        if (nums.size() < 3) return ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    if (ans.size() == 0 || temp != ans[ans.size() - 1]){
                        ans.push_back(temp);
                    }
                }
                if (sum >= 0) --r;
                else ++l;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);
    vector<vector<int> > ans = s.threeSum(nums);
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;
    }
    return 0;
}
