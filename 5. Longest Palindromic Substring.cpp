#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    string longestPalindrome(string s) {
        if (s == "") return "";
        vector<char> str;
        str.push_back('#');
        for (int i = 0; i < s.size(); ++i){
            str.push_back(s[i]);
            str.push_back('#');
        }
        int rightmost = 0;
        int pos;
        vector<int> length;
        length.resize(str.size());
        for (int i = 1; i < str.size(); ++i){
            if (rightmost > i){
                length[i] = min(rightmost - i, length[2 * pos - i]);
            }
            else{
                length[i] = 1;
            }
            for (; i >= length[i] && str[i + length[i]] == str[i - length[i]]; ++length[i])
            if (length[i] + i > rightmost){
                rightmost = length[i] + i;
                pos = i;
            }
        }
        pos = 0;
        for (int i = 0; i < length.size(); ++i){
            if (length[i] > length[pos]) pos = i;
        }
        string ans = "";
        int len = length[pos] - 1;
        if (str[pos] != '#') ans += str[pos];
        for (int i = 0; i < len; ++i){
            ++pos;
            if (str[pos] != '#') ans = str[pos] + ans + str[pos];
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.longestPalindrome("aacba");
    return 0;
}
