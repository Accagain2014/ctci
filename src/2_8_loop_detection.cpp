
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
    char val;
    Node * next;
    Node(char x) : val(x), next(NULL) {}

};

Node * loop_detection(Node * head)
{
    Node * p = head;
    unordered_set<Node *> record_set;

    while(p)
    {
        if(record_set.find(p) != record_set.end())
            return p;
        record_set.insert(p);
        p = p->next;
    }
    return NULL;

}


int main() {

   Node * head = new Node('A');
    head->next = new Node('B');
    head->next->next = new Node('C');
    head->next->next->next = new Node('D');
    head->next->next->next->next = new Node('E');
    head->next->next->next->next->next = head->next->next;

    printf("%c\n", loop_detection(head)->val);
   return 0;
}

//
// Created by cms on 17/9/2.
//

