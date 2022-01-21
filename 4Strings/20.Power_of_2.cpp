#include <bits/stdc++.h>
using namespace std;

int power(string A) {
    /*

    Brute Force approach =>
        Divide the number by 2 till it is greater than 1
        At any point last digit is odd, then it is not power of 2

        Algorithm =>
        Loop until N not equal to 1 and also N is even
            N divided by 2
        If N is equal to 1
            return 1
        Else 
            return 0
    
    Another approach =>
        
        Algorithm => 
        start num = 0
        iterate through the string and update the num
        num = num*10 + A[i] - '0'

        If num overflow let it overflow
        Cases
        1) If num is 1  "return 0"
        2) If (num & num-1)==0      "return 1"
           Else "return 0"

    */

    // Implementing approach 2
    int num = 0;
    for(int i=0;i<A.length();++i){
        num = (num*10)+(A[i]-'0');
    }
    // Case 1
    if(num==1)  return 0;
    
    // Case 2
    if( (num & (num-1))== 0 )   return 1;
    return 0;

}


//  BRUTE FORCE APPROACH
bool check0Str(string A){
    int N = A.length();
    for(int i=0;i<N-1;++i){
        if(A[i]!='0')   return false;
    }
    if(A[N-1]=='1') return true;
    return false;
}


int power(string A){
    int N = A.length();

    // find the non-zero character position
    int j = 0;
    while(A[j]=='0')    j++;

    // Base case
    if(N-j==1 and A[j]=='1')    return 0;

    // divide the number by 2
    while(!check0Str(A)){
        
        // If last num is odd 
        if((A[N-1]-'0')%2)  return 0;

        // Divide by 2
        int carry = 0;
        string temp = "";

        for(int i=0;i<N;++i){
            temp += ('0'+ carry + (A[i]-'0')/2 );
            carry = ((A[i]- '0')%2==1)?5:0;
        }
    
        A = temp;
    }

    return 1;
}
