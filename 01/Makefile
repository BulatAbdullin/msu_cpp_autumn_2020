CXX=g++
CXXFLAGS=-Wall -Wpedantic -std=c++17
SRCMODULES=allocator.cpp unit_tests.cpp
OBJMODULES=$(SRCMODULES:.cpp=.o)

all: run_tests

test: run_tests
	./run_tests

run_tests: run_tests.cpp $(OBJMODULES)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm *.o run_tests
