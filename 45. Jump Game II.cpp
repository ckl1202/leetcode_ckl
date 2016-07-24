#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int l = 0, r = 0, ans = 0;
        for (; r < nums.size() - 1; ++ans){
            int tempL = r + 1, tempR = r + 1;
            for (int i = l; i <= r; ++i){
                if (i + nums[i] > tempR) tempR = i + nums[i];
            }
            l = tempL; r = tempR;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(6);
    cout << s.jump(nums);
    return 0;
}
