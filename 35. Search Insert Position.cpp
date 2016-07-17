#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r){
            mid = (l + r) >> 1;
            if (nums[mid] == target) break;
            if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        if (nums[mid] < target) ++mid;
        return mid;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    cout << s.searchInsert(nums, 5) << ' ';
    cout << s.searchInsert(nums, 2) << ' ';
    cout << s.searchInsert(nums, 7) << ' ';
    cout << s.searchInsert(nums, 0) << ' ';
    return 0;
}
