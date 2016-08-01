
CXX = g++
CXXFLAGS = -O3
INCS = -I./
OBJS = PalindromeSubstring.o

main: main.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o main main.cpp $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm *.o main
