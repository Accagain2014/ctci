
// Author :  Accagain
// Date   :  17/9/2
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
#include <unordered_set>

#define INF 0x3fffffff

using namespace std;

struct Node
{
    int val;
    Node * next;
    Node(int x): val(x), next(NULL){}

};

Node * find_insection(Node * head1, Node * head2)
{
    unordered_set<Node *> record_set;
    Node * p = head2;
    while(p)
    {
        record_set.insert(p);
        p = p->next;
    }
    p = head1;
    while(p)
    {
        if(record_set.find(p) != record_set.end())
            return p;
        p = p->next;
    }
    return NULL;
}

int main() {

    Node * head1 = new Node(0);
    head1->next = new Node(1);
    head1->next->next = new Node(2);

    Node * head2 = new Node(3);
    head2->next = head1->next;

    printf("%d\n", find_insection(head1, head2)->val);
    return 0;
}

//
// Created by cms on 17/9/2.
//

