#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return 0;
        }
        else if (nums[0] > nums[1])
        {
            return 0;
        }
        else if(nums[n - 1] > nums[n - 2]){
            return n - 1;
        }
        

        return SearchPeakElement(nums, 1, n - 1);
    }

    int SearchPeakElement(const vector<int>& nums, int left, int right){
        if(left + 1 == right){
            if(nums[left] > nums[left + 1] && nums[left] > nums[left - 1]){
                return left;
            }
            else{
                return -1;
            }
        }
        else if(left >= right){
            return -1;
        }

        int middle = (left + right) / 2;
        if(nums[middle] > nums[middle - 1] && nums[middle] > nums[middle + 1]){
            return middle;
        }

        if(nums[left] > nums[left - 1] && nums[middle] < nums[left] + middle - left){
            return SearchPeakElement(nums, left, middle);
        }
        else if(nums[middle] > nums[middle - 1] && nums[right - 1] < nums[middle] + right - 1 - middle){
            return SearchPeakElement(nums, middle + 1, right);
        }
        else{
            int idLeft = SearchPeakElement(nums, left, middle);
            return idLeft != -1 ? idLeft : SearchPeakElement(nums, middle + 1, right);
        }
    }
};