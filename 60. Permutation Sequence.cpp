#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int base = 1;
        for (int i = 1; i <= n; ++i){
            base *= i;
        }
        --k;
        string ans;
        vector<int> used(n + 1);
        for (int i = n; i > 0; --i){
            base /= i;
            int digit = k / base + 1;
            int num = 0;
            for (int j = 1; j <= n; ++j){
                if (!used[j]) ++num;
                if (num == digit){
                    used[j] = true;
                    ans += char('0' + j);
                    break;
                }
            }
            k %= base;
        }
        return ans;
    }
};

int main(){
    Solution s;
    for (int i = 1; i <= 24; ++i) cout << s.getPermutation(4, i) << endl;
    return 0;
}
