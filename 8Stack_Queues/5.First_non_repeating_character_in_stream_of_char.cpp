// https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/

#include <bits/stdc++.h>
using namespace std;

string solve(string A) {
    string res="";
    vector <int> counter(26,0);
    queue <int> nums;
    for(int i=0;i<A.size();++i){
        if(counter[A[i]-'a']==0){
            nums.push(A[i]);
        }
        counter[A[i]-'a']++;
        while(!nums.empty()){
            if(counter[nums.front()-'a']>1) nums.pop();
            else break;
        }
        if(!nums.empty()) res+=nums.front();
        else res+='#';
    }

    return res;
}
