CXX=g++
CXXFLAGS=-Wall -Wpedantic -Werror -std=c++98 -g

all: main

test: main
	valgrind ./main

main: main.cpp unit_tests.cpp parser.o
	$(CXX) $(CXXFLAGS) main.cpp parser.o -o $@

parser.o: parser.cpp parser.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm *.o main
