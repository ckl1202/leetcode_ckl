#include <iostream>
using namespace std;

class Solution {
public:
    double power(double x, int n){
        if (n == 0){
            return 1;
        }
        double v = power(x, n / 2);
        if (n % 2 == 0){
            return v * v;
        }
        else{
            return v * v * x;
        }
    }

    double myPow(double x, int n) {
        if (n < 0){
            return 1.0 / power(x, -n);
        }
        else{
            return power(x, n);
        }
    }
};

int main(){
    Solution s;
    cout << s.myPow(2, 0);
    return 0;
}
