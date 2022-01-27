#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        unordered_map<long, int> residualRecords;

        long numeratorLong = (long)numerator;
        long denominatorLong = (long)denominator;

        if(numeratorLong == 0){
            return "0";
        }
        else if((numeratorLong > 0 && denominatorLong < 0) || (numeratorLong < 0 && denominatorLong > 0)){
            res += "-";
            numeratorLong = numeratorLong > 0 ? numeratorLong : -numeratorLong;
            denominatorLong = denominatorLong > 0 ? denominatorLong : -denominatorLong; 
        }
        
        long residual = 0;

        res += to_string(numeratorLong / denominatorLong);

        residual = numeratorLong % denominatorLong;
        if(residual == 0){
            return res;
        }
        else{
            res += ".";
        }

        int circleBeginIndex = res.length();
        while(residual != 0){
            if(residualRecords.count(residual)){
                res = res.substr(0, residualRecords[residual]) + "(" + res.substr(residualRecords[residual], res.length()) + ")";
                break;
            }
            else{
                residualRecords[residual] = circleBeginIndex;
            }

            residual *= 10;
            res += to_string(residual / denominatorLong);
            residual = residual % denominatorLong;
            ++circleBeginIndex;
        }

        return res;
    }
};

int main(){
    Solution test;

    cout << test.fractionToDecimal(100, 3) << endl;

    int i1 = 7;
    int i2 = -12;
    long i3 = (long)i2;
    cout << i3 << endl;

    return 0;
}