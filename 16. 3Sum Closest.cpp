#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int minOffset = 2147483647;
        int closest;
        for (int i = 0; i < nums.size() - 2; ++i){
            int l = i + 1, r = nums.size() - 1;
            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                int offset = max(sum, target) - min(sum, target);
                if (offset < minOffset){
                    minOffset = offset;
                    closest = sum;
                }
                if (sum > target) --r;
                else ++l;
            }
        }
        return closest;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-4);
    cout << s.threeSumClosest(nums, 2);
    return 0;
}
