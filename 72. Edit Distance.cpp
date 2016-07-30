#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();
        vector<vector<int>> f(word1.size() + 1);
        for (int i = 0; i <= word1.size(); ++i){
            f[i].resize(word2.size() + 1);
        }
        for (int i = 0; i <= word2.size(); ++i){
            f[0][i] = i;
        }
        for (int i = 0; i <= word1.size(); ++i){
            f[i][0] = i;
        }
        for (int i = 1; i <= word1.size(); ++i){
            for (int j = 1; j <= word2.size(); ++j){
                int _min = 2147483647;
                if (word1[i - 1] == word2[j - 1] && f[i - 1][j - 1] < _min) _min = f[i - 1][j - 1];
                if (f[i - 1][j] + 1 < _min) _min = f[i - 1][j] + 1;
                if (f[i][j - 1] + 1 < _min) _min = f[i][j - 1] + 1;
                if (f[i - 1][j - 1] + 1 < _min) _min = f[i - 1][j - 1] + 1;
                f[i][j] = _min;
            }
        }
        return f[word1.size()][word2.size()];
    }
};

int main(){
    Solution s;
    cout << s. minDistance("aaa", "bbbb");
    return 0;
}
