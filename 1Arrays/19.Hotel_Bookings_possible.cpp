// https://www.interviewbit.com/problems/hotel-bookings-possible/
#include <bits/stdc++.h>
using namespace std;

struct dates{
    int t, ad;
    // t indicates time and 
    // ad indicates whether it is arrival(1)
    // or departure(0)
    dates(int s, int e): t(s), ad(e)   {}
};

bool compare(dates &A, dates &B){
    // requires when sorting the array
    if(A.t==B.t)    return A.ad<B.ad;
    return A.t<B.t;
}

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    const int N = arrive.size();
    // create a vector of dates
    vector<dates> time;

    for(int i=0;i<N;++i){
        time.push_back({arrive[i], 1});
        time.push_back({depart[i],0});
    }

    // sort the array
    sort(time.begin(), time.end(), compare);

    // this is the minimum number of rooms required
    int rooms=0, active=0;
    for(auto &x:time){
        // write logic to obtain the number of rooms required
        if(x.ad==1){
            // New room required
            active++;
            rooms = max(rooms, active);
        }
        else if(x.ad==0){
            // otherwise decrease the "active" rooms
            active--;
        }
    }

    // Not possible
    if(rooms>K)     return 0;

    // Possible
    return 1;
}
