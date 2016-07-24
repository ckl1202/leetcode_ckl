#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int m_max = -2147483648;
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            if (sum > m_max) m_max = sum;
            if (sum < 0) sum = 0;
        }
        return m_max;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    cout << s.maxSubArray(nums);
    return 0;
}
