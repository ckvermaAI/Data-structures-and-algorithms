// https://www.interviewbit.com/problems/copy-list/

// https://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
// https://www.geeksforgeeks.org/clone-linked-list-next-arbit-pointer-set-2/
// https://www.geeksforgeeks.org/clone-linked-list-next-random-pointer-o1-space/
#include <bits/stdc++.h>
using namespace std;


struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };


RandomListNode* copyRandomList(RandomListNode* A) {
    // create new Nodes and store these nodes in a HashMap
    // {old nodes, new Nodes}
    unordered_map<RandomListNode*, RandomListNode*> HashMap;
    
    // iterate through the list to create new Nodes 
    RandomListNode* current = A;
    while(current){
        RandomListNode* temp = new RandomListNode(current->label);
        HashMap[current]=temp;
        current = current->next;
    }

    // reiterate thorugh the array to create links
    current = A;
    while(current){
        RandomListNode* nextNode = current->next;
        RandomListNode* randomNode = current->random;

        // setting nextNode for current node
        if(nextNode==NULL){
            HashMap[current]->next=NULL;
        }
        else{
            HashMap[current]->next=HashMap[nextNode];
        }

        // setting randomNode for current node
        if(randomNode==NULL){
            HashMap[current]->random=NULL;
        }
        else{
            HashMap[current]->random=HashMap[randomNode];
        }

    }
    return HashMap[A];
}
