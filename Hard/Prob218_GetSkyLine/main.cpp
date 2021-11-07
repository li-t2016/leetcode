#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        sort(buildings.begin(), buildings.end(), MyCompareFunc);

        priority_queue<vector<int>, vector<vector<int>>, cmp> edges;
        for(int i = 0; i < buildings.size(); ++i){
            edges.emplace(new vector<int>{i, buildings[i][0]});
            edges.emplace(new vector<int>{i, buildings[i][1]});
        }

        vector<vector<int>> res;

        while(!edges.empty()){
            const vector<int>& edge = edges.top();
            edges.pop();
            
            int tempIntersectHeight = 0;
            bool isIntersect = false;

            for(int i = 0; i < buildings.size(); ++i){
                if(buildings[i][0] > edge[0]){
                    break;
                }
                else if(buildings[i][1] < edge[0]){
                    continue;
                }
                
                if(buildings[i][])
            }
        }

        return res;
    }

    static bool MyCompareFunc(vector<int>& v1, vector<int>& v2){
        return v1[1] < v2[1];
    }

    struct cmp {
        bool operator()(vector<int>& v1, vector<int>& v2){
            return v1[1] > v2[1];
        }
    };
};

int main(){
    Solution test;


    
    return 0;
}