#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int starPos = -2;
        int sPos = -2;
        while (i < s.size()){
            if (j < p.size() && (s[i] == p[j] || p[j] == '?')){
                ++i;
                ++j;
                continue;
            }
            if (j < p.size() && p[j] == '*'){
                starPos = j;
                sPos = i;
                ++j;
                continue;
            }
            if (starPos != -1){
                j = starPos + 1;
                i = sPos + 1;
                ++sPos;
                continue;
            }
            return false;
        }
        while (j < p.size() && p[j] == '*') ++j;
        if (j == p.size()) return true;
        else return false;
    }
};

int main(){
    Solution s;
    cout << s.isMatch("aa", "*");
    return 0;
}
