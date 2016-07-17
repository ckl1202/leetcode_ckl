#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        if (s.size() == 1) return 1;
        int l = 0, r = s.size();
        int mmax = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            vector<int> nums;
            nums.resize(200);
            int repeatNums = 0;
            for (int i = 0; i < mid; ++i){
                nums[s[i]] += 1;
                if (nums[s[i]] == 2){
                    repeatNums++;
                }
            }
            bool flag = false;
            if (repeatNums == 0) flag = true;
            for (int i = 1; i < s.size() - mid + 1; ++i){
                nums[s[i - 1]]--;
                if (nums[s[i - 1]] == 1) --repeatNums;
                nums[s[i + mid - 1]]++;
                if (nums[s[i + mid - 1]] == 2) ++repeatNums;
                if (repeatNums == 0) flag = true;
            }
            if (flag){
                l = mid + 1;
                if (mid > mmax) mmax = mid;
            }
            else r = mid - 1;
        }
        return mmax;
    }
};

int main(){
    Solution s;
    cout << s.lengthOfLongestSubstring("pwwkew");
    return 0;
}
