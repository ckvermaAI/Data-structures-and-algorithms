// My Code school

// Reverse a linked list - Iterative method
// https://www.youtube.com/watch?v=sYcOK51hl-A&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=9

// Reverse a linked list using recursion
// https://www.youtube.com/watch?v=KYH83T4q6Vs&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=11

#include "Linked_list_implementation.cpp"

ListNode* reverseIterative(ListNode* head){
    // Time Complexity O(N)
    // Space complexity O(1)
    // One by one reverse each link in the list
    ListNode* prev=NULL, *current=head, *next;
    while(current){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

void reverseRecursion(ListNode* &head, ListNode*current){
    // Time complexity O(N)
    // Space complexity O(N)  - Different function recursion calls are stored in a implicit stack
    // ( Similarly we can create another approach where we can use a explicit stack to store all elements to list
    //   and perform operation in similiar manner )
    // Base condition
    if(current->next==NULL){
        // if we reach at the last node set head pointer to this node
        head=current;
        return;
    }
    // recursion
    reverseRecursion(head,current->next);
    // this will be executed in reverse direction of current list
    ListNode* temp=current->next;
    temp->next=current;
    current->next=NULL;
}


int main(){
    ListNode* head=NULL;
    insertBegin(head,2);
    insertBegin(head,4);
    insertBegin(head,6);
    insertBegin(head,5);
    ShowList(head);
    // head=reverseIterative(head);
    reverseRecursion(head, head);
    cout<<"\n";
    ShowList(head);

}