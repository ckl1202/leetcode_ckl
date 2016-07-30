#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;
        int l = 1, r = x;
        int mid;
        while (l <= r){
            mid = l + ((r - l) >> 1);
            if (mid == x / mid) return mid;

            if (mid < x / mid) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};

int main(){
    Solution s;
    cout << s.mySqrt(2);
    return 0;
}
