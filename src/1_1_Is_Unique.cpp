
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

#define INF 0x3fffffff

using namespace std;

/*
    问是ASCII码(扩展的是256, 基本的是128)，还是UNICODE
    或者是否是字母
    O(N)时间，O(1)空间，而且迭代次数不会超过字母不同个数, 所以时间也是O(1)

    follow up: 如果不能使用额外的数据结构
        1) 将当前字符和其他每一个字符比较，时间O(n^2), 空间O(1)
        2) 可以排序，O(Nlog(N)), 比较相邻的两个, 但是排序可能需要占用多的空间

 */

bool is_unique(string s)
{
    unsigned int record[4];
    memset(record, 0, sizeof(record));
    for(int i=0; i<s.size(); i++)
    {
        int now = s[i] / 32;
        unsigned int left = s[i] % 32;
        if(record[now] & (((unsigned int)1<<left)))
            return false;
        record[now] |= ((unsigned int)1<<left);
    }
    return true;
}

int main() {

    printf("%u\n", 1<<31);
    printf("%d\n", is_unique("1kdf2a1"));
    return 0;
}

//
// Created by cms on 17/8/18.
//

