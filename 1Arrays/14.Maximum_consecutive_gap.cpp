#include <bits/stdc++.h>
using namespace std;

int maximumGap(const vector<int> &A) {
    /*

    Brute Force approach will be to sort the array and find out the difference 
    b/w two consecutive numbers
    Time complexity = O(N*log(N))

    Now, if we know MIN and MAX value in the array
    then the maximum gap will be (MAX-MIN) when all the numbers are either
    MIN or MAX.

    let say the spacing b/w numbers is gap
    so they are arranged as 
    MIN, MIN + gap, MIN + 2*gap, .....  + MIN+(N-1)*gap (=MAX)

    thus we know that our answer will lie in    [gap, MAX-MIN]
    
    Now, if we know the answer is more than gap, what we do is create buckets of 
    size gap for ranges 

    [MIN, MIN+gap), [MIN+gap, MIN+2*gap) ....  
    
    so there will be N-1 buckets
    
    */


    const int N=A.size();
    if(N<2) return 0;

    int max_ = *max_element(A.begin(), A.end());
    int min_ = *min_element(A.begin(), A.end());
    float gap = (float)(max_- min_)/(float)(N-1);

    vector<int> bucketMin(N-1, INT_MAX), bucketMax(N-1, INT_MIN);

    for(int i=0;i<N;++i){
        if(A[i]==min_ or A[i]==max_)    continue;
        int index = (A[i]-min_)/gap;

        if(A[i]>bucketMax[index]){
            bucketMax[index]=A[i];
        }
        if(A[i]<bucketMin[index]){
            bucketMin[index]=A[i];
        }
    }

    int prev_=min_, ans=0;
    for(int i=0;i<N-1;++i){
        if(bucketMin[i]==INT_MAX)   continue;
        ans = max(ans, bucketMin[i]-prev_);
        prev_ = bucketMax[i];
    }
    ans = max(ans, max_-prev_);
    return ans;
}

