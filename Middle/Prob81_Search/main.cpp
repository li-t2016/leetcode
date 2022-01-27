#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int rotationId = FindRotationId(nums);

        if(nums[rotationId] > target || (rotationId > 0 && nums[rotationId - 1] < target) || (rotationId == 0 && nums[nums.size() - 1] < target)){
            return false;
        }
        else{
            /*if(nums[nums.size() - 1] < target){
                return BinarySearch(nums, target, 0, rotationId);
            }
            else{
                return BinarySearch(nums, target, rotationId, nums.size());
            }*/

            int left, right;
            if(nums[nums.size() - 1] < target){
                left = 0;
                right = rotationId;
            }
            else{
                left = rotationId;
                right = nums.size();
            }

            int middle;
            while(true){
                if(left + 1 == right){
                    return (nums[left] == target) ? true : false;
                }

                middle = (left + right) / 2;

                if(nums[middle] == target){
                    return middle;
                }
                else if(nums[middle] > target){
                    right = middle;
                }
                else{
                    left = middle + 1;
                }
            }
        }
    }

    int FindRotationId(const vector<int>& nums){
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[i - 1]){
                return i;
            }
        }

        return 0;
    }

    bool BinarySearch(const vector<int>& nums, int target, int left, int right){
        if(left + 1 == right){
            if(nums[left] == target){
                return true;
            }
            else{
                return false;
            }
        }

        int middle = (left + right) / 2;

        if(nums[middle] == target){
            return true;
        }
        else if(nums[middle] > target){
            return BinarySearch(nums, target, left, middle);
        }
        else{
            return BinarySearch(nums, target, middle + 1, right);
        }
    }
};

int main(){
    Solution test;
    vector<int> data = {4, 5, 1, 2, 3};
    cout << test.search(data, 3) << endl;

    return 0;
}

