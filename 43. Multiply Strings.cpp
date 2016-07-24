#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "" || num2 == "") return "";

        int sign = 1;
        vector<int> ans;
        ans.resize(num1.size() + num2.size() + 1);

        for (int i = 0; i < num1.size(); ++i)
            if (num1[i] == '-') sign = -sign;
        for (int i = 0; i < num2.size(); ++i)
            if (num2[i] == '-') sign = -sign;

        for (int i = 0; i < num1.size() >> 1; ++i){
            char temp = num1[i];
            num1[i] = num1[num1.size() - i - 1];
            num1[num1.size() - i - 1] = temp;
        }
        for (int i = 0; i < num2.size() >> 1; ++i){
            char temp = num2[i];
            num2[i] = num2[num2.size() - i - 1];
            num2[num2.size() - i - 1] = temp;
        }

        for (int i = 0; i < num1.size(); ++i){
            if (num1[i] == '-') continue;
            for (int j = 0; j < num2.size(); ++j){
                if (num2[j] == '-') continue;
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int pos = i + j;
                while (mul > 0){
                    ans[pos] += mul;
                    mul = ans[pos] / 10;
                    ans[pos] %= 10;
                    ++pos;
                }
            }
        }
        int pos = num1.size() + num2.size();
        while (ans[pos] == 0) --pos;
        string strAns;
        if (sign == -1) strAns = "-";
        for (int i = pos; i >= 0; --i){
            strAns += char(ans[i] + '0');
        }
        if (strAns == "" || strAns == "-") strAns = "0";
        return strAns;
    }
};

int main(){
    Solution s;
    cout << s.multiply("999", "-999");
    return 0;
}
