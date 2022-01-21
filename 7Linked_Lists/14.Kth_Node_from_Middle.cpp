// https://www.interviewbit.com/problems/kth-node-from-middle/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getMid(ListNode* head){
    ListNode *slow = head, *fast = head->next;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int solve(ListNode* A, int B) {
    // length of linked list
    int len=0;
    ListNode* current=A;
    while(current){
        len++; 
        current = current->next;
    }

    // Base case
    if(len/2<B)     return -1;

    // find the middle element using floyd's 
    // fast and slow pointers
    ListNode* mid = getMid(A);

    int numberOfShift = len/2-B;
    current = A;
    while(numberOfShift--){
        current = current->next;
    }
    return current->val;
}
