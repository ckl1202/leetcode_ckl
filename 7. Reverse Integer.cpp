#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int flag;
        if (x < 0){
            flag = -1;
            x = -x;
        }
        else flag = 1;
        long long newX = 0;
        while (x != 0 && x % 10 == 0) x /= 10;
        while (x != 0){
            newX = 10 * newX + x % 10;
            x /= 10;
        }
        newX *= flag;
        if (newX > 2147483647 || newX < -2147483648) newX = 0;
        return newX;
    }
};

int main(){
    Solution s;
    cout << s.reverse(-2147483647) << endl;
    return 0;
}
