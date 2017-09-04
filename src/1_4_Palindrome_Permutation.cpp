
// Author :  Accagain
// Date   :  17/8/18
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * 
 * 做法：
 *      
 * 时间复杂度：
 *          
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#define INF 0x3fffffff

using namespace std;
/*
 *
 * case insensitive,
 * 用int保存，按位来判断次数, 检查某个数恰好有一位是1，a & (a-1)
 *  factorial time, exponential time,
 *
 *  in order to check if A is in group B, don't need to generate all permutation in B,
 *  just check whether A has the property
 *
 */

bool palindrome_permutation_bit(string s)
{
    int is_odd_times;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] != ' ')
        {
            int now;
            if(s[i] >= 'A' && s[i] <= 'Z')
                now = s[i] - 'A';
            else
                now = s[i] - 'a';
            is_odd_times = is_odd_times ^ (1<<now);
        }
    }
    printf("%x\n", is_odd_times);
//    int odd_sum = 0;
//    for(int i=0; i<26; i++)
//    {
//        if(is_odd_times & (1<<i))
//        {
//            odd_sum++;
//            if(odd_sum > 1)
//                return false;
//        }
//    }
    return is_odd_times == 0 ? 1 : (is_odd_times & (is_odd_times-1) == 0 ? 1: 0);
    //return true;
}

bool palindrome_permutation(string s)  // 时间复杂度O(n),
{
    unordered_map<char, int> char_times;
    int odd_times = 0;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] != ' ')
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                char_times[s[i]-'A']++;
            else
                char_times[s[i]-'a']++;
        }
    }
    for(auto it=char_times.begin(); it!=char_times.end(); it++)
    {
        if(it->second % 2)
        {
            odd_times++;
            if(odd_times > 1)
                return false;
        }
    }
    return true;
}

int main() {

    printf("%d\n", palindrome_permutation_bit("Taact Coa"));
    printf("%d\n", palindrome_permutation("Taact Coa"));
    return 0;
}

//
// Created by cms on 17/8/18.
//

