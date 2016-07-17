#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        if (nums.size() == 0) return ans;
        if (nums[0] == target) ans[0] = 0;
        else{
            int l = 1, r = nums.size() - 1;
            while (l <= r){
                int mid = (l + r) >> 1;
                if (nums[mid] == target && nums[mid] > nums[mid - 1]){
                    ans[0] = mid;
                    break;
                }
                if (nums[mid] < target) l = mid + 1;
                else r = mid - 1;
            }
        }
        if (nums[nums.size() - 1] == target) ans[1] = nums.size() - 1;
        else{
            int l = 0, r = nums.size() - 2;
            while (l <= r){
                int mid = (l + r) >> 1;
                if (nums[mid] == target && nums[mid] < nums[mid + 1]){
                    ans[1] = mid;
                    break;
                }
                if (nums[mid] > target) r = mid - 1;
                else l = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    vector<int> ans = s.searchRange(nums, 10);
    cout << ans[0] << ' ' << ans[1] << endl;
    return 0;
}
