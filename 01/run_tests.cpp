#include <stdio.h>

#include "unit_tests.hpp"

int main()
{
	alloc_too_much();
	alloc_just_right();
	alloc_max_size();
	reset();
	printf("Succes: unit tests passed\n");
	return 0;
}
