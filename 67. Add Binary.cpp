#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "" && b == "") return "0";
        int pa = a.size() - 1;
        int pb = b.size() - 1;
        int carry = 0;
        string ans = "";
        while (pa >= 0 || pb >= 0){
            if (pa >= 0) carry += a[pa] - '0';
            if (pb >= 0) carry += b[pb] - '0';
            ans = char(carry % 2 + '0') + ans;
            carry >>= 1;
            --pa; --pb;
        }
        if (carry != 0) ans = "1" + ans;
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.addBinary("", "");
    return 0;
}
