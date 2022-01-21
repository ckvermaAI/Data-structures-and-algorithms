// https://www.interviewbit.com/problems/merge-intervals/
#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> cleaning(vector<Interval>&intervals, Interval newInterval, int count, int N){
    vector<Interval> res(N-count);
    int i=0;

    for(auto &x:intervals){
        if(x.start==-1 and x.end==-1)   continue;
        else{
            res[i++]=x;
        }
    }

    bool found = false;

    if(res[0].start>newInterval.end){
        res.insert(res.begin(), newInterval);
        found = true;
    }

    for(int i=0;i<res.size()-1 and !found;++i){
        if(res[i].end<newInterval.start and res[i+1].start>newInterval.end){
            // after current interval
            res.insert(res.begin()+i+1, newInterval);
            found = true;
        }
    }

    if(res.back().end<newInterval.start and !found){
        res.insert(res.end(), newInterval);
    }
    return res;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    
    if(newInterval.start>newInterval.end){
        newInterval = Interval(newInterval.end, newInterval.start);
    }

    const int N=intervals.size();
    // Base case
    if(N==0)    return vector<Interval> {newInterval};

    // Otherwise iterate through all the elements in "intervals" array
    int count = 0;
    for(int i=0;i<N;++i){
        auto &x = intervals[i];
        if(x.start>newInterval.end or x.end<newInterval.start)
            continue;   // intervals are not intersecting
        else{
            // cout<<"here";
            // intervals are intersecting and merge these intervals
            int newStart = min(x.start, newInterval.start);
            int newEnd = max(x.end, newInterval.end);
            
            x = Interval(-1, -1);       // because this interval will get deleted
            newInterval = Interval(newStart, newEnd);
            count++;
        }
    }
    if(count==N){
        return vector<Interval> {newInterval};
    }

    return cleaning(intervals, newInterval, count, N);
}