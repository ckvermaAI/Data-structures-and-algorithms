// https://www.interviewbit.com/problems/merge-two-sorted-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// This is iterative version
ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
    // Iterative solution
    // create new head of the list
    ListNode head(-1);
    // Pointer to this new head
    ListNode* p = &head;

    // iterate through the list
    while(head1 and head2){
        // find the lowest element and append that to result
        if(head1->val<=head2->val){
            // if lowest value in list1
            p->next = head1;
            head1=head1->next;
        }
        else{
            // if lowest value in list2
            p->next = head2;
            head2 = head2->next;
        }
        p=p->next;
        // p->next = NULL;
    }

    // now insert the remaining elements in the list
    while(head1){
        p->next = head1;
        head1=head1->next;

        p=p->next;
        // p->next = NULL;
    }

    while(head2){
        p->next = head2;
        head2=head2->next;

        p=p->next;
        // p->next = NULL;
    }

    return head.next;
}

// This is recursive version
ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    // This is recursion version 
    ListNode* current = NULL;

    // Base case
    if(A==NULL) return B;
    if(B==NULL) return A;

    if(A->val<=B->val){
        current = A;
        current->next = mergeTwoLists(A->next, B);
    }
    else{
        current = B;
        current->next = mergeTwoLists(A, B->next);
    }

    return current;

}