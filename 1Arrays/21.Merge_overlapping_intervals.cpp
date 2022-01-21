// https://www.interviewbit.com/problems/merge-overlapping-intervals/
#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };

void show(vector <Interval> A){
    int n=A.size();
    for(int i=0;i<n;++i)
        cout<<A[i].start<<" "<<A[i].end<<"\n";
}

bool IntervalSort(Interval A, Interval B){
    return A.start<B.start;
}

vector<Interval> merge(vector<Interval> &A) {
// void merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    sort(A.begin(),A.end(), IntervalSort);
    vector <bool> keep(n,true);
    vector <Interval> B;
    for(int i=1;i<n;++i){
        if(A[i].start<=A[i-1].end && A[i].start>=A[i-1].start){
            A[i].start=A[i-1].start;
            A[i].end=max(A[i].end,A[i-1].end);
            keep[i-1]=false;
        }
    }
    for(int i=0;i<n;++i){
        if(keep[i])
            B.push_back(A[i]);
    }
    return B;

}

int main(){
    int n;
    cin>>n;
    vector <Interval> A(n), B;
    for(int i=0;i<n;++i)
        cin>>A[i].start>>A[i].end;

    cout<<"OUTPUTS\n";
    show(A);
    B=merge(A);
    cout<<"After calling function\n";
    show(B);


    return 0;
}
