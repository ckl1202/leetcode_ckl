#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == 'M') ans += 1000;
            if (s[i] == 'D') ans += 500;
            if (s[i] == 'C') ans += 100;
            if (s[i] == 'C' && i < s.size() - 1 && s[i + 1] == 'M') ans -= 200;
            if (s[i] == 'C' && i < s.size() - 1 && s[i + 1] == 'D') ans -= 200;
            if (s[i] == 'L')  ans += 50;
            if (s[i] == 'X') ans += 10;
            if (s[i] == 'X' && i < s.size() - 1 && s[i + 1] == 'C') ans -= 20;
            if (s[i] == 'X' && i < s.size() - 1 && s[i + 1] == 'L') ans -= 20;
            if (s[i] == 'V') ans += 5;
            if (s[i] == 'I') ans += 1;
            if (s[i] == 'I' && i < s.size() - 1 && s[i + 1] == 'X') ans -= 2;
            if (s[i] == 'I' && i < s.size() - 1 && s[i + 1] == 'V') ans -= 2;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.romanToInt("MDCCCLXXXVIII") << endl;
    return 0;
}
