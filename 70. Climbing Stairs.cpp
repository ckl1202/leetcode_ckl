#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int a = 1, b = 1, c;
        for (int i = 2; i <= n; ++i){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main(){
    Solution s;
    cout << s.climbStairs(3);
    return 0;
}
