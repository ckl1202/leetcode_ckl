#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> path_name;
        string temp = "";
        for (int i = 1; i < path.size(); ++i){
            //path[i] is a letter.
            if (path[i] != '/'){
                temp += path[i];
                continue;
            }
            //path[i] is a /. if there is noting to be stored, skip it. To deal with "//" case.
            if (path[i] == '/'){
                if (temp == "") continue;
                if (temp == "."){
                    temp = "";
                    continue;
                }
                if (temp == ".."){
                    if (!path_name.empty()){
                        path_name.pop();
                    }
                    temp = "";
                    continue;
                }
                path_name.push(temp);
                temp = "";
                continue;
            }
        }
        string ans = "";
        while (!path_name.empty()){
            ans = '/' + path_name.top() + ans;
            path_name.pop();
        }
        if (ans == "") ans = "/";
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.simplifyPath("/../a//./b/./../c/...");
    return 0;
}
