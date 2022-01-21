// https://www.interviewbit.com/problems/colorful-number/
#include <bits/stdc++.h>
using namespace std;

int colorful(int A) {
    vector <int> num;
    unordered_map<int, int> counter;
    while(A){
        num.push_back(A%10);
        A/=10;}
    for(int i=0;i<num.size();++i){
        int mul=num[i];
        for(int j=i+1;j<num.size();++j){
            counter[mul]++;
            if(counter[mul]>1)   return 0;
            mul=mul*num[j];
        }
        counter[mul]++;
        if(counter[mul]>1)   return 0;
    }
    return 1;
}


int main(){
    cout<<colorful(123);
    return 0;
}