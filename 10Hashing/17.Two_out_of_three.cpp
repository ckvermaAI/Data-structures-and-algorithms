#include <bits/stdc++.h>
using namespace std;

struct vec{
    vector<int> x;
    vec(){
        x={0,0,0};
    }
};

vector<int> solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    unordered_map<int,vec>num;
    for(int i=0;i<A.size();++i){
        vec temp =num[A[i]];
        temp.x[0]++;
        num[A[i]]=temp;
    }
    for(int i=0;i<B.size();++i){
        vec temp =num[B[i]];
        temp.x[1]++;
        num[B[i]]=temp;
    }
    for(int i=0;i<C.size();++i){
        vec temp =num[C[i]];
        temp.x[2]++;
        num[C[i]]=temp;
    }
    vector <int> result;
    for(int i=1;i<=100000;++i){
        if(num.find(i)!=num.end()){
            vector <int> temp=num[i].x;
            int count= max(max(min(temp[0],temp[1]),min(temp[1],temp[2])),min(temp[2],temp[0]));
            // to include only one occurence
            if(count>=1)    result.push_back(i);
            // to include all the occurence
            // while(count){
                // result.push_back(i);
                // count--;
            // }
        }
    }
    return result;
}
