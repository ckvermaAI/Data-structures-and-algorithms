#include <bits/stdc++.h>
using namespace std;

vector <string> solve(vector <string> &words, int L){
    vector<string> res;
    // loop to iterate over each line in resulting array
    for(int i = 0, k, l; i < words.size(); i += k) {    
        // i denotes the entry/position in final array
        // k iterates over all elements in each entry of resulting array
        cout<<"first i is "<<i<<"\n";
        for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= L - k; k++) {
            // start k=0 because it indicates the positions in each entry of resulting array
            // start l=0 because for each entry in resulting array we want to add L characters, l keeps the count of these characters
            // now actually we are iterating over (i+k)th element of words vector
            // and at each counter we want to make sure that current_characters (l)+ next word size should be less than L
            // but there is small catch if we have only word then it should be left justified but if there are more than 1 words then
            // we should also include ' ' into our consideration, hence there is "L-k" in l + words[i+k].size() <= L - k
            l += words[i+k].size();
        }
        // Now k provides us upper bound for the words in line i
        cout<<"second k is "<<k<<" l is "<<l<<"\n";
        string tmp = words[i];
        cout<<"tmp1 "<<tmp<<"\n";
        for(int j = 0; j < k - 1; j++) {
            if(i + k >= words.size()) tmp += " ";   // for last entry in the resulting array
            else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
            tmp += words[i+j+1];
        }
        tmp += string(L - tmp.size(), ' ');
        res.push_back(tmp);
        cout<<"\n";
    }
    return res;
}

int main(){
    int n,m;
    cin>>n;
    vector <string> A(n), B;
    for(int i=0;i<n;++i)    cin>>A[i];
    cin>>m;
    cout<<"OUTPUTS\n";
    B=solve(A,m);
    for(int i=0;i<B.size();++i){
        cout<<B[i]<<" ";
    }




}