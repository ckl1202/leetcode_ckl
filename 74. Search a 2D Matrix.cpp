#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        int row;
        if (target < matrix[0][0]) return false;
        int l = 0, r = matrix.size() - 1;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (matrix[mid][0] <= target &&
                (mid == matrix.size() - 1 || matrix[mid + 1][0] > target)){
                    row = mid;
                    break;
                }
            if (matrix[mid][0] > target) r = mid - 1;
            else l = mid + 1;
        }
        l = 0, r = matrix[row].size() - 1;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (matrix[row][mid] == target) return true;
            if (matrix[row][mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(3);
    temp.push_back(5);
    temp.push_back(7);
    matrix.push_back(temp);
    temp[0] = 10; temp[1] = 11; temp[2] = 16; temp[3] = 20;
    matrix.push_back(temp);
    temp[0] = 23; temp[1] = 30; temp[2] = 34; temp[3] = 50;
    matrix.push_back(temp);
    for (int i = 0; i < 55; ++i){
        cout << i << ' ' << s.searchMatrix(matrix, i) << endl;
    }
    return 0;
}
