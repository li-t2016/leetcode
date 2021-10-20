#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
private:
    enum searchType{Pos, Neg};
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long res;

        vector<int> numsCount1 = {0, 0, 0};
        vector<int> numsCount2 = {0, 0, 0};

        GetNumsCount(nums1, numsCount1);
        GetNumsCount(nums2, numsCount2);

        long long negtiveProductCount = numsCount1[0] * numsCount2[2] + numsCount1[2] * numsCount2[0];
        long long zeroProductCount = numsCount1[1] * nums2.size() + numsCount2[1] * nums1.size() - numsCount1[1] * numsCount2[1];
        long long positiveProductCount = numsCount1[0] * numsCount2[0] + numsCount1[2] * numsCount2[2];

        if(k <= negtiveProductCount){

        }
        else if(k - negtiveProductCount <= zeroProductCount){
            res = 0;
        }
        else{

        }

        return res;
    }

    //numsCount is a vector<int> containing 3 elements: {negative numbers count, zero count, positive numbers count}
    void GetNumsCount(vector<int>& nums, vector<int>& numsCount){
        if(nums.size() == 0){
            return;
        }
        else if(nums[0] > 0){
            numsCount[2] = nums.size();
            return;
        }
        else if(nums[nums.size() - 1] < 0){
            numsCount[0] = nums.size();
            return;
        }

        vector<int>::iterator negtiveNumsBorder = lower_bound(nums.begin(), nums.end(), 0);
        vector<int>::iterator  positiveNumsBorder = upper_bound(nums.begin(), nums.end(), 0);

        if(negtiveNumsBorder == nums.end()){
            numsCount[0] = nums.size();
        }
        else{
            numsCount[0] = negtiveNumsBorder - nums.begin();
        }

        if(positiveNumsBorder == nums.end()){
            numsCount[2] = 0;
        }
        else{
            numsCount[2] = nums.end() - positiveNumsBorder;
        }

        numsCount[1] = nums.size() - numsCount[0] - numsCount[2];
    }
};


int main(){
    return 0;
}