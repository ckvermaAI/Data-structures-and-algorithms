// https://www.interviewbit.com/problems/palindrome-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


void leftRight(ListNode* head, ListNode* &left, ListNode* &right){
    // use floyd's fast and slow pointers
    // to find the mid point of the list
    ListNode* slow = head, *fast=head->next;

    while(slow and fast and fast->next){
        // move slow by one
        slow = slow->next;
        // move fast by one
        fast = fast->next->next;
    }

    right = slow->next;
    slow->next=NULL;
    left = head;

}

void reverseRight(ListNode* &head){
    // reverse the list
    ListNode* prev=NULL, *current=head, *next;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head=prev;
}

int lPalin(ListNode* A) {
    /*
    
    If we have the array and we have to find or
    check whether the current array is palindrome or not
    we will start with two pointers one on left and another 
    on right and will check that if both elements are same or 
    not till left < right

    as we have singly linked list we cannot traverse
    in backward direction.
    1) we can create another list which is reversed 
        and compare the elements of both list
        Time complexity = O(N)
        Space complexity = O(N)

    2) If we just split the left and right part and
    reverse the right part then we are done.
        and space complexity in this case will be O(1)   
    
    */
    
    // find the left and right part of the list
    ListNode* left , *right;
    leftRight(A, left, right);

    // reverse the right part
    reverseRight(right);

    // iterate through the left and right part
    // right part will be smaller or equal to left part
    while(right){
        if(left->val!=right->val)   return 0;
        else{
            left = left->next;
            right = right->next;
        }
    }

    return 1;

}