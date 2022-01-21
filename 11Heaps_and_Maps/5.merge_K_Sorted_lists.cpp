// https://www.interviewbit.com/problems/merge-k-sorted-lists/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeKLists(vector<ListNode*> &A) {
    // Base case
    // if lists are empty 
    if(A.empty() or A[0]==NULL)     return NULL;

    typedef tuple<int,ListNode*> tu;

    // create a priority queue to store the first elements
    // of each list
    priority_queue<tu, vector<tu>, greater<tu>> pq;

    // insert the elements of all rows
    for(int i=0;i<A.size();++i){
        pq.push({A[i]->val, A[i]});
    }

    // to store the new list
    ListNode head(0);
    ListNode* start = &head;

    while(!pq.empty()){
        int val; ListNode* temp;
        tie(val, temp) = pq.top();
        pq.pop();

        start->next = temp;
        start=start->next;

        if(temp->next){
            pq.push({temp->next->val, temp->next});
        }

        start->next = NULL;

    }

    return head.next;

}



