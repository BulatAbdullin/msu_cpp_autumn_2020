#include <stdio.h>
#include <assert.h>

#include "unit_tests.cpp"

int main()
{
	trivial();
	assert(started && ended);
	test();
	return 0;
}
