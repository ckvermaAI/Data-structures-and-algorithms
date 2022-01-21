// https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
#include <bits/stdc++.h>
using namespace std;

int longest_palindrome_n3(string str){
    // brute force approach to find the longest palindromic string
    // time complexity O(N^3) and space complexity O(1)
    int N=str.size();
    int maxLength=1,start=0;
    for(int i=0;i<N;++i){
        for(int j=i;j<N;++j){
            bool pal=true;
            for(int k=0;k<(j-i+1)/2;++k)
                if(str[i+k]!=str[j-k])  pal=false;
            
            if(pal && (j-i+1)>maxLength){
                start=i;
                maxLength=j-i+1;
            }
        }
    }
    return maxLength;
}

int longest_palindrome_dp(string str){
    // Dynamic programming 
    // time complexity O(N^2) & space complexity is O(N^2)
    int N=str.size(), start=0, maxLength=1;
    bool table[N][N];
    memset(table, 0, sizeof(table));
    // because the smallest palindrome is of length 1
    for(int i=0;i<N;++i)    table[i][i]=1;
    for(int i=0;i<N-1;++i){
        if(str[i]==str[i+1]){
             table[i][i+1]=1;
             start=i;
             maxLength=2;
        }   
    } 

    for(int len=3;len<=N;++len){
        for(int i=0;i<N-len+1;++i){
            int j=i+len-1;
            if(table[i+1][j-1] && str[i]==str[j])
                table[i][j]=true;
            if(len>maxLength){
                maxLength=len;
                start=i;
            }
        }
    }
    return maxLength;
}




int main(){
    string A;
    cin>>A;
    // cout<<longest_palindrome_n3(A);
    cout<<longest_palindrome_dp(A);

    return 0;
}