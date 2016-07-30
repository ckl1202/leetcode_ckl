#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroLast = -1, oneLast = -1;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] == 0){
                ++zeroLast;
                if (zeroLast > oneLast) ++oneLast;
                int temp = nums[zeroLast];
                nums[zeroLast] = 0;
                nums[i] = temp;
            }
            if (nums[i] == 1){
                ++oneLast;
                int temp = nums[oneLast];
                nums[oneLast] = 1;
                nums[i] = temp;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(0);
    for (int i = 0; i < nums.size(); ++i) cout << nums[i] << ' ';
    cout << endl;
    s.sortColors(nums);
    for (int i = 0; i < nums.size(); ++i) cout << nums[i] << ' ';
    return 0;
}
