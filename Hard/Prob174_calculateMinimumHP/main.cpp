#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> minimumHP(dungeon);
        vector<vector<int>> currentHP(dungeon);
        int row = minimumHP.size();
        int col = minimumHP[0].size();

        if(minimumHP[0][0] >= 0){
            minimumHP[0][0] = 1;
            currentHP[0][0] = 1 + dungeon[0][0];
        }
        else{
            minimumHP[0][0] = -dungeon[0][0] + 1;
            currentHP[0][0] = 1;
        }

        for(int i = 0; i < col; ++i){
            for(int j = 0; j < row; ++j){
                if(i == 0 && j == 0){
                    continue;
                }
                else if(i == 0){
                    if(currentHP[0][j - 1] + dungeon[0][j] >= 1){
                        minimumHP[0][j] = minimumHP[0][j - 1];
                        currentHP[0][j] = currentHP[0][j - 1] + dungeon[0][j];
                    }
                    else{
                            currentHP[0][j] = 1;
                            minimumHP[0][j] = minimumHP[0][j - 1] + (-dungeon[0][j] - currentHP[0][j - 1] + 1);
                    }
                }
                else if(j == 0){
                    if(dungeon[i][0] + currentHP[i - 1][0] >= 1){
                        minimumHP[i][0] = minimumHP[i - 1][0];
                        currentHP[i][0] = currentHP[i - 1][0] + dungeon[i - 1][0];
                    }
                    else{
                        currentHP[i][0] = 1;
                        minimumHP[i][0] = minimumHP[i - 1][0] + (-dungeon[i][0] - currentHP[i - 1][0]) + 1;
                    }
                }
                else{
                    int minimumHPUp, minimumHPLeft;
                    if(currentHP[i - 1][j] + dungeon[i][j] <= 0){
                        minimumHPUp = minimumHP[i - 1][j] + (-currentHP[i - 1][j] - dungeon[i][j]) + 1;
                    }
                    else{
                        minimumHPUp = minimumHP[i - 1][j];
                    }

                    if(currentHP[i][j - 1] + dungeon[i][j] <= 0){
                        minimumHPLeft = minimumHP[i][j - 1] + (-currentHP[i][j - 1] - dungeon[i][j]) + 1;
                    }
                    else{
                        minimumHPLeft = minimumHP[i][j - 1];
                    }

                    if(minimumHPUp < minimumHPLeft){
                        minimumHP[i][j] = minimumHPUp;
                        currentHP[i][j] = (minimumHPUp == minimumHP[i - 1][j]) ? currentHP[i - 1][j] + dungeon[i][j] : 1;
                    }
                    else{
                        minimumHP[i][j] = minimumHPLeft;
                        currentHP[i][j] = (minimumHPLeft == minimumHP[i][j - 1]) ? currentHP[i][j - 1] + dungeon[i][j] : 1;
                    }
                }
            }
        }

        return minimumHP[row - 1][col - 1];
    }
};

int main(){
    Solution test;

    vector<vector<int>> data = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};

    cout << test.calculateMinimumHP(data);

    return 0;
}