#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        map<string, int> total;
        map<string, int> had;

        int diffNum = 0;

        for (int i = 0; i < words.size(); ++i){
            ++total[words[i]];
            if (total[words[i]] == 1) ++diffNum;
        }

        int wordLen = words[0].size();
        int wordNum = words.size();
        int sLen = s.size();
        int loopEnd = sLen - wordLen * wordNum;
        int subLen = wordLen * wordNum;
        for (int i = 0; i < wordLen; ++i){
            had.clear();
            int invalid = diffNum;
            if (i + subLen > sLen) break;
            for (int j = 0; j < wordNum; ++j){
                string subStr = s.substr(i + j * wordLen, wordLen);
                if (total[subStr] == had[subStr]) ++invalid;
                if (total[subStr] == ++had[subStr]) --invalid;
            }
            if (invalid == 0) ans.push_back(i);
            for (int j = i + wordLen; j <= loopEnd; j += wordLen){
                string delSub = s.substr(j - wordLen, wordLen);
                if (total[delSub] == had[delSub]) ++invalid;
                if (total[delSub] == --had[delSub]) --invalid;
                string addSub = s.substr(j + subLen - wordLen, wordLen);
                if (total[addSub] == had[addSub]) ++invalid;
                if (total[addSub] == ++had[addSub]) --invalid;
                if (invalid == 0) ans.push_back(j);
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> words;
    words.push_back("word");
    words.push_back("good");
    words.push_back("best");
    words.push_back("good");
    vector<int> ans = s.findSubstring("wordgoodgoodgoodbestword", words);
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    return 0;
}
