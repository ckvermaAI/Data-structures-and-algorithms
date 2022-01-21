// https://www.interviewbit.com/problems/reverse-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverseList(ListNode* head) {
    // iterative version 
    // Time complexity = O(N) and space complexity = O(1)
    
    // reverse one link at a time starting from head of list
    ListNode* prev=NULL, *current=head, *next;
    while(current){
        next = current->next;
        current->next = prev;
        prev=current;
        current=next;
    }
    return prev;
}
