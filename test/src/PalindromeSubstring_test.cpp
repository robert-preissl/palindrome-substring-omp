

#include "gtest/gtest.h"
#include "PalindromeSubstring.h"
#include "largeString.h"

class FindLongestPalindromeSubstrTest : public ::testing::Test {
	
	protected:
  		virtual void SetUp() {}
  		virtual void TearDown() {}

};

// test overall functionality including corner cases
TEST_F(FindLongestPalindromeSubstrTest,shortStrings){

    PalindromeSubstring palSubStr;
    string s;
    
    // test for empty input string
    s = "";
    EXPECT_EQ( s, palSubStr.findLongestPalindromeSubstr(s) );
    
    // test for input string with just one char
    s = "a";
    EXPECT_EQ( s, palSubStr.findLongestPalindromeSubstr(s));
    
    // test for input string with just two chars, which are the same
    s = "aa";
    EXPECT_EQ( s, palSubStr.findLongestPalindromeSubstr(s));
    
    // test for input string with just two chars, which are different
    s = "ab";
    EXPECT_EQ( "a", palSubStr.findLongestPalindromeSubstr(s));
    
    // test for input string with no palindromes (all chars are unique)
    s = "abcdefgh";
    EXPECT_EQ( "a", palSubStr.findLongestPalindromeSubstr(s));
    
    // test for input string with non alphabetic elements
    s = "abc124$322^5443=-=-/";
    EXPECT_EQ( "=-=", palSubStr.findLongestPalindromeSubstr(s));

    // test for input string with an even sized palindrome
    s = "abba";
    EXPECT_EQ( s, palSubStr.findLongestPalindromeSubstr(s));

    // test for input string with an odd sized palindrome
    s = "abcba";
    EXPECT_EQ( s, palSubStr.findLongestPalindromeSubstr(s));

    // test for input string with two even sized palindrome of same length
    s = "abba_xyz_abba";
    EXPECT_EQ( "abba", palSubStr.findLongestPalindromeSubstr(s));

    // test for input string with two odd sized palindrome of same length
    s = "abcba_xyz_abcba";
    EXPECT_EQ( "abcba", palSubStr.findLongestPalindromeSubstr(s));

    // test for input string with two even sized palindrome of different length
    s = "abba_xyz_abccba";
    EXPECT_EQ( "abccba", palSubStr.findLongestPalindromeSubstr(s));

    // test for input string with two odd sized palindrome of different length
    s = "abcba_xyz_abcdcba";
    EXPECT_EQ( "abcdcba", palSubStr.findLongestPalindromeSubstr(s));

    // test for input string with all same characters (even sized)
    s = "aaaaaaaaaaaaaaaa";
    EXPECT_EQ( s, palSubStr.findLongestPalindromeSubstr(s));

    // test for input string with all same characters (odd sized)
    s = "aaaaaaaaaaaaaaaaa";
    EXPECT_EQ( s, palSubStr.findLongestPalindromeSubstr(s));

}

// test for larger strings and verify the complexity analysis:
//  runtime complexity: best  case O(N)    .. no palindromes
//                      worst case O(N*N)  .. all characters are equal
TEST_F(FindLongestPalindromeSubstrTest,longStrings){

    PalindromeSubstring palSubStr;
    string s;

    // test for a large input string with no palindromes
    s = largeStringNoPalindromes;
    EXPECT_EQ( "a", palSubStr.findLongestPalindromeSubstr(s));
    
    // test for a large input string with all chars same
    s = largeStringAllCharsSame;
    EXPECT_EQ( largeStringAllCharsSame, palSubStr.findLongestPalindromeSubstr(s));
    
    // test for a large input string which contains many palindromes of same size
    s = largeStringIncludesSeveralPalindromes;
    EXPECT_EQ( "_1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZZYXWVUTSRQPONMLKJIHGFEDCBA0987654321_", palSubStr.findLongestPalindromeSubstr(s));
    
    
}
