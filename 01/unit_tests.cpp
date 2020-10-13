#include <assert.h>
#include <string.h>

#include "allocator.hpp"

void alloc_too_much()
{
	Allocator allocator;
	allocator.makeAllocator(12);
	assert(allocator.alloc(13) == nullptr);
}

void alloc_just_right()
{
	Allocator allocator;
	allocator.makeAllocator(12);
	const char *message = "hello";
	char *ptr = allocator.alloc(strlen(message) + 1);
	strcpy(ptr, message);
	assert(strcmp(ptr, message) == 0);
}
