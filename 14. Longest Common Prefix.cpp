#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string ans = strs[0];
        for (int i = 1; i < strs.size(); ++i){
            string temp = "";
            int j = 0;
            while (j < ans.size() && j < strs[i].size() && ans[j] == strs[i][j]){
                temp += ans[j];
                ++j;
            }
            ans = temp;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> strs;
    strs.push_back("abda");
    strs.push_back("abd");
    strs.push_back("abc");
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
