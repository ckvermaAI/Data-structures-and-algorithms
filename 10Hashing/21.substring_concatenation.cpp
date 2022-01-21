// https://www.interviewbit.com/problems/substring-concatenation/

#include <bits/stdc++.h>
using namespace std;

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    const int wordL = B[0].size(), windowL=B.size()*wordL;

    vector<int> result;
    if(windowL==0 or A.size()<windowL)    return result;
    // create a HashMap to store the number of occurence of each word
    unordered_map<string,int> HashMap;

    for(int i=0;i<B.size();++i){
        HashMap[B[i]]++;
    }

    // we want to check whether different permutation of word
    // exist in window
    for(int i=0; i<A.size()-windowL+1; ++i){
        // "i" indicates the window
        unordered_map<string,int> remain = HashMap;
        string currentW = A.substr(i, windowL);

        for(int j=0;j<windowL; j+=wordL){
            // extarct the word
            string word_ = currentW.substr(j, wordL);
            // check if this word exist in the dictionary
            if(remain.find(word_)!=remain.end()){
                remain[word_]--;
                if(remain[word_]==0){
                    remain.erase(word_);
                }
            }
            
        }

        if(remain.size()==0){
            result.push_back(i);
        }
    }

    return result;

}
