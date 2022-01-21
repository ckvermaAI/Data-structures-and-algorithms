// https://www.interviewbit.com/problems/substring-concatenation/
#include <bits/stdc++.h>
using namespace std;

vector<int> findSubstring(string A, const vector<string> &B) {
    // Brute Force approach
    vector <int> res;
    int N=B.size(), len=N*(B[0].length());
    // Base case
    if(len>A.size())    return res;
    
    // General case 
    string dummy="$";
    for(int i=0;i<A.size()-len+1;++i){
        string temp=A.substr(i,len);
        int count=0;
        for(int j=0;j<B.size();++j){
            if(temp.find(B[j])!=string::npos){
                count++;
                temp.replace(temp.find(B[j]),B[0].size(),dummy);
            }
        }
        if(count==B.size()) res.push_back(i);
    }
    
    return res;
}

vector<int> fast(string A, const vector<string> &B) {
    // Using Hash Table
    vector <int> res;
    int N=B.size(), len=N*(B[0].length());
    // Base case
    if(len>A.size())    return res;
    
    // Storing the counts of each string in B
    unordered_map <string,int> globalM;
    for(string x:B) globalM[x]++;
    
    // General case 
    for(int i=0;i<A.size()-len+1;++i){
        string current=A.substr(i,len);
        unordered_map<string,int> localM=globalM;
        
        for(int j=0;j<len;j+=B[0].size()){
           string temp= current.substr(j,B[0].size());
           if(localM.find(temp)!=localM.end()){
               localM[temp]--;
               if(localM[temp]==0)  localM.erase(temp);
           }
           else break;
        }
        if(localM.size()==0) res.push_back(i);

    }
    
    return res;
}

int main(){
    string A="barfoothebarfooman";
    vector <string> B={"foo", "bar"};
    // string A="aaaaaaaaaaaaaaaaaaaaa";
    // vector <string> B={"aa", "aa"};
    // vector <int> res=findSubstring(A,B);
    vector <int> res=fast(A,B);
    for(int x:res)  cout<<x<<" ";
    return 0;
}
