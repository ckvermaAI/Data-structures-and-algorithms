// https://www.interviewbit.com/problems/intersection-of-linked-lists/
// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
    /*
    
    Idea is to iterate over both the list twice
    
    so lets say we have 2 pointers "s" and "t" =>
    1) initially "s" points to A and "t" points to B
    2) when any of the pointer reaches to end of list 
       we redirect that pointer to head of another list

    If the size of list A is N and size of list B is M
    then both pointer will traverse all the M+N elements 
    in both list 
    a) when there is no common element both "s" and "t" will equal
        only when both element traversed the "M+N" element
        or s=t=NULL
    
    b) and if there is common node b/w two linked list then "s" and "t"
       will meet at this node
    
    */

    ListNode* s = A, *t = B;

    while(s!=t){
        // traverse the "s" pointer
        if(s==NULL) s = B;
        else s = s->next;

        // traverse the "t" pointer
        if(t==NULL) t = A;
        else  t = t->next;
    }

    return s;
    
}
