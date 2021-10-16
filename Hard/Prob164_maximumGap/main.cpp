#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums){
        int l = nums.size();
        if(l < 2){
            return 0;
        }

        int minVal = INT_MAX, maxVal = INT_MIN;
        for(int i = 0; i < l; ++i){
            if(nums[i] > maxVal){
                maxVal = nums[i];
            }
            if(nums[i] < minVal){
                minVal = nums[i];
            }
        }

        if(maxVal == minVal){
            return 0;
        }

        int groupNum = l - 1;
        int groupRange = ceil(double(maxVal - minVal) / double(groupNum));
        int** groupNums = new int*[groupNum];
        for(int i = 0; i < groupNum; ++i){
            groupNums[i] = new int[2];
            groupNums[i][0] = INT_MAX;
            groupNums[i][1] = INT_MIN;
        }

        for(int i = 0; i < l; ++i){
            if(nums[i] == minVal){
                continue;
            }
            int curNumGroupId = (nums[i] - minVal - 1) / groupRange;
            if(nums[i] < groupNums[curNumGroupId][0]){
                groupNums[curNumGroupId][0] = nums[i];
            }
            if(nums[i] > groupNums[curNumGroupId][1]){
                groupNums[curNumGroupId][1] = nums[i];
            }
        }

        int maxGap = INT_MIN;
        for(int i = 0; i < groupNum; ++i){
            if(i == 0){
                while(groupNums[i][0] == INT_MAX){
                    ++i;
                }
                maxGap = groupNums[i][0] - minVal;
            }
            else{
                while(i < groupNum && groupNums[i][0] == INT_MAX){
                    ++i;
                }
                if(i == groupNum){
                    break;
                }
                for(int j = i - 1; j >= 0; --j){
                    if(groupNums[j][0] != INT_MAX){
                        if(groupNums[i][0] - groupNums[j][1] > maxGap){
                            maxGap = groupNums[i][0] - groupNums[j][1];
                        }
                        break;
                    }
                }
            }
        }

        for(int i = 0; i < groupNum; ++i){
            delete [] groupNums[i];
        }
        delete [] groupNums;

        return maxGap;
    }
};

int main(){
    Solution test;

    vector<int> data = {3, 6, 9, 1};

    int res = test.maximumGap(data);

    cout <<"maximum gap = " << res << endl;

    return 0;
}