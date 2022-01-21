// https://www.interviewbit.com/problems/sort-binary-linked-list/

#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* solve(ListNode* A) {
    // traverse once through the linked list and
    // count zeros and ones
    int zeros=0, ones=0;

    // traverse to count zero and ones
    ListNode* current = A;
    while(current){
        if(current->val)    ones++;
        else    zeros++;

        // move to next element
        current = current->next;
    }

    // again traverse to fill zeros and ones
    current = A;

    // filling zeros
    while(zeros--){
        current->val = 0;
        current = current->next;
    }
    // filling ones
    while(ones--){
        current->val = 1;
        current = current->next;
    }

    return A;
}