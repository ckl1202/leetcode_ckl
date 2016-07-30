#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> need(300);
        vector<bool> flag(300);
        int num = t.size();
        for (int i = 0; i < t.size(); ++i){
            ++need[t[i]];
            flag[t[i]] = true;
        }
        int i;
        for (i = 0; i < s.size(); ++i){
            if (flag[s[i]]){
                --need[s[i]];
                if (need[s[i]] >= 0) --num;
                if (num == 0) break;
            }
        }
        if (num > 0) return "";
        int minLen = i + 1;
        string ans = s.substr(0, i + 1);
        int l = 0, r = i + 1;
        for (; l < s.size(); ++l){
            if (flag[s[l]]){
                if (r - l < minLen){
                    minLen = r - l;
                    ans = s.substr(l, r - l);
                }
                ++need[s[l]];
                if (need[s[l]] > 0){
                    while (r < s.size() && s[r] != s[l]){
                        if (flag[s[r]]){
                            --need[s[r]];
                        }
                        ++r;
                    }
                    if (r < s.size()){
                        --need[s[r]];
                        ++r;
                    }
                    if (r == s.size() && need[s[l]] != 0) break;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.minWindow("abc", "b");
    return 0;
}
