#include <bits/stdc++.h>
using namespace std;

vector<int> sortKSortedArray(vector<int> A, int k) {
  // Write your code here.
	if(k>=A.size()){
		sort(A.begin(), A.end());
		return A;
	}
	
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0;i<k;++i)	pq.push(A[i]);
	
	int start=0, end=k;
	while(start<A.size()){
		int temp=pq.top();
		pq.pop();
		A[start++]=temp;
		if(end<A.size())
			pq.push(A[end++]);
		
	}
	
  return A;
}

int main(){

    vector<int> A = {3, 2, 1, 5, 4, 7, 6, 5};

    vector<int> B = sortKSortedArray(A, 3);

    for(int &x:B)   cout<<x<<" ";
    

    return 0;
}