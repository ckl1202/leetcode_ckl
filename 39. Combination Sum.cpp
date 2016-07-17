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
            temp.push_back(candidates[i]);
            ans[candidates[i]].push_back(temp);
            temp.clear();
        }
        for (int i = 0; i < candidates.size(); ++i){
            for (int j = candidates[i] + 1; j <= target; ++j){
                for (int k = 0; k < ans[j - candidates[i]].size(); ++k){
                    vector<int> prevVec = ans[j - candidates[i]][k];
                    if (prevVec[prevVec.size() - 1] > candidates[i]) continue;
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
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(7);
    vector<vector<int> > ans = s.combinationSum(candidates, 7);
    for (int i = 0; i < ans.size(); ++i){
        for (int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
