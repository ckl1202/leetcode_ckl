#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        int xEnd = n >> 1;
        int yEnd = n >> 1;
        if (n & 1) ++yEnd;
        for (int i = 0; i < xEnd; ++i){
            for (int j = 0; j < yEnd; ++j){
                int x = i, y = j;
                int temp = matrix[x][y];
                for (int k = 0; k < 3; ++k){
                    int nextX = n - 1 - y, nextY = x;
                    matrix[x][y] = matrix[nextX][nextY];
                    x = nextX; y = nextY;
                }
                matrix[x][y] = temp;
            }
        }
    }
};

int main(){
    Solution s;
    int n = 4, num = 0;
    vector<vector<int> > matrix;
    vector<int> temp;
    temp.resize(n);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            temp[j] = ++num;
        }
        matrix.push_back(temp);
    }
    s.rotate(matrix);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
