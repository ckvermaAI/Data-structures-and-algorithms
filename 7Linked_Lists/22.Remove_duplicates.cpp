// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* A) {
    // create new head for the list
    ListNode head(-1);
    // pointer pointing to this new list
    ListNode *p = &head;

    // create a pointer to iterate through the original list
    ListNode* current = A;
    while(current){
        ListNode* temp = current;
        int count = 0;
        while(temp and temp->val==current->val){
            temp = temp->next;
            count++;
        }

        p->next = current;
        p = p->next;

        // case-1 no duplicates
        if(count==1)    current = current->next;

        // case -2 if there are duplicates
        else    current = temp;

        p->next = NULL;
        
    }
    return head.next;
    
}