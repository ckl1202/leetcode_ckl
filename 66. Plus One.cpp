#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int flag = false;
        for (int i = 0; i < digits.size(); ++i){
            if (digits[i] != 9){
                flag = true;
                break;
            }
        }
        if (!flag){
            ans.push_back(1);
            for (int i = 0; i < digits.size(); ++i) ans.push_back(0);
            return ans;
        }
        ans = digits;
        int i;
        for (i = digits.size() - 1; i >= 0; --i){
            if (ans[i] == 9){
                ans[i] = 0;
            }
            else{
                ++ans[i];
                break;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> digits;
    //digits.push_back(9);
    //digits.push_back(9);
    //digits.push_back(9);
    vector<int> ans = s.plusOne(digits);
    for (int i = 0; i < ans.size(); ++i) cout << ans[i];
    return 0;
}
