#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        if(k == 0 || n < k){
            return res;
        }

        int groupNum = (n % k == 0) ? n / k : n / k + 1;
        int groupElementNum = k;
        
        vector<int> leftLargestElements(n, INT_MIN);
        vector<int> rightLargestElements(n, INT_MIN);

        for(int i = 0; i < groupNum; ++i){
            for(int j = i * groupElementNum; j < (i + 1) * groupElementNum && j < n; ++j){
                if(j == i * groupElementNum){
                    leftLargestElements[j] = nums[j];
                }
                else{
                    leftLargestElements[j] = nums[j] > leftLargestElements[j - 1] ? nums[j] : leftLargestElements[j - 1];
                }
            }
        }

        for(int i = groupNum - 1; i >= 0; --i){
            for(int j = min((i + 1) * groupElementNum - 1, n - 1); j >= i * groupElementNum; --j){
                if(j == min((i + 1) * groupElementNum - 1, n - 1)){
                    rightLargestElements[j] = nums[j];
                }
                else{
                    rightLargestElements[j] = nums[j] > rightLargestElements[j + 1] ? nums[j] : rightLargestElements[j + 1];
                }
            }
        }

        for(int i = 0; i < n - k + 1; ++i){
            if(i % groupElementNum == 0){
                res.push_back(rightLargestElements[i]);
            }
            else{
                res.push_back(max(rightLargestElements[i], leftLargestElements[i + k - 1]));
            }
        }

        return res; 
    }

    int min(int& n1, int& n2){
        return n1 > n2 ? n2 : n1;
    }

    int min(int&& n1, int&& n2){
        return n1 > n2 ? n2 : n1;
    }

    int max(int& n1, int& n2){
        return n1 > n2 ? n1 : n2;
    }
};

int main(){
    Solution test;
    vector<int> testData = {1, 5, 8, -2, 100, 3, 5};

    auto res = test.maxSlidingWindow(testData, 2);

    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}