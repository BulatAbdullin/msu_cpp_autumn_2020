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

void alloc_max_size()
{
	Allocator allocator;
	allocator.makeAllocator(1473);
	assert(allocator.alloc(1473) == allocator.getPtrStart());
}

void reset()
{
	Allocator allocator;
	allocator.makeAllocator(99);
	char *ptr = allocator.alloc(10);
	assert(ptr == allocator.getPtrStart());
	ptr = allocator.alloc(50);
	assert(ptr != allocator.getPtrStart());
	allocator.reset();
	assert(allocator.getPtrCurrent() == allocator.getPtrStart());
}
