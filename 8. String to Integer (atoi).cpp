#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        bool flag = false;
        vector<bool> isValid;
        isValid.resize(str.size());
        for (int i = 0; i < str.size(); ++i){
            if (str[i] == ' ') continue;
            if (str[i] >= '0' && str[i] <= '9'){
                flag = true;
                isValid[i] = true;
                continue;
            }
            if (flag) break;
            if (str[i] == '-' || str[i] == '+') {
                if (!flag) isValid[i] = true;
                flag = true;
            }

        }
        string temp = str;
        str = "";
        flag = false;
        for (int i = 0; i < temp.size(); ++i){
            if (!isValid[i] && !flag && temp[i] != ' ')return 0;
            if (isValid[i]){
                str += temp[i];
                flag = true;
            }
            if (flag && !isValid[i]) break;
        }
        if (str.size() == 0) return 0;
        if (str[0] != '-' && str[0] != '+' && str[0] < '0' && str[1] > '9') return 0;
        if (!flag) return 0;
        int sign = 1;
        for (int i = 0; i < str.size(); ++i){
            if (str[i] == '-') sign = -sign;
        }
        long long ans = 0;

        flag = false;
        for (int i = 0; i < str.size(); ++i){
            if (str[i] < '0' || str[i] > '9') continue;
            if (!flag && i >= 2) return 0;
            flag = true;
            ans = ans * 10 + str[i] - '0';
            if (1 == sign && ans > 2147483647) return 2147483647;
            if (-1 == sign && ans > 2147483648) return -2147483648;
        }
        ans *= sign;
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.myAtoi("   +0 123") << endl;
    return 0;
}
