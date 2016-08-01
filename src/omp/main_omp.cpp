
#include "./../PalindromeSubstring.h"

#include "./../../test/src/largeString.h"
#include <omp.h>

#include <iostream>
using namespace std;




int main() {

	PalindromeSubstring s = PalindromeSubstring();
	
	double start = omp_get_wtime();
	
	string result = s.findLongestPalindromeSubstr(largeStringAllCharsSame);
	
	double end = omp_get_wtime();

	cout << " For a string of length: " << largeStringAllCharsSame.length() << " : time[sec] = " << end - start << endl;

	return 0;

}
