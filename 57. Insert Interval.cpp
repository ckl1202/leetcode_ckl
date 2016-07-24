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

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans = intervals;
        int l = newInterval.start, r = newInterval.end;
        for (int i = 0; i < intervals.size(); ++i){
            if (intervals[i].start <= newInterval.start && intervals[i].end >= newInterval.end) return ans;
            if (intervals[i].start < newInterval.start && intervals[i].end >= newInterval.start && intervals[i].start < l) l = intervals[i].start;
            if (intervals[i].end > newInterval.end && intervals[i].start <= newInterval.end && intervals[i].end > r) r = intervals[i].end;
        }
        for (int i = 0; i < ans.size(); ++i){
            if (ans[i].start >= l && ans[i].end <= r){
                ans.erase(ans.begin() + i);
                --i;
            }
        }
        int pos = 0;
        for (int i = 1; i < ans.size(); ++i){
            if (ans[i].start > l && ans[i - 1].start < l) pos = i;
        }
        if (pos == 0){
            if (ans.size() > 0 && l > ans[ans.size() - 1].start) pos = ans.size();
        }
        ans.insert(ans.begin() + pos, Interval(l, r));
        return ans;
    }
};

int main(){
    Solution s;
    vector<Interval> intervals;
    Interval x;
    x.start = 1; x.end = 2;
    intervals.push_back(x);
/*    x.start = 3; x.end = 5;
    intervals.push_back(x);
    x.start = 6; x.end = 7;
    intervals.push_back(x);
    x.start = 8; x.end = 10;
    intervals.push_back(x);
    x.start = 12; x.end = 16;
    intervals.push_back(x);*/
    vector<Interval> ans = s.insert(intervals, Interval(17, 17));
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i].start << ' ' << ans[i].end << endl;
    }
    return 0;
}
