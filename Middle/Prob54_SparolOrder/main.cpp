#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        if(matrix.size() == 0){
            return res;
        }

        int m = matrix.size(), n = matrix[0].size();

        res.reserve(m * n);

        int circleNum = (m - 1) / 2 > (n - 1) / 2 ? (n - 1) / 2 : (m - 1) / 2;

        for(int i = 0; i <= circleNum; ++i){
            TraverseOneCircle(matrix, res, i, i);
        }

        return res;

    }

    void TraverseOneCircle(vector<vector<int> >& matrix, vector<int>& traverseRes, int row, int col){
        int n = matrix[0].size() - 2 * col;
        int m = matrix.size() - 2 * row;

        //traverse the top side
        for(int i = col; i < col + n; ++i){
            traverseRes.push_back(matrix[row][i]);
        }
        
        //traverse the right side
        for(int i = row + 1; i < row + m; ++i){
            traverseRes.push_back(matrix[i][col + n - 1]);
        }

        //traverse the bottom side
        if(m > 1){
            for(int i = col + n - 2; i >= col; --i){
                traverseRes.push_back(matrix[row + m - 1][i]);
            }
        }

        //traverse the left side
        if(n > 1){
            for(int i = row + m - 2; i > row; --i){
                traverseRes.push_back(matrix[i][col]);
            }
        }
    }
};

int main(){

    return 0;
}