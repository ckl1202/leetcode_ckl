#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; ++i){
            string temp;
            char prev = ans[0];
            int j = 1;
            int n_count = 1;
            while (j < ans.size()){
                if (ans[j] == prev) ++n_count;
                else{
                    char str[100];
                    sprintf(str, "%d", n_count);
                    temp += str;
                    temp += prev;
                    prev = ans[j];
                    n_count = 1;
                }
                ++j;
            }
            char str[10];
            sprintf(str, "%d", n_count);
            temp += str;
            temp += prev;
            ans = temp;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.countAndSay(5);
    return 0;
}
