#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        traversePermutation(res, nums, 0);

        return res;
    }

    void traversePermutation(vector<vector<int>>& res, vector<int>& nums, int current_id){
        if(current_id == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = current_id; i < nums.size(); ++i){
            int temp = nums[i];
            nums[i] = nums[current_id];
            nums[current_id] = temp;

            traversePermutation(res, nums, current_id + 1);

            temp = nums[i];
            nums[i] = nums[current_id];
            nums[current_id] = temp;
        }
    }
};

int main(){
    Solution test;

    vector<int> nums = {1, -10, 2, 3};
    cout << test.permute(nums).size() << endl;

    return 0;
}