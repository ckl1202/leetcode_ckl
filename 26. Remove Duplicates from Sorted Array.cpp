#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int nextPos = 0;
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] != nums[nextPos]) nums[++nextPos] = nums[i];
        }
        return ++nextPos;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    cout << s.removeDuplicates(nums);
    return 0;
}
