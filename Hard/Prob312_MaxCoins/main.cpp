#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> val(nums.size() + 2, 1);
        for(int i = 0; i < nums.size(); ++i){
            val[i + 1] = nums[i];
        }

        vector<vector<int>> subsetMaxCoins(nums.size() + 2, vector<int>(nums.size() + 2, 0));

        FindSubsetMaxCoins(val, subsetMaxCoins, 0, nums.size() + 1);

        return subsetMaxCoins[0][nums.size() + 1];
    }

    void FindSubsetMaxCoins(vector<int>& val, vector<vector<int>>& subsetMaxCoins, int leftBorder, int rightBorder){
        if(leftBorder >= rightBorder - 1){
            subsetMaxCoins[leftBorder][rightBorder] = 0;
            return;
        }
        else if(leftBorder + 2 == rightBorder){
            subsetMaxCoins[leftBorder][rightBorder] = val[leftBorder] * val[leftBorder + 1] * val[rightBorder];
            return;
        }
        else if(subsetMaxCoins[leftBorder][rightBorder] != 0){
            return;
        }

        int currentMaxCoin = INT32_MIN;
        for(int i = leftBorder + 1; i < rightBorder; ++i){
            int currentCoin = val[leftBorder] * val[i] * val[rightBorder];

            FindSubsetMaxCoins(val, subsetMaxCoins, leftBorder, i);
            FindSubsetMaxCoins(val, subsetMaxCoins, i, rightBorder);

            currentMaxCoin = currentCoin + subsetMaxCoins[leftBorder][i] + subsetMaxCoins[i][rightBorder] > currentMaxCoin ? currentCoin + subsetMaxCoins[leftBorder][i] + subsetMaxCoins[i][rightBorder] : currentMaxCoin;
        }

        subsetMaxCoins[leftBorder][rightBorder] = currentMaxCoin;
        return;
    }
};

int main(){
    vector<int> val = {5, 8};

    Solution test;
    cout << test.maxCoins(val) << endl;

    return 0;
}

