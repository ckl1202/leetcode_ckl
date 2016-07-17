#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int a[] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
        int sum = 1;
        for (int i = 0; i < digits.size(); ++i){
            sum *= a[digits[i] - '0'];
        }
        vector<string> ans;
        if (digits == "") return ans;
        ans.resize(sum);
        int times = 1;
        string letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 0; i < digits.size(); ++i){
            int num = digits[i] - '0';
            int pos = 0;
            sum /= a[num];
            for (int j = 0; j < times; ++j){
                for (int k = 0; k < letters[num].size(); ++k){
                    for (int p = 0; p < sum; ++p){
                        ans[pos] += letters[num][k];
                        ++pos;
                    }
                }
            }
            times *= a[num];
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> ans = s.letterCombinations("");
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i] << endl;
    }
    return 0;
}
