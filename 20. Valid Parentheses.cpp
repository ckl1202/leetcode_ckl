#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> a;
        for (int i = 0; i < s.size(); ++i){
            int num;
            if (s[i] == '(') num = 1;
            if (s[i] == ')') num = -1;
            if (s[i] == '{') num = 2;
            if (s[i] == '}') num = -2;
            if (s[i] == '[') num = 3;
            if (s[i] == ']') num = -3;
            if (num > 0){
                a.push(num);
            }
            else{
                if (a.empty() || a.top() + num != 0) return false;
                a.pop();
            }
        }
        if (a.empty()) return true;
        else return false;
    }
};

int main(){
    Solution s;
    cout << s.isValid("([)]");
    return 0;
}
