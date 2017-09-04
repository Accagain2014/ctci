
// Author :  Accagain
// Date   :  17/8/18
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * 
 * 做法：
 *      维护前缀总长度，维护后缀长度，判断每种操作是否能满足
 *
 * 时间复杂度：
 *          O(N), 空间复杂度O(N), 可以只用O(1)的空间复杂度，remove操作和insert操作可以等价，互逆的
 *          如果不相等，往后推一个
 *          如果时间复杂度是O(min(n, m)), n和m差别很大，则近似时间复杂度是O(1)
 * 
****************************************************************************************/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

#define INF 0x3fffffff

using namespace std;

bool one_away(string s1, string s2)
{
    int len1 = s1.size(), len2 = s2.size();
    int max_len = max(len1, len2);

    if(abs(len1 - len2) > 1)
        return false;
    int pre[len1+10], last[len1+10];
    memset(pre, 0, sizeof(pre));
    memset(last, 0, sizeof(last));
    for(int i=0; i<len1 && i<len2; i++)
    {
        if(s1[i] == s2[i])
            pre[i+1] = pre[i]+1;
        else
            pre[i+1] = 0;
        //printf("pre %d %d\n", i+1, pre[i+1]);
    }
    for(int i=len1-1, j=len2-1; i>=0 && j>=0; i--, j--)
    {
        if(s1[i] == s2[j])
            last[i+1] = last[i+2]+1;
        else
            last[i+1] = 0;
        //printf("last %d %d\n", i+1, last[i+1]);
    }
    for(int i=0; i<=len1; i++)
    {
        if(len1 == len2) //replace
        {
            if(pre[i] + last[i+2] == len1-1)
                return true;
        }
        else if(len1 < len2) //less one, only insert
        {
            if(pre[i] == i && last[i+1] == (len1-i))
                return true;
        }
        else // remove
        {
            if(pre[i] == i && last[i+2] == (len1-1-i))
                return true;
        }
        //printf(": i %d\n", i);
    }
    return false;
}

int main() {
    printf("%d\n", one_away("pale", "ple"));
    printf("%d\n", one_away("pale", "plae")); //有点问题，还和顺序有关
    printf("%d\n", one_away("pales", "pale"));
    printf("%d\n", one_away("pale", "bale"));
    printf("%d\n", one_away("pale", "bake"));
    return 0;
}

//
// Created by cms on 17/8/18.
//

