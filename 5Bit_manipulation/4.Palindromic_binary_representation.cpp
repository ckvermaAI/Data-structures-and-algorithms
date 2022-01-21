// https://www.interviewbit.com/problems/palindromic-binary-representation/
// https://www.youtube.com/watch?v=QYoWR8hDCyQ&t=1698s

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

/*

Brute Force approach will be to iterate over all number starting from
0 and find out the Ath palindrome
Time Complexity = O(2^A)

Just write down the first few palidromes

1    1
2    11
    Length of palidrome = {1, 2} and
    count of palindrome for each length = 1
    
3    101
4    111
5    1001
6    1111
    Length of palidrome = {3, 4} and
    count of palindrome for each length = 2

8     10001
9     10101
10    11011
11    11111
12    100001
13    101101
14    110011
15    111111
    Length of palidrome = {5, 6} and
    count of palindrome for each length = 4


So, we can count the number of palindrome and what should be the length 
of "ith palindrome". 

Once we find out the length of palindrome we can find the position of palindrome 
in the sequence of palindrome for that particular length.


*/

int reverse_binary(int A, int len){
    int res=0;
    for(int i=len-1;i>=0;--i){
        if(A & (1<<i)){
            res += (1<<(len-i-1));
        }
    }
    return res;
}


int solve(int A) {
    int lenPalindrome = 1, pos=1;
    while(pos<A){
        lenPalindrome++;
        pos += (1<<((lenPalindrome-1)/2) );
    }

    // get back to valid position
    pos -= (1<<((lenPalindrome-1)/2) );
    // get back to valid length

    int offset = A-pos-1;
    
    // Place the first 1 
    int ans = (1<<(lenPalindrome-1));
    // place the next digit in left part of number
    ans |= (offset<<(lenPalindrome/2));

    int half = (ans>>(lenPalindrome/2));
    int rev = reverse_binary(half, (lenPalindrome+1)/2 );
    ans |= rev;

    return ans;
}
