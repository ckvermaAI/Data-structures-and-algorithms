#include <bits/stdc++.h>
using namespace std;

int steps(int source, int step, int dest){
    // recursion 
    if(abs(source)>dest)
        return numeric_limits<int>::max();
    if(source==dest)
        return step;
    int pos=steps(source+step+1, step+1, dest);
    int neg=steps(source-step-1, step+1, dest);
    return min(pos,neg);
}


int solve(int A) {
    int x = sqrt((long long int)8*A+1);
    cout<<A<<" "<<(long long int)8*A<<" "<<x<<"\n";
    A=max(A,(-1)*A);
    int direct_step = ceil((sqrt(8*A + 1) - 1)/2);
    int state_ds = direct_step*(direct_step+1)/2;
    int d = (state_ds-A);
    if(d%2==0) return direct_step;
    else{
        if((d+direct_step+1)%2==0) return direct_step+1;
        else return direct_step+2;
    }
}


int main(){
    cout<<solve(900028145);

    return 0;
}