#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;

        if(n == 0){
            return res;
        }

        res.reserve(n);
        
        vector<int> oneRow(n, 0);
        for(int i = 0; i < n; ++i){
            res.push_back(oneRow);
        }

        int circleNum = (n - 1) / 2;
        int currentNum = 1;

        for(int i = 0; i <= circleNum; ++i){
            TraverseOneCircle(res, currentNum, i, i, n);
        }

        return res;
    }

    void TraverseOneCircle(vector<vector<int> >& res, int& currentNum, int row, int col, int n){
        int circleSide = n - 2 * row;

        //traverse the top side
        for(int i = col; i < col + circleSide; ++i){
            res[row][i] = currentNum;
            ++currentNum;
        }
        
        //traverse the right side
        for(int i = row + 1; i < row + circleSide; ++i){
            res[i][col + circleSide - 1] = currentNum;
            ++currentNum;
        }

        //traverse the bottom side
        if(circleSide > 1){
            for(int i = col + circleSide - 2; i >= col; --i){
                res[row + circleSide - 1][i] = currentNum;
                ++currentNum;
            }
        }

        //traverse the left side
        if(circleSide > 1){
            for(int i = row + circleSide - 2; i > row; --i){
                res[i][col] = currentNum;
                ++currentNum;
            }
        }
    }
};

int main(){


    return 0;
}