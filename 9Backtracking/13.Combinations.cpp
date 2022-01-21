// https://www.interviewbit.com/problems/combinations/
#include <bits/stdc++.h>
using namespace std;

void genPerm(vector<vector<int>>&res, vector<int>&numbers, int start, vector<int>&temp, int B){
    // Base case
    if(temp.size()==B){
        res.push_back(temp);
        return;
    }

    for(int i=start;i<numbers.size();++i){
        temp.push_back(numbers[i]);
        genPerm(res, numbers, i+1, temp, B);
        temp.pop_back();
    }

    return;
}


vector<vector<int>> combine(int A, int B) {
    // to store the result
    vector<vector<int>> res;

    // Base case
    if(A<B) return res;

    // generate number b/w from [1, A]
    vector<int> numbers(A);
    for(int i=0;i<A;++i)    numbers[i]=i+1;

    // auxiliary array to store the number in recursion
    vector<int> temp;

    genPerm(res, numbers, 0, temp, B);

    return res;

}
