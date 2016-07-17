#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.size();
        string newP = "";
        vector<bool> haveStar;
        for (int i = 0; i < p.size(); ++i){
            if (p[i] == '*') continue;
            newP += p[i];
            if (i == p.size() - 1 || p[i + 1] != '*'){
                haveStar.push_back(false);
            }
            if (i != p.size() - 1 && p[i + 1] == '*')
                haveStar.push_back(true);
        }
        int l2 = newP.size();
        //if (l1 == 0 && l2 == 0) return false;
        if (l1 == 0){
            for (int i = 0; i < l2; ++i){
                if (!haveStar[i]) return false;
            }
            return true;
        }
        if (l2 == 0) return false;
        vector<vector<bool> > match;
        match.resize(l1 + 1);
        for (int i = 0; i <= l1; ++i){
            match[i].resize(l2 + 1);
        }
        match[0][0] = true;
        int nextJ = 0;
        while (nextJ < l2 && haveStar[nextJ]){
            match[0][++nextJ] = true;
        }
        for (int i = 1; i <= l1; ++i){
            for (int j = 1; j <= l2; ++j){
                if (match[i - 1][j - 1] && (s[i - 1] == newP[j - 1] || newP[j - 1] == '.'))
                    match[i][j] = true;
                if (haveStar[j - 1]){
                    if (match[i][j - 1]) match[i][j] = true;
                    if (match[i - 1][j] && (s[i - 1] == newP[j - 1] || newP[j - 1] == '.'))
                        match[i][j] = true;
                }
            }
        }
        return match[l1][l2];
    }
};

int main(){
    Solution s;
    cout << s.isMatch("abcd", "d*");
    return 0;
}
