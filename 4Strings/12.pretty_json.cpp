#include <bits/stdc++.h>
using namespace std;

vector<string> prettyJSON(string A) {
    vector <string> res;
    int braces=0;       // keep track of indentation
    for(int i=0,k;i<A.size();i+=k+1){
        // find the each element of resulting array
        
        for(k=0;i+k<A.size();++k){
            // special case - when closing brace is followed by a comma
            if((A[i+k]==']' || A[i+k]=='}') and A[i+k+1]==',') { k++;break; }
        
            // if current char is either opening braces or closing braces or a comma
            else if(A[i+k]=='{' || A[i+k]=='[' || A[i+k]==']' || A[i+k]=='}' || A[i+k]==',') break;

            // if next char is either opening braces or closing braces 
            else if(A[i+k+1]=='{' || A[i+k+1]=='[' || A[i+k+1]==']' || A[i+k+1]=='}') break;
        }

        // update the indendation 
        // if it is closing braces then indentation should decrease first then we make up the string
        if(A[i+k]==']' || A[i+k]=='}') braces--;

        // special case - when closing brace is followed by a comma
        if(A[i+k]==',' and (A[i+k-1]==']'||A[i+k-1]=='}') ) braces--;

        // add indentation and substring
        string temp=string(braces,'\t');
        temp+=A.substr(i,k+1);
        
        // add the string in resulting array
        res.push_back(temp);
        
        // if it is opening braces then indentation should increase after the current string
        if(A[i+k]=='{' || A[i+k]=='[') braces++;
    }
    
    return res;  
}
