#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > hashMap;
        for (auto &v : strs){
            string temp(v);
            sort(temp.begin(), temp.end());
            hashMap[temp].push_back(v);
        }
        vector<vector<string> > ans(hashMap.size());
        int k = 0;
        for (auto it = hashMap.begin(); it != hashMap.end(); ++it, ++k){
            ans[k].swap(it->second);
            sort(ans[k].begin(), ans[k].end());
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    vector<vector<string> > ans = s.groupAnagrams(strs);
    for (int i = 0; i < ans.size(); ++i){
        for (int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
