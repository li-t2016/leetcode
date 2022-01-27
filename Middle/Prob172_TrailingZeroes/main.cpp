#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if(n == 0){
            return 0;
        }

        
    }
};

int main(){
    long long int i = 1;

    for(int j = 1; j < 20; ++j){
        cout << j << " " << i << endl;
        i *= (j + 1); 
    }

    return 0;
}