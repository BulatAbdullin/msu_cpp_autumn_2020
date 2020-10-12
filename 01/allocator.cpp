#include "allocator.hpp"

Allocator::Allocator()
	: ptr_start(nullptr)
	, ptr_current(nullptr)
	, unused_size(0)
	, max_size(0)
{}

void Allocator::makeAllocator(size_t max_size)
{
	unused_size = this->max_size = max_size;
	ptr_start = ptr_current = new char[max_size];
}

char *Allocator::alloc(size_t size)
{
	if (size > unused_size) {
		return nullptr;
	}
	char *ptr_return = ptr_current;
	unused_size -= size;
	ptr_current += size;
	return ptr_return;
}

void Allocator::reset()
{
	ptr_current = ptr_start;
	unused_size = max_size;
}

Allocator::~Allocator()
{
	if (ptr_start) {
		delete[] ptr_start;
	}
}
