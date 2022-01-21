// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* deleteDuplicates(ListNode* A) {
    // create a new head 
    ListNode head(-1);
    // create a pointer to new head
    ListNode* p = &head;

    // create a pointer to traverse the original link
    ListNode* current = A;    
    while(current){
        ListNode* temp=current;
        int count = 0;
        while(temp and temp->val==current->val){
            temp = temp->next;
            count++;
        }
        // if there is no duplicate of element pointing
        // by current
        if(count==1){
            // append to new list
            p->next = current;
            p = p->next;
            current = current->next;

            p->next = NULL;
        }
        else{
            // shift the current 
            current = temp;
        }
    }

    return head.next;

}