#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        //if (x == 0) return true;
        long long mi = 1;
        while (mi * 10 < x) mi *= 10;
        while (x != 0){
            int head = x / mi;
            int tail = x % 10;
            if (head != tail) return false;
            x = x % mi;
            x = x / 10;
            mi /= 100;
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.isPalindrome(13321);
    return 0;
}
