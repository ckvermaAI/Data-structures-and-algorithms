// https://www.interviewbit.com/problems/points-on-the-straight-line/

#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<int> &X, vector<int> &Y) {
    // A line can be formed by at least two points
    const int N = X.size();

    // Base case
    if(N<3) return N;

    int res=0;
    // use HashMap
    unordered_map<double,int> HashMap;

    for(int i=0;i<N;++i){
        HashMap.clear();
        for(int j=0;j<N;++j){
            if(i==j)    continue;
            
            double slope;

            // vertical lines or coinciding points
            if(X[i]==X[j])  slope=INT_MAX;

            // otherwise 
            else slope=(1.0*(Y[i]-Y[j]))/(1.0*(X[i]-X[j]));

            HashMap[slope]++;
            res = max(res, HashMap[slope]);

        }
    }

    // to count the point itself
    return res+1;
}
