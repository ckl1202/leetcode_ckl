#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<string> ans;
    string temp;
    void dfs(int n, int nChar, int nLeft){
        if (nChar == n << 1){
            if (nLeft == 0) ans.push_back(temp);
            return;
        }
        if (nLeft < n){
            temp += '(';
            dfs(n, nChar + 1, nLeft + 1);
            temp.erase(nChar);
        }
        if (nLeft > 0){
            temp += ')';
            dfs(n, nChar + 1, nLeft - 1);
            temp.erase(nChar);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, 0, 0);
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> ans = s.generateParenthesis(3);
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i] << endl;
    }
    return 0;
}
