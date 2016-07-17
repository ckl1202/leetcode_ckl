#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        bool flag = false;
        for (int i = nums.size() - 2; i >= 0; --i){
            if (nums[i] < nums[i + 1]){
                flag = true;
                int temp = nums[i];
                int pos = i + 1;
                while (pos < nums.size() - 1 && nums[pos + 1] > nums[i]) ++pos;
                nums[i] = nums[pos];
                nums[pos] = temp;
                sort(nums.begin() + i + 1, nums.end());
                break;
            }
        }
        if (!flag){
            sort(nums.begin(), nums.end());
        }
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    s.nextPermutation(nums);
    for (int i = 0; i < nums.size(); ++i) cout << nums[i] << ' ';
    return 0;
}
