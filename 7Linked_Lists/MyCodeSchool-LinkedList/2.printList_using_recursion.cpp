// My code school
// Print elements of a linked list in forward and reverse order using recursion
// https://www.youtube.com/watch?v=K7J3nCeRC80&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=10

#include "Linked_list_implementation.cpp"

void printForwardRecursion(ListNode* head){
    if(head==NULL)  return;
    cout<<head->data<<" ";
    printForwardRecursion(head->next);
}

void printReverseRecursion(ListNode* head){
    if(head==NULL)  return;
    printReverseRecursion(head->next);
    cout<<head->data<<" ";
}

int main(){
    ListNode* head=NULL;
    insertAtEnd(head,2);
    insertAtEnd(head,4);
    insertAtEnd(head,6);
    insertAtEnd(head,5);
    printForwardRecursion(head);
    cout<<"\n";
    printReverseRecursion(head);
    
    return 0;
}