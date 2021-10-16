#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;

        if(k <= 0 || k > n){
            return res;
        }

        for(int i = n; i >= k; --i){
            vector<int> tempRes;
            tempRes.push_back(i);
            findCombination(i - 1, k - 1, tempRes, res);
        }

        return res;
    }

    void findCombination(int n, int k, vector<int>& currentRes, vector<vector<int> >& res){
        if(k == 0){
            res.push_back(currentRes);
        }
        else if(n == k){
            for(int i = 1; i <= k; ++i){
                currentRes.push_back(i);
            }
            res.push_back(currentRes);
            for(int i = 1; i <= k; ++i){
                currentRes.pop_back();
            }
        }
        else{
            for(int i = n; i >= k; --i){
                currentRes.push_back(i);
                findCombination(i - 1, k - 1, currentRes, res);
                currentRes.pop_back();
            }
        }
    }
};

int main(){
    Solution test;
    int n = 10, k = 3;
    vector<vector<int> > res = test.combine(n, k);
    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < k; ++j){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}