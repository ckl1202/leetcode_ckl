#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> ans;
        if (nums.size() == 0) return ans;
        for (int i = 0; i < nums.size() - 1; ++i){
            for (int j = i + 1; j < nums.size(); ++j){
                if (nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    //nums.push_back(15);
    vector<int> ans = s.twoSum(nums, 6);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
