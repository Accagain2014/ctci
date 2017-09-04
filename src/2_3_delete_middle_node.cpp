
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

struct Node
{
    int val;
    Node * next;
    Node(int x): val(x), next(NULL) {}
};

Node * delete_middle_node(Node * head)
{
    Node * slow_pointer = head;
    Node * fast_pointer = head->next;
    if(fast_pointer == NULL)
        return NULL;

    fast_pointer = fast_pointer->next;
    if(fast_pointer == NULL)
        return slow_pointer->next;

    while(fast_pointer)
    {
        fast_pointer = fast_pointer->next;
        if(fast_pointer == NULL)
            break;
        fast_pointer = fast_pointer->next;
        if(fast_pointer == NULL)
            break;
        slow_pointer = slow_pointer->next;
    }
    slow_pointer->next = slow_pointer->next->next;
    return head;

}

bool removeNode(Node * pNode) {
    // write code here
    if(pNode == NULL || pNode->next == NULL)
        return false;
    pNode->val = pNode->next->val;
    pNode->next = pNode->next->next;
    return true;

}

int main() {

    Node * head = new Node(1);
    head->next = new Node(2);
//    head->next->next = new Node(3);
//    //head->next->next->next = new Node(4);
//    head->next->next->next = new Node(5);

    Node * ans = delete_middle_node(head);
    while(ans)
    {
        printf("%d ", ans->val);
        ans = ans->next;
    }

    return 0;
}

//
// Created by cms on 17/8/30.
//

