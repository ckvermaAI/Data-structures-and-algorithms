// https://www.interviewbit.com/problems/partition-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int num) {
    /*
    
    Simple idea - create two list one having elements less than B
    or second having element greater or equal to B

    Now, to create these list we need to find a way to fix or should 
    retain the head of two list

    One thing we can do is to "create a new ListNode with dummy value"
    and use this "node.next" as our head pointer of new create list

    In this way we can access the head of the list anytime 
    head of list == node.next
    
    */

    // create two dummy node which stores the head pointer
    // of newly created list
    ListNode headl(-1), headg(-1);
    
    // two pointers to traverse through the list
    ListNode* A = &headl, *B = &headg;

    // Pointer to traverse the given list
    ListNode* current = head;

    while(current){
        if(current->val<num){
            A->next = current;
            A = A->next;
        }
        else if(current->val>=num){
            B->next = current;
            B = B->next;
        }
        current = current->next;
    }

    // Now merge the two list
    B->next = NULL;
    A->next = headg.next;

    return headl.next;

}