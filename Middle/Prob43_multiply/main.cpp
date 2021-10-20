#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string numReverse1, numReverse2;
        for(int i = 0; i < num1.size(); ++i){
            numReverse1 += num1[num1.size() - 1 - i];
        }
        
        for(int i = 0; i < num2.size(); ++i){
            numReverse2 += num2[num2.size() - 1 - i];
        }

        string res;
        for(int i = 0; i < num1.size(); ++i){
            res = Add(res, SingleBitNumMultiply(numReverse1[i], numReverse2, i));
        }

        for(int i = 0; i < res.size() / 2; ++i){
            char temp = res[i];
            res[i] = res[res.size() - 1 - i];
            res[res.size() - 1 - i] = temp;
        }

        return res;
    }

    //input: num1[0] should be the least significant bit
    string Add(string& num1, string&& num2){
        string addRes;
        addRes.reserve(num1.size() > num2.size() ? num1.size() + 1 : num2.size() + 1);
        
        int minLength = num1.size() > num2.size() ? num2.size() : num1.size();


        int tempAddSum, tempCarry = 0;
        for(int i = 0; i < minLength; ++i){
            tempAddSum = int(num1[i] - '0') + int(num2[i] - '0') + tempCarry;
            tempCarry = tempAddSum >= 10 ? 1 : 0;
            tempAddSum = tempAddSum >= 10 ? tempAddSum - 10 : tempAddSum;

            addRes += char(tempAddSum + '0');
        }

        if(num1.size() == minLength){
            for(int i = minLength; i < num2.size(); ++i){
                tempAddSum = int(num2[i] - '0') + tempCarry;
                tempCarry = tempAddSum >= 10 ? 1 : 0;
                tempAddSum = tempAddSum >= 10 ? tempAddSum - 10 : tempAddSum;

                addRes += char(tempAddSum + '0');
            }

            if(tempCarry > 0){
                addRes += "1";
            }
        }
        else{
            for(int i = minLength; i < num1.size(); ++i){
                tempAddSum = int(num1[i] - '0') + tempCarry;
                tempCarry = tempAddSum >= 10 ? 1 : 0;
                tempAddSum = tempAddSum >= 10 ? tempAddSum - 10 : tempAddSum;

                addRes += char(tempAddSum + '0');
            }

            if(tempCarry > 0){
                    addRes += "1";
            }
        } 

        return addRes;
    }

    //num1 should be a single bit num, such as "2", "3"
    string SingleBitNumMultiply(char& num1, const string& num2, int shiftBase10 = 0){
        string mulRes;
        mulRes.reserve(1 + num2.size() + shiftBase10);

        if(num1 == '0' || num2 == "0"){
            return "0";
        }

        if(shiftBase10 > 0){
            for(int i = 0; i < shiftBase10; ++i){
                mulRes += '0';
            }
        }

        int singleBit = int(num1 - '0');
        int tempCarry = 0, tempMulRes;

        for(int i = 0; i < num2.size(); ++i){
            tempMulRes = singleBit * int(num2[i] - '0') + tempCarry;

            tempCarry = tempMulRes / 10;

            mulRes += char(tempMulRes % 10 + '0');
        }

        if(tempCarry > 0){
            mulRes += char(tempCarry + '0');
        }

        return mulRes;
    }
};


int main(){
    Solution test;
    string num1 = "10", num2 = "99";
    cout << test.multiply(num1, "99") << endl;;

    return 0;
}