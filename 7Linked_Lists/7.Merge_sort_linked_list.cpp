// https://www.interviewbit.com/problems/sort-list/
// https://www.geeksforgeeks.org/merge-sort-for-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void LeftRightSplit(ListNode* head, ListNode* &left, ListNode* &right){
    // split the list into two halves 
    ListNode* slow = head;
    ListNode* fast = head->next;

    // Move fast by two elements 
    // and slow by one element
    while(fast){
        fast = fast->next;
        if(fast){
            slow = slow->next;
            fast = fast->next;
        }
    }

    // assign left and right pointers
    left = head;
    right = slow->next;

    // split the two list 
    slow->next=NULL;
    
}

ListNode* Merge(ListNode* left, ListNode* right){
    ListNode* result = NULL;

    // Base cases
    if(left==NULL)  return right;
    else if(right==NULL)    return left;

    // insert the smaller element in result
    // and use recursion
    if(left->val<=right->val){
        result = left;
        result->next = Merge(left->next, right);
    }
    else{
        result = right;
        result->next = Merge(left, right->next);
    }
    return result;
}

void MergeSort(ListNode* &head){
    // To sort the linkedList in O(N*log(N))
    // complexity and space complexity = O(1)
    // while implementing the MergeSort on array
    // we need extra space of O(N) due to merging
    // two sorted array

    // Base case
    // empty list or list having one element is sorted
    if(head==NULL or head->next==NULL)  return;

    // recursion
    // divide the list into two halves
    ListNode* left, *right;
    LeftRightSplit(head, left, right);

    // sort the two halves recursively
    MergeSort(left);
    MergeSort(right);

    // merge the two sorted halves
    head = Merge(left, right);

}


ListNode* sortList(ListNode* A) {
    MergeSort(A);
    return A;
}
