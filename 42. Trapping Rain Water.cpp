#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        vector<int> lm, rm;
        lm.resize(height.size());
        rm.resize(height.size());
        int m_max = 0;
        for (int i = 0; i < lm.size(); ++i){
            lm[i] = m_max;
            if (height[i] > m_max) m_max = height[i];
        }
        m_max = 0;
        for (int i = rm.size() - 1; i >= 0; --i){
            rm[i] = m_max;
            if (height[i] > m_max) m_max = height[i];
        }
        int ans = 0;
        for (int i = 0; i < height.size(); ++i){
            ans += max( min(lm[i], rm[i]) - height[i], 0 );
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> height;
    height.push_back(0);
    height.push_back(1);
    height.push_back(0);
    height.push_back(2);
    height.push_back(1);
    height.push_back(0);
    height.push_back(1);
    height.push_back(3);
    height.push_back(2);
    height.push_back(1);
    height.push_back(2);
    height.push_back(1);
    cout << s.trap(height) << endl;
    return 0;
}
