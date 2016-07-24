#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool comp(const Interval &a, const Interval &b){
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if (intervals.size() == 0) return ans;

        sort(intervals.begin(), intervals.end(), comp);

        Interval temp(intervals[0].start, intervals[0].end);
        for (int i = 1; i < intervals.size(); ++i){
            if (intervals[i].start <= temp.end && intervals[i].end > temp.end){
                temp.end = intervals[i].end;
            }
            else if (intervals[i].start > temp.end){
                ans.push_back(temp);
                temp.start = intervals[i].start;
                temp.end = intervals[i].end;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

int main(){
    Solution s;
    Interval x;
    vector<Interval> is;
    x.start = 8; x.end = 10;
    is.push_back(x);
    x.start = 15; x.end = 18;
    is.push_back(x);
    x.start = 1; x.end = 6;
    is.push_back(x);
    x.start = 1; x.end = 4;
    is.push_back(x);
    vector<Interval> ans = s.merge(is);
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i].start << ' ' << ans[i].end << endl;
    }
    return 0;
}
