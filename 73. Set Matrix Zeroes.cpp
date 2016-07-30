#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        if (matrix[0].size() == 0) return;
        vector<int> row, col;
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = 0; j < matrix.size(); ++j){
                if (matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        vector<int>::iterator rowEnd = unique(row.begin(), row.end());
        vector<int>::iterator colEnd = unique(col.begin(), col.end());
        for (vector<int>::iterator iter = row.begin(); iter != rowEnd; ++iter){
            for (int j = 0; j < matrix[0].size(); ++j){
                matrix[*iter][j] = 0;
            }
        }
        for (vector<int>::iterator iter = col.begin(); iter != colEnd; ++iter){
            for (int j = 0; j < matrix.size(); ++j){
                matrix[j][*iter] = 0;
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix;
    vector<int> temp;
    temp.push_back(3);
    temp.push_back(7);
    temp.push_back(2);
    temp.push_back(8);
    temp.push_back(2);
    matrix.push_back(temp);
    temp[2] = 0;
    matrix.push_back(temp);
    temp[1] = 0;
    matrix.push_back(temp);
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    s.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++i){
        for (int j = 0; j < matrix[0].size(); ++j){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
