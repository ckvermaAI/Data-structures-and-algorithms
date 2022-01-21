// https://www.interviewbit.com/problems/insertion-sort-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    /*
    
    Insertion sort => starting from 2nd element in array/list
    find its suitable position in the left part of the array.
    At any given state the left half of the array is sorted.
    
    1. Create a new list and insert first element of original list in it
    2. now traverse through the original list and insert the other elements 
        of original list in correct posiion in new list

    */

    // create a dummy node which store the head of new list
    ListNode* newList = new ListNode(0);
    
    // our newList pointer ->next points to original list
    // we will check if at any point the order breaks (sorted in ascending order)
    // then we'll modify the order of list
    newList->next = head;

    // create two pointers 
    // one to iterate over the original list
    ListNode* current = head;
    
    // one pointer which points to start of the newList
    // this will help to find the correct position of other elements in the array
    ListNode* prev = newList;

    
    // Iterate over original list
    while(current){

        // check if the order breaks ( sorted in ascending order )
        if(current->next and current->val>current->next->val){

            // find correct position of "current->next" node
            while(prev->next and prev->next->val<current->next->val){
                prev = prev->next;
            }

            // after founding the correct position change the pointer
            // insert "current->next" in b/w  "prev" and "prev->next"
            ListNode* temp = prev->next;
            prev->next=current->next;

            current->next = current->next->next;
            prev->next->next = temp;

            // reset the prev
            prev=newList;
        }

        // order doesn't break then move forward
        else{
            current = current->next;
        }
    }



    return newList->next;

}
