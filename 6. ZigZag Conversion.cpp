#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) return s;
        string ans;
        for (int i = 0; i < numRows; ++i){
            int pos = i;
            int direction = 0;//0 : down; 1 : up
            if (i == numRows - 1) direction = 1;
            while (pos < s.size()){
                ans += s[pos];
                if (direction == 0){
                    pos += (numRows - i) * 2 - 2;
                }
                else{
                    pos += i * 2;
                }
                direction = 1 - direction;
                if (i == 0) direction = 0;
                if (i == numRows - 1) direction = 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.convert("A", 1);
    return 0;
}
