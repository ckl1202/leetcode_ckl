#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        if (words.empty()){
            string temp = "";
            for (int i = 0; i < maxWidth; ++i) temp += " ";
            ans.push_back(temp);
            return ans;
        }
        int len = words[0].size();
        int l = 0;
        char space = ' ';
        for (int i = 1; i < words.size(); ++i){
            if (len + 1 + words[i].size() > maxWidth){
                int r = i - 1;
                string temp = "";
                if (l == r){
                    temp = words[l];
                    for (int j = words[l].size(); j < maxWidth; ++j){
                        temp += space;
                    }
                }
                else{
                    temp = "";
                    int aveSpace = (maxWidth - len) / (r - l);
                    int extraSpace = (maxWidth - len - aveSpace * (r - l));
                    ++aveSpace;
                    for (int j = l; j < r; ++j){
                        temp += words[j];
                        int numSpace = aveSpace;
                        if (extraSpace > 0){
                            ++numSpace;
                            --extraSpace;
                        }
                        for (int k = 0; k < numSpace; ++k){
                            temp += space;
                        }
                    }
                    temp += words[r];
                }
                ans.push_back(temp);
                l = i;
                len = words[i].size();
            }
            else len += 1 + words[i].size();
        }
        string temp = "";
        for (int i = l; i < words.size() - 1; ++i){
            temp += words[i] + space;
        }
        temp += words[words.size() - 1];
        while (temp.size() < maxWidth) temp += space;
        ans.push_back(temp);
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> words;
    /*.push_back("lalalademaxiya");
    words.push_back("This");
    words.push_back("is");
    words.push_back("an");
    words.push_back("example");
    words.push_back("of");
    words.push_back("text");
    words.push_back("justification.");*/
    words.push_back("");
    vector<string> ans = s.fullJustify(words, 2);
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i] << endl;
    }
    return 0;
}
