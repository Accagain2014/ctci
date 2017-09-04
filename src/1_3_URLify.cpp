
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

 two-scan approach,
 */

void replace_spaces(char * str, int true_length)
{
    int space_count = 0;
    for(int i=0; i<true_length; i++)
    {
        if(str[i] == ' ')
            space_count++;
    }
    int index = true_length + space_count*2;
    if(true_length < strlen(str))
        str[true_length] = '\0';
    for(int i=true_length-1; i>=0; i--)
    {
        if(str[i] == ' ')
        {
            str[index-1] = '0';
            str[index-2] = '2';
            str[index-3] = '%';
            index -= 3;
        }
        else
        {
            str[index-1] = str[i];
            index -= 1;
        }
    }
}

string URLify(string s, int len)
{
    string ans = "";
    int has = 0;

    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == ' ')
            ans += "%20";
        else
            ans += s[i];
        has++;
        if(has >= len)
            break;
    }
    return ans;

}

int main() {
    string s = "Mr Jonh Smith    ";
    printf("%s\n", URLify(s, 13).c_str());

    char ss[] = "Mr Jonh Smith    ";
    replace_spaces(ss, 13);
    printf("%s\n", ss);
    return 0;
}

//
// Created by cms on 17/8/18.
//

