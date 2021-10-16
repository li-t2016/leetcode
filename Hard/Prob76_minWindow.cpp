#include <iostream>
#include <string>
#include <map>
#include <limits.h>
using namespace std;


//最小覆盖子串
class Solution {
public:
    string minWindow(string s, string t) {
        int l1 = s.length();
        int l2 = t.length();

        if(l1 < l2){
            return "";
        }

        map <char, int> s_char_count;
        map <char, int> t_char_count;

        for(auto &c : t){
            ++t_char_count[c];
        }

        int left = 0, right = -1;
        while(left < l1 && t_char_count[s[left]] == 0){
            ++left;
        }
        if(left == l1){
            return "";
        }

        right = left;
        int min_length = INT_MAX;
        int min_str_left = -1, min_str_right = -1;

        while(right <= l1){
            while(!isCover(s_char_count, t_char_count)){
                if(right < l1){
                    ++s_char_count[s[right]];
                    ++right;
                }
                else{
                    break;
                }
            }

            if(isCover(s_char_count, t_char_count)){
                if(right - left < min_length){
                    min_str_left = left;
                    min_str_right = right;
                    min_length = right - left;
                }
            }
            else{
                break;
            }

            --s_char_count[s[left]];
            ++left;
            while(left < right){
                if(t_char_count[s[left]] == 0){
                    --s_char_count[s[left]];
                    ++left;
                }
                else{
                    break;
                }
            };
        }

        if(min_str_left == -1){
            return "";
        }
        else{
            return s.substr(min_str_left, min_length);
        }
    }

    bool isCover(map<char, int> &m1, map<char, int> &m2){
        for(const auto &e : m2){
            if(m1[e.first] < e.second){
                return false;
            }
        }

        return true;
    }
};

int main(){
    Solution test;
    cout << test.minWindow("ADOBECODEBANC", "ABC") << endl;

    return 0;
}