#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() + nums2.size() == 0) return 0;
        int n1 = 0, n2 = 0;
        int total = nums1.size() + nums2.size();
        int value;
        for (int i = 0; i < total >> 1; ++i){
            if (n1 == nums1.size()){
                value = nums2[n2];
                ++n2;
            }
            else{
                if (n2 == nums2.size()){
                    value = nums1[n1];
                    ++n1;
                }
                else{
                    if (nums1[n1] < nums2[n2]){
                        value = nums1[n1];
                        ++n1;
                    }
                    else{
                        value = nums2[n2];
                        ++n2;
                    }
                }
            }
        }
        int value2;
        if (n1 == nums1.size()) value2 = nums2[n2];
        else{
            if (n2 == nums2.size()) value2 = nums1[n1];
            else{
                value2 = min(nums1[n1], nums2[n2]);
            }
        }
        if (total % 2 == 0) return (value + value2) / 2.0;
        else return value2;
    }
};

int main(){
    Solution s;
    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    vector<int> nums2;
    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(5);
    nums2.push_back(6);
    cout << s.findMedianSortedArrays(nums1, nums2);
    return 0;
}
