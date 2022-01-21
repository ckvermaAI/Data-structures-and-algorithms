// https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
#include <bits/stdc++.h>
using namespace std;

string Longest_palindromic_substring(string str){
    // time complexity O(N^2) && space complexity O(1)
    int N=str.size(),start=0, maxLength=1;
    int low,high;

    for(int i=1;i<N;++i){
        // even length palindrome
        low=i-1;
        high=i;
        while(low>=0 and high<N and str[low]==str[high]){
            low--;
            high++;
        }
        low++;high--;
        if(str[low]==str[high] and (high-low+1)>maxLength){
            start=low;
            maxLength=high-low+1;
        }
        // odd length palindrome
        low=i-1;
        high=i+1;
        while(low>=0 and high<N and str[low]==str[high]){
            low--;
            high++;
        }
        low++;high--;
        if(str[low]==str[high] and (high-low+1)>maxLength){
            start=low;
            maxLength=high-low+1;
        }
    }
    return str.substr(start,maxLength);
}

int main(){
    string A;
    cin>>A;
    cout<<Longest_palindromic_substring(A);


}