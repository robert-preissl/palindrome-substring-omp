
CXX = g++-mp-4.8
CXXFLAGS = -O3 -fopenmp
INCS = -I./
OBJS = PalindromeSubstring_omp.o

main: main_omp.cpp $(OBJS)
	$(CXX) $(CXXFLAGS) -o main main_omp.cpp $(OBJS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

clean:
	rm *.o main
