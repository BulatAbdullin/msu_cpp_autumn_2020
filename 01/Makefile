CXX=g++
CXXFLAGS=-Wall -Wpedantic -std=c++17

all: test

test: run_tests
	./run_tests

SRCMODULES=allocator.cpp
OBJMODULES=$(SRCMODULES:.cpp=.o)

run_tests: run_tests.cpp $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm *.o run_tests
