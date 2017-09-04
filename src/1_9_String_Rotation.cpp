
// Author :  Accagain
// Date   :  17/8/18
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * 
 * 做法：
 *      将s1 + s1, 然后查找是否有s2, 说明是可以通过rotation得到，否则不能
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

class ReverseEqual {
public:
    bool checkReverseEqual(string s1, string s2) {
        // write code here
        return (s1+s1).find(s2) != -1;
    }
};

int main() {

    return 0;
}

//
// Created by cms on 17/8/18.
//

