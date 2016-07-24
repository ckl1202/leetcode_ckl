#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int rm = nums[0];
        int pos = 1;
        while (pos <= rm){
            if (pos + nums[pos] > rm) rm = pos + nums[pos];
            if (rm >= nums.size() - 1) return true;
            ++pos;
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(4);
    cout << s.canJump(nums);
    return 0;
}
