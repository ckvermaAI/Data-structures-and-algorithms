#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string A) {
    /*

    Brute force approach =>
        iterate through all the substrings
        and check whether that string is palindrome or not
        Time complexity = O(N^3)
        space comeplexity = O(1)

    Better approach =>
        Which is partially right solution, 
        Given string S, Reverse the string S == S'
        Find the longest substring b/w S and S' which must also
        be the longest palindromic substring.

        This seems to work, lets see some example 
        1) S = "caba" and S' ="abac"
         The longest common substring b/w S and S' is "aba" which is our answer

        2) S ="abacdfgdcaba” and S'=“abacdgfdcaba”
            The lonegst common substring b/w S and S' is "abacd". clearly not a 
            valid palindrome.

        We could see that longest common substring method fails when there exists a 
        reversed copy of non-palindromic substring in some other part of S. To rectify
        this, each time we find a longest common substring candidate, we check if
        the substring's indices are same as reversed substring's original indices.
        If it is then we update the longest palindrome found so far, if not we skip
        this and find the next candidate.
        
        Time complexity = O(N^2)
        Space complexity = O(N^2) ( could be improved to O(N) )

    
    Another DP solution =>
        state of DP
        DP[i,j] == true, if the substring S[i...j] is palindrome
                == false, otherwise
        
        DP[i, j] == (DP[i+1,...., j-1] and Si==Sj)

        and base cases are 
        DP[i,i] == 1 (strings of length 1 are palindrome)
        DP[i, i+1] == (Si==Si+1)
        
        Time complexity = O(N^2)
        Space complexity = O(N^2)
    

    Optimised Space solution =>
        Time complexity = O(N^2)
        Space complexity = O(1)

        Observation => A palindrome mirrors around its center. Therefore a 
                        palindrome can be expanded from its center and there
                        are "2N-1" such centers.
                    
                    N centers for "N" character in string
                    (these centres will create a odd palindrome)

                    N-1 centres b/w two letters/characters in string
                    (these centres will create a even palindrome)
    
    */

    const int N=A.length();
    int low, high;
    int start=0, maxLength=1;

    for(int i=1;i<N;++i){

        // Odd length palindrome
        // center will be i
        low = i-1, high=i+1;
        while(low>=0 and high<N and A[low]==A[high]){
            low--; high++;
        }
        low++;high--;
        if( (high-low+1)>maxLength and A[low]==A[high]){
            start=low;
            maxLength = (high-low+1);
        }

        // Even length palindrome 
        // center will be b/w i-1 and i
        low = i-1, high=i;
        while(low>=0 and high<N and A[low]==A[high]){
            low--; high++;
        }
        low++;high--;
        if( (high-low+1)>maxLength and A[low]==A[high]){
            start=low;
            maxLength = (high-low+1);
        }
    }
    return A.substr(start, maxLength);
}
