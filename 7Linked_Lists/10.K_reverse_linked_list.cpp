// https://www.interviewbit.com/problems/k-reverse-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};

ListNode *reverseListWhole(ListNode *A){
    ListNode *current=A, *prev=NULL;
    while(current){
        ListNode *temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;

    }
    return prev;
}

ListNode* reverseList(ListNode* A, int B) {
    // Base case
    if(B==1)   return A;

    // Find the length of linked list
    ListNode *current=A;
    int count=0, slots, tempB;
    while(current){ count++; current=current->next;}

    // Find the different number of slots
    slots=count/B;

    // create new head
    ListNode fakehead(0);
    ListNode *start=&fakehead;

    ListNode *cstart=A, *cend=A;
    while(slots){
        tempB=B-1;
        while(tempB){  tempB--; cend=cend->next;}
        
        ListNode *temp=cend->next;
        cend->next=NULL;

        // Reverse this segment
        ListNode* res=reverseListWhole(cstart);      

        // append to the new List
        start->next=res;
        while(start->next){start=start->next;}

        // update the variables
        cstart=temp;
        cend=temp;
        slots--;
    }

    return fakehead.next;

}