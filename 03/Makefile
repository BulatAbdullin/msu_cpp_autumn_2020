CXX=g++
CXXFLAGS=-Wall -Wpedantic -std=c++98 -g

all: main

test: main
	valgrind ./main

main: main.cpp tests.cpp matrix.o
	$(CXX) $(CXXFLAGS) main.cpp matrix.o -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm *.o main
