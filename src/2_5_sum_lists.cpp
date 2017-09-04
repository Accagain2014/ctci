
// Author :  Accagain
// Date   :  17/8/30
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
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        // write code here
        int cnt = 0;
        ListNode * ans = a;
        while(a && b)
        {
            int temp = a->val + b->val + cnt;
            a->val = temp % 10;
            cnt = temp / 10;
            if(a->next == NULL)
            {
                a->next = b->next;
                if(a->next == NULL) //有可能为空
                {
                    if(cnt)
                        a->next = new ListNode(cnt);
                    return ans;
                }
                a = a->next;
                break;
            }
            a = a->next;
            b = b->next;
        }

        while(a)
        {
            int temp = (a->val + cnt);
            a->val = temp % 10;
            cnt = temp / 10;
            a = a->next;
        }

        if(cnt)
            a->next = new ListNode(cnt);

        return ans;

    }
};

int main() {

    return 0;
}

//
// Created by cms on 17/8/30.
//

