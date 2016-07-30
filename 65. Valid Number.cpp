#include <ctype.h>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        enum InputType {
            INVALID, SPACE, SIGN, DOT, E, DIGIT, LEN
        };
        int trans[][LEN] = {
            {-1,  0,  1,  2, -1,  3},
            {-1, -1, -1,  2, -1,  3},
            {-1, -1, -1, -1, -1,  4},
            {-1,  5, -1,  4,  6,  3},
            {-1,  5, -1, -1,  6,  4},
            {-1,  5, -1, -1, -1, -1},
            {-1, -1,  7, -1, -1,  8},
            {-1, -1, -1, -1, -1,  8},
            {-1,  5, -1, -1, -1,  8}
        };
        int state = 0;
        int pos = 0;
        while (pos < s.size()) {
            InputType input;
            if (isspace(s[pos])) {
                input = SPACE;
            } else if (s[pos] == '+' || s[pos] == '-') {
                input = SIGN;
            } else if (s[pos] == '.') {
                input = DOT;
            } else if (s[pos] == 'e' || s[pos] == 'E') {
                input = E;
            } else if (isdigit(s[pos])) {
                input = DIGIT;
            } else {
                input = INVALID;
            }
            state = trans[state][input];
            if (state == -1) {
                return false;
            }
            ++pos;
        }
        return state == 3 || state == 4 || state == 5 || state == 8;
    }
};

int main(){
    Solution s;
    cout << s.isNumber("3");
}
