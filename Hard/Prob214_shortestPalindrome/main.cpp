#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string res;
        string sPalindrome;
        for(int i = s.length() - 1; i >= 0; --i){
            sPalindrome += s[i];
        }
        
        int* next = new int[s.length()];

        ConstructNextArray(sPalindrome, next);

        for(int i = 0; i < s.length(); ++i){
            cout << next[i] << ' ';
        }
        cout << endl;
        
        delete [] next;
        return res;
    }

    void ConstructNextArray(const string& s, int* next){
        next[0] = 0;
        for(int i = 1; i < s.length(); ++i){
            int now = next[i - 1];
            while(now > 0){
                if(s[now] == s[i]){
                    next[i] = now + 1;
                    break;
                }
                else{
                    now = next[now - 1];
                }
            }
            if(now == 0){
                next[i] = s[0] == s[i] ? 1 : 0;
            }
        }
    }
};

int main(){
    Solution test;

    string s = "abcdaabcdanad";
    int* next = new int[s.size()];
    test.ConstructNextArray(s, next);

    for(int i = 0; i < s.size(); ++i){
        cout << next[i] << ' ';
    }
    cout << endl;

    return 0;
}