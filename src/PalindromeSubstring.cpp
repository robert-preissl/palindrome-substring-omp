
#include "PalindromeSubstring.h"

#include <iostream>
#include <assert.h>
using namespace std;


//     the overall plan to find the longest possible palindromic substring:
//
//
//  the central idea is to compute for each character of the given string
//   the longest palindrome we can form starting around that specific
//   character:
//
//  this means that for every position i in [0, N-1] (N .. length):
//   we set two pointers a,b like this: a=i & b=i and move a left
//   and b to the right 1 step. each step we check if we still have
//   a palindrome: (of course, the starting position with a=b is a palindrome)
//     if yes: keep going
//     if no : stop, and move i one step further
//
//  note, the above is true for palindromes with odd size. for even
//   size, we set a to i, and b to i+1. which we have to check as well!
//
//  runtime complexity: best  case O(N)    .. no palindromes (best case since the function "formLongestPalindrome" always terminates immediately and only the loop in "findLongestPalindromeSubstr" matters for runtime)
//                      worst case O(N*N)  .. all characters are equal (for each index of the string we have to go through the full iterations "formLongestPalindrome" since we can never prematurely exit)
//  
//  memory complexity:  O(N) .. size of string
        
       
       
        
// returns the substring of a string "s" (with length "sLength"),
//  based on a given center index "i" and a given length "pLength"
//  e.g., if s = "abcde", i = 2, and substrLength = 3  =>  return = "bcd"
string PalindromeSubstring::extractSubstringCenterIndex( int i, const string& s, int substrLength, int sLength ) {

    assert (i - substrLength/2 >= 0 && i - substrLength/2 + substrLength <= sLength ); // just to be double sure we do not go out of bounds
    return s.substr(i - substrLength/2, substrLength);

}


// returns the length of the longest possible palindromic substring of a
//  given string "s" (with length "sLength").
// the palindromic substr is formed by constantly expanding a and b to the left and
//  right, respectively by one position.
int PalindromeSubstring::formLongestPalindrome( int a, int b, const string& s, int sLength ) {

    while( a >= 0 && b <= sLength-1 ) {
        if( s[a] != s[b] )
            break; // break out of the loop if we are not palindromic anymore
            
        a--; // move pointers one spot to left and right
        b++;
    }
    return (b-a-1); // return the length of the longest possible palindrome

}


// returns the longest possible palindromic substring of a string "s"
//  note, if multiple palindromic substrings exist of similar size, the first
//  one found is returned
string PalindromeSubstring::findLongestPalindromeSubstr(string s) {

    int sLength = s.length();
        
    // in case of empty string or just one character the longest
    //  palindrome is the string itself
    if( sLength < 2 )
        return s;

    int maxLength = 1;
    int indexOfLongestPalindrome = 0; // if we do not find later a longest palindrome,
                                      //  we will return the first character of the string
                                      //  (then we have N palindromes basically of size 1)

    // compute longest possible palindrome per index i:
    for( int i = 1; i < sLength; ++i ) {

        // however, take into account that palindromes can be odd or even sized!
        //  * to find even sized palindromes: we set search-indices a = i-1 & b = i+1
        //     (no need to start with a = b = i, since we know that this is a palindrome of size 1)
        //  * to find odd  sized palindromes: we set search-indices a = i-1 & b = i
        int tempLongest = max(
            formLongestPalindrome( i-1, i+1, s, sLength ), 
            formLongestPalindrome( i-1, i,   s, sLength )  );
            
        // if a new longer palindrome has been found, reset max value and index
        if( tempLongest > maxLength ) {
            maxLength = tempLongest;
            indexOfLongestPalindrome = i;
        }

    }
            
	return extractSubstringCenterIndex( indexOfLongestPalindrome, s, maxLength, sLength );

}
