#include <string>
#include <iostream>
using namespace std;

class solution{
public:
    bool isNumber(string s){
        int l = s.length();
        if(l == 0){
            return false;
        }

        int e_index = -1;
        for(int i = 0; i < l; ++i){
            if(s[i] == 'e' || s[i] == 'E'){
                e_index = i;
                break;
            }
        }

        if(e_index == -1){
            if(isInt(s) || isFraction(s)){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(e_index == l - 1 || e_index == 0){
                return false;
            }
            else{
                string num1 = s.substr(0, e_index);
                string num2 = s.substr(e_index + 1);
                if(!((isInt(num1) || isFraction(num1)) && isInt(num2))){
                    return false;
                }
            }
        }

        return true; 
    }

    bool isInt(string s){
        int l = s.length();
        if(l == 0){
            return false;
        }
        
        bool have_symbol = false;
        if(s[0] == '+' || s[0] == '-'){
            have_symbol = true;
        }
        if(have_symbol == true && l == 1){
            return false;
        }

        for(int i = 0; i < l; ++i){
            if(i == 0 && have_symbol == true){
                continue;
            }
            else{
                if(!(s[i] >= '0' && s[i] <= '9')){
                    return false;
                }
            }
        }

        return true;
    }

    bool isFraction(string s){
        int l = s.length();
        if(l == 0){
            return false;
        }

        bool have_symbol = false;
        if(s[0] == '+' || s[0] == '-'){
            have_symbol = true;
        }
        if(have_symbol && l == 2){
            return false;
        }
        else if(!have_symbol && l == 1){
            return false;
        }

        int point_index = -1;
        for(int i = 0; i < l; ++i){
            if(s[i] == '.'){
                point_index = i;
                break;
            }
        }

        if(point_index == -1){
            return false;
        }

        int begin = (have_symbol == true) ? 1 : 0;
        for(int i = begin; i < l; ++i){
            if(i == point_index){
                continue;
            }
            else if(!(s[i] >= '0' && s[i] <= '9')){
                return false;
            }
        }

        return true;
    }
};

int main(){
    solution test;
    cout << test.isNumber("1.2");
    return 0;
}
