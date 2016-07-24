#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i){
            while (nums[i] > 0 && nums[i] != i + 1){
                if (nums[i] - 1 >= nums.size()) break;
                int temp = nums[nums[i] - 1];
                if (temp == nums[i]) break;
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(4);
    //nums.push_back(1);
    //nums.push_back(1);
    //nums.push_back(2);
    cout << s.firstMissingPositive(nums);
    return 0;
}
