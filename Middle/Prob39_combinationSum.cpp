#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<int> current_combine;
        vector<vector<int>> res = dfs(candidates, target, 0, current_combine);

        return res;
    }

    vector<vector<int>> dfs(vector<int>& candidates, int target, int current_id, vector<int> current_combine){
        vector<vector<int>> res;

        for(int i = current_id; i < candidates.size(); ++i){
            if(target < candidates[i]){
                continue;
            }
            else{
                if(target == candidates[i]){
                    current_combine.push_back(candidates[i]);
                    res.push_back(current_combine);
                    current_combine.pop_back();
                    continue;
                }
                else{
                    current_combine.push_back(candidates[i]);
                    vector<vector<int>> temp_res = dfs(candidates, target - candidates[i], i, current_combine);

                    if(temp_res.size() > 0){
                        res.insert(res.end(), temp_res.begin(), temp_res.end());
                    }
                    current_combine.pop_back();
                }
            }
        }
        
        return res;
    }
};

int main(){
    Solution test;
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> res = test.combinationSum(candidates, 7);
    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < res[i].size(); ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}



/*改进
  可以考虑先排序，减少搜索的分支个数
  过程中res全部改为引用，直接修改最终的返回值
*/