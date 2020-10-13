#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>

class Allocator
{
private:
	char *ptr_start;
	char *ptr_current;
	size_t unused_size;
	size_t max_size;
public:
	Allocator();
	~Allocator();
	void makeAllocator(size_t max_size);
	char *alloc(size_t size);
	void reset();

	inline char *getPtrStart() const
	{
		return ptr_start;
	}

	inline char *getPtrCurrent() const
	{
		return ptr_current;
	}

	inline size_t getMaxSize() const
	{
		return max_size;
	}
};

#endif
