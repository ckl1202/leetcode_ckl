#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<vector<int> > > ans;
        ans.resize(target + 1);
        vector<int> temp;
        for (int i = 0; i < candidates.size(); ++i){
            if (candidates[i] > target) break;
            if (i != 0 && candidates[i] == candidates[i - 1]) continue;
            temp.push_back(candidates[i]);
            ans[candidates[i]].push_back(temp);
            temp.clear();
        }
        for (int i = 0; i < candidates.size(); ++i){
            for (int j = target; j > candidates[i]; --j){
                for (int k = 0; k < ans[j - candidates[i]].size(); ++k){
                    vector<int> prevVec = ans[j - candidates[i]][k];
                    if (prevVec[prevVec.size() - 1] > candidates[i]) continue;
                    if (prevVec[prevVec.size() - 1] == candidates[i] && i > 0 && candidates[i] == candidates[i - 1]) continue;
                    prevVec.push_back(candidates[i]);
                    ans[j].push_back(prevVec);
                }
            }
        }
        return ans[target];
    }
};

int main(){
    Solution s;
    vector<int> candidates;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);
    vector<vector<int> > ans = s.combinationSum(candidates, 8);
    for (int i = 0; i < ans.size(); ++i){
        for (int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
