// https://www.interviewbit.com/problems/anagrams/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> anagrams(const vector<string> &A) {
    // To store (A[i], Encoding[A[i]])
    unordered_map<string,string> Encodings;
    // To store (Encoding[A[i]], position in final array)
    unordered_map <string,int> encodingsToPos;
    int unique=0;
    for(int i=0;i<A.size();++i){
        string x=A[i];
        
        // generating encodings
        vector <int> temp(26,0);
        for(int i=0;i<x.length();++i) temp[x[i]-'a']++;
        string temp_="";
        for(int &x:temp)    temp_+=to_string(x);
        // encodings are stored in temp_ as strings

        // validating if encoding are already present
        // otherwise increase the unique words/different anagrams
        if(encodingsToPos.find(temp_)==encodingsToPos.end()){
            encodingsToPos[temp_]=unique;
            unique++;
        }
        Encodings[x]=temp_;
    }
    vector<vector<int>> res(unique);
    for(int i=0;i<A.size();++i){
        int pos=encodingsToPos[Encodings[A[i]]];
        res[pos].push_back(i+1);
    }
    return res;
}

int main(){
    vector<string> A={"cat", "dog", "god", "tca"};
    vector<vector<int>> res=anagrams(A);

    for(auto &x:res){
        for(int &y:x)   cout<<y<<" ";
        cout<<"sdjbsd\n";
    }

    return 0;
}
