
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

#define INF 0x3fffffff

using namespace std;

struct Node
{
    int val;
    Node * next;
    Node(int x) : val(x), next(NULL) {}
};

int find_Kth_to_last(Node * head, int k)
{
    // 扫两遍, 时间复杂度O(N),
    int n = 0, now = 0;
    Node * p = head;
    while(p)
    {
        n++;
        p = p->next;
    }
    if(k > n)
        return -1;
    p = head;
    while(p)
    {
        now++;
        if(now == n-k+1)
        {
            return p->val;
        }
        p = p->next;
    }

}
// 递归实现
Node * find_Kth_to_last_recursive(Node * head, int k, int & hav)
{
    if(head->next == NULL)
    {
        hav += 1;
        if(hav == k)
            return head;
        return NULL;
    }
    Node * p = find_Kth_to_last_recursive(head->next, k, hav);
    hav += 1;
    if(hav == k)
        return head;
    return p;
}


int main() {

    Node * head = new Node(1);
    head -> next = new Node(1);
    head -> next -> next = new Node(3);
    head -> next -> next -> next = new Node(2);
    head -> next -> next -> next -> next = new Node(3);
    head -> next -> next -> next -> next -> next = new Node(4);

    //head = remove_duplicate(head);

    printf("%d\n", find_Kth_to_last(head, 3));
    int hav = 0;
    printf("%d\n", find_Kth_to_last_recursive(head, 3, hav)->val);

    return 0;

}

//
// Created by cms on 17/8/23.
//

// 1 1 3 2 3 4
