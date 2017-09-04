
// Author :  Accagain
// Date   :  17/8/23
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
#include <unordered_set>

#define INF 0x3fffffff

using namespace std;

struct Node
{
    int val;
    Node * next;
    Node(int x): val(x), next(NULL){}

};

Node * remove_duplicate(Node * head)
{
    // use hash map to store whether a val emerges
    unordered_set<int> set;
    Node * p = head;
    Node * q = head -> next;
    set.insert(p->val);
    while(q)
    {
        if(set.find(q->val) != set.end())
            p->next = q->next;
        else
        {
            set.insert(q->val);
            p = p->next;
        }
        q = q->next;

    }
    return head;
}

// follow up, no buffer, use O(N^2) time complexity

Node * remove_without_buffer(Node * head)
{
    Node * p = head;
    Node * q = head -> next;

    while(q)
    {
        bool flag = false;

        for(auto it = head; it != q; it=it->next)
        {
            if(it->val == q->val)
            {
                flag = true;
                p->next = q->next;
                break;
            }
        }
        //printf("%d...\n", q->val);
        if(!flag)
            p = p->next;
        q = q->next;
    }
    return head;
}


int main() {

    Node * head = new Node(1);
    head -> next = new Node(1);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> next = new Node(3);
    head -> next -> next -> next -> next -> next = new Node(4);

    //head = remove_duplicate(head);
    head = remove_without_buffer(head);
    while(head)
    {
        printf("%d\n", head->val);
        head = head -> next;
    }
    return 0;
}

//
// Created by cms on 17/8/23.
//
/*

 1 1 3 2 3 4

 */

