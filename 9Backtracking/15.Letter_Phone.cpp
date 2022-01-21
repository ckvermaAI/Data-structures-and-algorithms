// https://www.interviewbit.com/problems/letter-phone/

#include <bits/stdc++.h>
using namespace std;

void genPerm(vector<string> &res, vector<vector<char>>&mapping, string &A, string &temp, int start){
    
    // if number is fully parsed
    if(A.length()==temp.length()){
        res.push_back(temp);
        return;
    }

    for(int i=start;i<A.length();++i){
        vector<char> dictionary = mapping[A[i]-'0'];
        for(int j=0;j<dictionary.size();++j){
            temp += dictionary[j];
            genPerm(res, mapping, A, temp, i+1);
            temp.pop_back();
        }
    }
    

}

vector<string> Solution::letterCombinations(string A) {
    // to store the result
    vector<string> res;

    // mapping from number to alphabets/digits

    vector<vector<char>> mapping ={{'0'},           // 0
                                    {'1'},          // 1
                                    {'a','b','c'},  // 2
                                    {'d','e','f'},  // 3
                                    {'g','h','i'},   // 4
                                    {'j','k', 'l'},  // 5
                                    {'m','n','o'},   // 6
                                    {'p','q','r','s'}, // 7
                                    {'t','u','v'},      // 8
                                    {'w','x','y','z'}   // 9
                                    };

    // to store the string in recursion
    string temp="";
    
    genPerm(res, mapping, A, temp, 0);
    
    return res;

}