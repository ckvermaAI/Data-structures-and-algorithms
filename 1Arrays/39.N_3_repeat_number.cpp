// https://www.interviewbit.com/problems/n3-repeat-number/

#include <bits/stdc++.h>
using namespace std;



int repeatedNumber(const vector<int> &A) {
    /*
    Basic Idea - if we remove three distinct numbers
    from the array then the N/3 repeat number does not change 
    
    */

    const int N=A.size();
    float lim=N/3;
    map <int, int> counter;
    // list <pair<int, int>> counter;
    for(int i=0;i<N;++i){
        int ele=A[i];
        if(counter.size()<3){
            if(counter.find(ele)!=counter.end())  
                counter[ele]++;
            else
                counter[ele]=1;
        }
        if(counter.size()==3){
            vector <int> key_;
            for(auto it=counter.begin();it!=counter.end();++it){
                it->second--;
                if(it->second==0)
                    key_.push_back(it->first);
            }
            for(int i=0;i<key_.size();++i)
                counter.erase(key_[i]);
            
        }

    }
    for(auto it=counter.begin();it!=counter.end();++it){
        int count_=0;
        for(int i=0;i<N;++i){
            if(A[i]==it->first)
                count_++;
        }
        if((float)count_>lim)
            return it->first;
    }
    
    return -1;

}
