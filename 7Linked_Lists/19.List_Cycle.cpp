// https://www.interviewbit.com/problems/list-cycle/

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL){}
};

ListNode* detectCycle(ListNode* A) {
    /*
    
    Method-I =>
    use HashMap to store which nodes are visited
    once we enounter a node which is already visited we know
    that there is cycle.
    And the first node which will apprear again is first node in 
    the cycle
    Time complexity = O(N)
    Space complexity = O(N)

    
    Method-II =>
    Use floyd's slow and fast pointers to detect if there is cycle
    1) if there is cycle these will meet a point in the cycle
    2) if there is not a cycle then fast will become NULL

    To find the first/starting point in the cycle
    1) find the cycle length
    2) use two pointers one at the starting point of list
        another shifted to cycle length position forward
        These pointers will meet at the starting point of the cycle

    */
    ListNode* slow = A, *fast = A->next;
    while(fast and fast->next and slow!=fast){
        slow = slow->next;
        fast = fast->next->next;
    }

    // if there is no cycle
    if(fast!=slow)  return NULL;

    // Otherwise there is cycle
    // find the length of cycle
    int length=1;
    while(slow->next!=fast){
        length++;
        slow = slow->next;
    }

    // traverse two nodes - move these with same pace
    slow = A, fast = A;
    while(length--){
        fast=fast->next;
    }

    while(slow!=fast){
        slow=slow->next;
        fast = fast->next;
    }

    return slow;

}
