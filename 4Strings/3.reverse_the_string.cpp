// https://www.interviewbit.com/problems/reverse-the-string/
#include <bits/stdc++.h>
using namespace std;

pair<int,int> lastWord(string A, int endOfStr){
    
    const int N = A.length();
    int low=-1, high=-1;
    
    // finding the end of word
    for(int i=endOfStr;i>=0;--i){
        if(A[i]!=' '){
            high=i;
            break;
        }
    }
    if(high==-1)    return {low, 0};

    // finding the start of word
    for(int i=high-1;i>=0;--i){
        if(A[i]==' '){
            low=i+1;
            break;
        }
    }

    if(low==-1)     low=0;

    return {low, (high-low+1) };
}

string solve(string A) {
    /*
    
    If we know how to extract the last word
    then we are done

    Keep om extracting the last word and add it to result
    
    */
    string res="";
    int EndOfString=A.length()-1;
    while(EndOfString>=0){
        pair<int,int> p = lastWord(A, EndOfString);
        int start = p.first, len=p.second;
        if(start>=0)
            res += (A.substr(start, len)+" ");
        EndOfString = start-1;
    }
    
    return res.substr(0,res.length()-1);

}
