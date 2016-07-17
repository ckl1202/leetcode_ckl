#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (haystack == "") return -1;

        vector<int> p;
        int j = -1;
        p.push_back(-1);
        for (int i = 1; i < needle.size(); ++i){
            while (j > -1 && needle[i] != needle[j + 1]) j = p[j];
            if (needle[j + 1] == needle[i]) ++j;
            p.push_back(j);
        }
        j = -1;
        for (int i = 0; i < haystack.size(); ++i){
            while (j > -1 && haystack[i] != needle[j + 1]) j = p[j];
            if (haystack[i] == needle[j + 1]) ++j;
            if (j == needle.size() - 1) return i - needle.size() + 1;
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout << s.strStr("bacacbc", "abc");
    return 0;
}
