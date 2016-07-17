#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int pos = -1;
        if (nums[0] >= nums[nums.size() - 1]){
            int l = 0, r = nums.size() - 1;
            while (l <= r){
                int mid = (l + r) >> 1;
                if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1]){
                    pos = mid;
                    break;
                }
                if (nums[mid] >= nums[l]) l = mid + 1;
                else r = mid - 1;
            }
        }
        int l = 0, r = pos;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        l = pos + 1, r = nums.size() - 1;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> nums;
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    //nums.push_back(6);
    //nums.push_back(7);
    cout << s.search(nums, 9);
    return 0;
}
