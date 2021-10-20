#include <iostream>
#include <vector>
using namespace std;


//递归循环，判断每个位置i的元素是否存在，line 34表示存在，然后循环剩余的元素
//line 36删除之后，下一次循环，表示没有这个元素的情况
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> subset;

        //empty set must be s subset
        res.push_back(subset);

        for(int i = 0; i < nums.size(); ++i){
            subset.push_back(nums[i]);
            res.push_back(subset);
            FindAllSubsetsWithIDElement(nums, res, subset, i);
            subset.pop_back();
        }

        return res;
    }

    void FindAllSubsetsWithIDElement(vector<int>& nums, vector<vector<int> >& res, vector<int>& subset, int id){
        if(id == nums.size() - 1){
            return;
        }
        else{
            for(int i = id + 1; i < nums.size(); ++i){
                subset.push_back(nums[i]);
                res.push_back(subset);
                FindAllSubsetsWithIDElement(nums, res, subset, i);
                subset.pop_back();
            }
            return;
        }
    }
};

int main(){
    Solution test;
    vector<int> data = {1, 2, 5, 6};
    auto res = test.subsets(data);
    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[i].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}