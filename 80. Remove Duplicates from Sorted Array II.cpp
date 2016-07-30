#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int num = 1;
        int previous = nums[0];
        int times = 1;
        for (int i = 1; i < nums.size(); ++i){
            if (nums[i] != previous || times < 2){
                nums[num] = nums[i];
                if (nums[i] == previous) times = 2;
                else times = 1;
                previous = nums[i];
                ++num;
            }
        }
        return num;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    int ans = s.removeDuplicates(nums);
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) cout << nums[i] << ' ';
    return 0;
}
