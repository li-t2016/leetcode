#include <iostream>
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

        //target_string_count数组记录目标字符串s中各个字母的出现频次
        const int CHARACTER_NUM = 26;
        int *target_string_count = new int[CHARACTER_NUM];
        for(int i = 0; i < CHARACTER_NUM; ++i){
            target_string_count[i] = 0;
        }

        for(int i = 0; i < l2; ++i){
            target_string_count[int(char(t[i]) - 'a')] += 1;
        }

        //left_largest_index_have_target_string记录s中每个位置要包含t，至少需要到左侧哪一个索引位置
        int *left_largest_index_have_target_string = new int[l1];
        for(int i = 0; i < l1; ++i){
            left_largest_index_have_target_string[i] = -1;
        }

        //origin_string_count辅助找第一个包含t的位置
        int *origin_string_count = new int[CHARACTER_NUM];
        for(int i = 0; i < CHARACTER_NUM; ++i){
            origin_string_count[i] = 0;
        }

        for(int i = 0; i < l2; ++i){
            origin_string_count[int(char(s[i]) - 'a')] += 1;
        }

        //在s中寻找第一个包含t的位置
        bool if_have_t = false;
        int first_cover_t_index = l2 - 1;
        while(!if_have_t && first_cover_t_index < l1){
            bool if_cover = true;
            for(int j = 0; j < CHARACTER_NUM; ++j){
                if(origin_string_count[j] < target_string_count[j]){
                    if_cover = false;
                    break;
                }
            }
            if(if_cover){
                if_have_t = true;
                left_largest_index_have_target_string[first_cover_t_index] = 0;
                break;
            }
            else{
                ++first_cover_t_index;
                origin_string_count[int(char(s[first_cover_t_index]) - 'a')] += 1;
            }
        }

        if(if_have_t == false){
            return "";
        }
        
        for(int i = first_cover_t_index + 1; i < l1; ++i){
            if(s[i] == s[left_largest_index_have_target_string[i - 1]]){
                int new_left_boundry = left_largest_index_have_target_string[i - 1] + 1;
                while(new_left_boundry <= i && target_string_count[new_left_boundry] == 0){
                    ++new_left_boundry;
                }
                left_largest_index_have_target_string[i] = new_left_boundry;
            }
            else{
                left_largest_index_have_target_string[i] = left_largest_index_have_target_string[i - 1];
            }
        }

        int min_length = INT_MAX;
        int min_length_index = -1;
        for(int i = l2 - 1; i < l1; ++i){
            if(left_largest_index_have_target_string[i] != -1 && i - left_largest_index_have_target_string[i] + 1 < min_length){
                min_length = i - left_largest_index_have_target_string[i] + 1;
                min_length_index = i;
            }
        }

        return s.substr(left_largest_index_have_target_string[min_length_index], min_length);
    };
};