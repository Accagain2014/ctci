
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

和面试官确认，是否是大小写敏感，eg: "God"是否是"dog"的一个排列. 还有空格是否重要

 时间复杂度O(n), 空间复杂度O(n)
 另外解法，排序后再比较，O(nlog(n)) clean, simple, easy to understand


 */

bool check_permutation(string desc, string target)
{
    if(desc.size() != target.size())
        return false;
    unordered_map<char, int> myp;
    for(int i=0; i<desc.size(); i++)
        myp[desc[i]]++;
    for(int i=0; i<target.size(); i++)
    {
        if(myp[target[i]])
            myp[target[i]]--;
        else
            return false;
    }
    return true;
}

bool cmp(char a, char b)
{
    return a > b;
}

int main() {
    string s = "bacded";
    sort(s.begin(), s.end(), cmp);
    printf("%s\n", s.c_str());

    printf("%d\n", check_permutation("aaa", "ada"));
    return 0;
}

//
// Created by cms on 17/8/18.
//

