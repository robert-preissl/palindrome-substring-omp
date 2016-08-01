

On a high-level, there are 3 main deliverables:

1.) the C++ solution, with a best case runtime complexity of O(N) and a worst case complexity of O(N*N)

2.) an automated testing framework (relying on "googletest") to check for correctness

3.) using the solution from 1.) and making it multithreaded to speed-up the computation



here are more details to each of these 3 points (more explanations, how to run, etc.)

for 1.)
in pal/src you will see a source file called "PalindromeSubstring.cpp", which is basically the
code representing my idea to find the longest palindromic substring.
An algorithm discussion is in that file and also an explanation why best case complexity is O(N)
and worst is O(N*N).

in order to build and run a simple example do: "make" and then: "./main". You should see an output
like: "The longest palindromic substring of string s = abc12321efghijkl is : 12321".

Are there worse and better solutions?
-> there is a simple brute force solution (basically, check for each subsequence if palindromic)
for this problem, which runtime complexity is O(N*N*N). So, I tried to
come up with something faster. However, my worst case O(N*N) is not very good for very large strings
and it seems that there is a fancy O(N) algorithm from "Manacher" as described here:
http://en.wikipedia.org/wiki/Longest_palindromic_substring , which I would not so quickly come up with to be honest.
However, as usually with string matching problems, suffix trees are an awesome choice and I
would personally vote for such a solution which would be O(N) complexity as described here:
https://www8.cs.umu.se/kurser/TDBAfl/VT06/algorithms/BOOK/BOOK3/NODE131.HTM
(I used suffix trees for my PhD thesis and there are some cool open source implementations out there) 



for 2.)
in pal/test/src you will see a file called "PalindromeSubstring_test.cpp", which
defines all the test cases I could come up with for that exercise. there a 2 groups
of tests. one, where I focus on correctness (testing corner cases) and one where I
test larger strings to verify my statement of O(N) vs O(N*N) complexity depending
on how the string is setup.

before running, you have to do 2 things:
a.) download & install google-test: https://code.google.com/p/googletest/downloads/detail?name=gtest-1.7.0.zip&can=2&q=
                                    https://code.google.com/p/tonatiuh/wiki/InstallingGoolgeTestForMac
b.) edit the Makefile in pal/test/src to point to your googleTest root directory (edit GTEST_DIR & GTEST_BUILD_DIR)

now, build via: "make" and run the full test suite with: " ./testAll --gtest_output="xml:./testAll.xml" "




for 3.)
the cool thing about my solution in 1.) is that it can be perfectly multithreaded:
each thread will take care of a portion of indices of the string and compute for each of its
position the longest palindrome that can be formed starting around that specific character!!
(note, the string is split up among threads; but each thread sees the whole string as read-only)

after each thread is done, a single thread inspects all the "thread local best solutions" and
computes the best global solution to be returned.
my test runs with large strings show very strong speed-ups! I ran up to 8 threads and
I can clearly see all CPUs very busy and the measured wall-clock times going significantly down.
(however, clearly even with 1000 threads there is no chance against a O(N) solution for super large strings)
the code and Makefile for this multithreaded version is under pal/src/omp

before building, you have to install a c++ compiler supporting OpenMP. (on Mac, g++
symlinks to Clang which does not support OpenMP right now.). I installed
gcc 4.8. on my mac via "macports" and it workes fine!
so, the Makefile in pal/src/omp needs to specify a c++ compiler with OpenMP support!

to build execute: "make" and to run: "./main". also note, that you can play with various number of
openMP threads by setting: "export OMP_NUM_THREADS=8".

 



