
// Author :  Accagain
// Date   :  17/8/30
// Email  :  chenmaosen0@gmail.com

/***************************************************************************************
 * 
 * 
 * 做法：
 *      
 * 时间复杂度：
 *   考虑是否稳定的问题，空间时间消耗分析
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
class Partition {
public:
    /*
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        // 没有保持稳定性
        ListNode * head = pHead, * tail = pHead;
        ListNode * p = pHead->next;
        while(p)
        {
            ListNode * temp = p->next;
            if(p->val < x)
            {
                p->next = head;
                head = p;
			}
            else
            {
                tail->next = p;
                tail = p;
            }
            p = temp;
        }
        tail->next = NULL;
        return head;
    }
    */

    ListNode* partition(ListNode* pHead, int x) {
        ListNode * before_start = NULL, * before_end = NULL;
        ListNode * after_start = NULL, * after_end = NULL;

        while(pHead)
        {
            ListNode * temp = pHead->next;
            pHead->next = NULL;
            if(pHead->val < x)
            {
                if(before_start == NULL)
                {
                    before_start = pHead;
                    before_end = pHead;
                }
                else
                {
                    before_end->next = pHead;
                    before_end = pHead;
                }
            }
            else
            {
                if(after_start == NULL)
                {
                    after_start = pHead;
                    after_end = pHead;
                }
                else
                {
                    after_end->next = pHead;
                    after_end = pHead;
                }
            }
            pHead = temp;
        }
        if(before_start == NULL)
            return after_start;
        before_end->next = after_start;
        return before_start;

    }

};

int main() {
    return 0;
}

//
// Created by cms on 17/8/30.
//

