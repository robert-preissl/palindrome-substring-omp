
#ifndef _PALINDROMESUBSTRING_HPP_
#define _PALINDROMESUBSTRING_HPP_



#include <string>
using namespace std;



class PalindromeSubstring {

	public:
    	string findLongestPalindromeSubstr(string s);
	
	private:
		// some helper methods
    	int formLongestPalindrome( int a, int b, const string& s, int sLength );
    	
    	string extractSubstringCenterIndex( int i, const string& s, int substrLength, int sLength );

};



#endif
