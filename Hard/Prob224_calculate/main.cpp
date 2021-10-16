#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

    class Solution{
        public:
            int calculate(string s){
                stack<char> calculationStack;

                for(int i = 0; i < s.length(); ++i){
                    if(s[i] == ' '){
                        continue;
                    }

                    if(s[i] != ')'){
                        if(i > 0 && s[i] == '-'){
                            calculationStack.push('+');
                        }
                        calculationStack.push(s[i]);
                    }
                    else{
                        if(calculationStack.top() == '('){
                            calculationStack.pop();
                            continue;
                        }

                        while(true){
                            int firstNum, secondNum;
                            char symbol;
                            secondNum = getOneNum(calculationStack);
                            if(calculationStack.top() == '('){
                                if(!calculationStack.empty()){
                                    calculationStack.pop();
                                }
                                pushOneNum(secondNum, calculationStack);
                                break;
                            }

                            symbol = calculationStack.top();
                            calculationStack.pop();

                            firstNum = getOneNum(calculationStack);

                            if(symbol == '-'){
                                pushOneNum(firstNum - secondNum, calculationStack);
                            }
                            else{
                                pushOneNum(firstNum + secondNum, calculationStack);
                            }
                        }
                    }
                }
                
                int res;
                while(true){
                    int secondNum = getOneNum(calculationStack);
                    //cout << "secondNum = " << secondNum << endl;
                    if(calculationStack.empty()){
                        res = secondNum;
                        break;  
                    }
                    else{
                        char symbol = calculationStack.top();
                        calculationStack.pop();

                        int firstNum = getOneNum(calculationStack);
                        //cout << "firstNum = " << firstNum << endl;

                        if(symbol == '-'){
                            pushOneNum(firstNum - secondNum, calculationStack);
                        }
                        else{
                            pushOneNum(firstNum + secondNum, calculationStack);
                        }
                    }
                }

                return res;
            }

        private:
            int getOneNum(stack<char>& s){
                string num;
                while(!s.empty() && s.top() <= '9' && s.top() >= '0'){
                    num += s.top();
                    s.pop();
                }

                bool symbol = false;
                if(!s.empty() && s.top() == '-'){
                    s.pop();
                    if(s.empty() || (s.top() == '+' || s.top() == '-' || s.top() == '(')){
                        symbol = true;
                    }
                    if(!symbol){
                        s.push('-');
                    }
                }

                int res = 0;
                long long int digit = 1;
                for(int i = 0; i < num.length(); ++i){
                    res += int(num[i] - '0') * digit;
                    digit *= 10;
                }

                if(symbol){
                    res = -res;
                }
                return res;
            }

            void pushOneNum(int num, stack<char>& s){
                string n;
                bool symbol = false;
                if(num < 0){
                    symbol = true;
                    num = -num;
                }
                while(num >= 10){
                    n += char(num % 10 + int('0'));
                    num = num / 10;
                }
                n += char(num + int('0'));

                if(symbol){
                    if(!s.empty() && s.top() == '-'){
                        s.pop();
                    }
                    else{
                        s.push('-');
                    }
                }
                for(int i = n.length() - 1; i >= 0; --i){
                    s.push(n[i]);
                }
            }
    };

int main(){
    Solution test;

    string s = "1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10";
    //s = "(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)";
    //s = "(4-(1+(3)-2)-5)+8-(3-5)-1";

    cout << "result = " << test.calculate(s) << endl;

    return 0;
}