
#include "PalindromeSubstring.h"

#include <iostream>
using namespace std;




int main() {

	PalindromeSubstring palindromeSubstring = PalindromeSubstring();
	
	
	string s = "abc12321efghijkl";
	string result = palindromeSubstring.findLongestPalindromeSubstr(s);

	cout << " The longest palindromic substring of string s = " << s << " is : " << result << endl;

	return 0;

}
