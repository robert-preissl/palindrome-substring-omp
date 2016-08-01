
# ---  Please adapt for your environment ---

# the root directory for googletest
GTEST_DIR = /Users/robert/Private/C++Tutorial/gtest-1.7.0

# the path where googletest has been installed (where "make was executed)
GTEST_BUILD_DIR = /Users/robert/Private/C++Tutorial/gtest-1.7.0/mybuild

# ------------------------------------------




GTEST_HEADERS_INCL = -I $(GTEST_DIR)/include/ \
                     -I $(GTEST_DIR)/include/gtest/internal/


CXX = g++
CXXFLAGS = -g -L$(GTEST_BUILD_DIR) -lgtest -lgtest_main -lpthread -O3
INCS = -I./ -I../../src $(GTEST_HEADERS_INCL)
OBJS = ../../src/PalindromeSubstring.o PalindromeSubstring_test.o

testAll: $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCS) -o testAll testAllMain.cpp $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm testAll *.o testAll.xml




