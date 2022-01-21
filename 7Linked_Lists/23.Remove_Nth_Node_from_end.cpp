// https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void removeN(ListNode* head, int steps){
    // steps indicates how many steps we need to move 
    // forward start from head of list;
    ListNode* current = head;
    while(steps--)    current = current->next;

    // delete the "current->next"
    ListNode* temp = current->next;
    current->next = temp->next;
    delete temp;
    return;
}

ListNode* removeNthFromEnd(ListNode* A, int B) {

    // first find the length/size of list
    int len=0;
    // create a pointer to iterate through the list
    ListNode* current = A;
    while(current){
        len++;
        current=current->next;
    }

    // Case-I if there is only one node in list
    if(len==1){
        return NULL;
    }
    
    // Case-II delete the first node
    else if(len<=B){
        ListNode* temp = A;
        A = A->next;
        delete temp;
    }

    // Case-III delete other nodes
    else{
        removeN(A, len-B-1);
    }

    
    return A;
}
