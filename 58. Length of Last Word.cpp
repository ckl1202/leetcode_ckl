#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = s.size() - 1;
        while (pos >= 0 && s[pos] == ' ') --pos;
        int num = 0;
        while (pos >= 0 && s[pos] != ' '){
            ++num;
            --pos;
        }
        return num;
    }
};

int main(){
    Solution s;
    cout << s.lengthOfLastWord("Hello World") << endl;
    return 0;
}
