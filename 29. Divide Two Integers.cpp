#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return 2147483647;
        if (dividend == -2147483648 && divisor == -1) return 2147483647;
        if (dividend == -2147483648 && divisor == -2147483648) return 1;
        if (divisor == -2147483648) return 0;
        bool isfMax = false;
        if (dividend == -2147483648){
            isfMax = true;
            if (divisor > 0) dividend += divisor;
            else dividend -= divisor;
        }

        int sign = 1;
        if (dividend < 0){
            dividend = -dividend;
            sign = -sign;
        }
        if (divisor < 0){
            divisor = -divisor;
            sign = -sign;
        }
        vector<int> num;
        //vector<int> ans;
        bool flag = true;
        long long lastnum = divisor;
        num.push_back(divisor);
        while (flag){
            flag = false;
            long long temp1 = lastnum << 3;
            long long temp2 = lastnum << 1;
            long long temp = temp1 + temp2;
            if (temp <= dividend){
                flag = true;
                num.push_back(temp);
                lastnum = temp;
            }
        }
        int ans = 0;
        for (int i = num.size() - 1; i >= 0; --i){
            int temp1 = ans << 3;
            int temp2 = ans << 1;
            ans = temp1 + temp2;
            while (dividend >= num[i]){
                dividend -= num[i];
                ++ans;
            }
        }
        ans = sign * ans;
        if (isfMax){
            if (sign > 0) ++ans;
            else --ans;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.divide(-2147483648, -2);
    return 0;
}
