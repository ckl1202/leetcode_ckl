#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int tail = nums.size();
        int i = 0;
        while (i < tail){
            if (nums[i] != val) ++i;
            else{
                nums[i] = nums[--tail];
            }
        }
        return i;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    int length = s.removeElement(nums, 3);
    cout << length;
    for (int i = 0; i < length; ++i) cout << nums[i] << ' ';
    return 0;
}
