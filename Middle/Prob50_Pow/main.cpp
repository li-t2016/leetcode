#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        bool symbol = n > 0 ? false : true;

        if(n == 0 || x == (double)1.0){
            return 1;
        }
        else if(x == (double)-1.0){
            return n % 2 == 0 ? 1 : -1;
        }
        else if(x == 0){
            return 0;
        }

        bool isIntMin = (n == INT_MIN) ? true : false;
        if(symbol){
            if(isIntMin){
                n = INT_MAX;
            }
            else{
                n = -n;
            }
        }

        double pow2Record[32];
        pow2Record[0] = x;
        
        int i = 1;;
        long int temp = 2;
        while(temp <= n){
            pow2Record[i] = pow2Record[i - 1] * pow2Record[i - 1];
            ++i;
            temp = temp * 2;
        }

        double res = 1.0;
        temp /= 2;

        for(int j = i - 1; j >= 0; --j){
            if(n > temp){
                res *= pow2Record[j];
                n -= temp;
                temp /= 2;
            }
            else if(n == temp){
                res *= pow2Record[j];
                break;
            }
            else{
                temp /= 2;
            }
        }

        if(isIntMin){
            res *= x;
        }

        return symbol ? 1 / res : res;
    }
};

int main(){
    Solution test;

    cout << test.myPow(2, 10) << endl;

    return 0;
}