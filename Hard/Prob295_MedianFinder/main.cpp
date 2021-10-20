#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
public:
    vector<int> numLists;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        numLists.push_back(num);
    }
    
    double findMedian() {
        sort(numLists.begin(), numLists.end());
        int n = numLists.size();
        if(n == 0){
            return 0;
        }
        int currentIterConunt = 0;
        for(auto iter = numLists.begin(); iter != numLists.end(); ++iter){
            if(currentIterConunt == n / 2){
                if(n % 2 == 0){
                    return (double(*iter) + double((*(--iter)))) / 2;
                }
                else{
                    return double(*iter);
                }
            }
            ++currentIterConunt;
        }

        return 0;
    }
};


int main(){
    MedianFinder test;
    test.addNum(5);
    test.addNum(9);
    test.addNum(100);
    for(auto iter = test.numLists.begin(); iter != test.numLists.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;
    cout << test.findMedian() << endl;

    return 0;
}