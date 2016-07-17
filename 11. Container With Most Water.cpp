#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) return 0;
        int _max = 0;
        int l = 0, r = height.size() - 1;
        while (l <= r){
            if (min(height[l], height[r]) * (r - l) > _max){
                _max = min(height[l], height[r]) * (r - l);
            }
            if (height[l] < height[r]) ++l;
            else --r;
        }
        return _max;
    }
};

int main(){
    Solution s;
    vector<int> height;
    height.push_back(1);
    height.push_back(3);
    height.push_back(4);
    height.push_back(2);
    cout << s.maxArea(height);
    return 0;
}
