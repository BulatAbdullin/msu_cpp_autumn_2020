#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#include "allocator.hpp"

int main()
{
	Allocator allocator;
	allocator.makeAllocator(12);

	puts("Alloc too much");
	char *fail_alloc = allocator.alloc(123);
	printf("FAIL: 0x%" PRIXPTR "\n", (uintptr_t) fail_alloc);
	puts("");

	puts("Alloc just right");
	const char *message = "hello\n";
	char *ptr = allocator.alloc(strlen(message) + 1);
	strcpy(ptr, message);
	printf("START: 0x%" PRIXPTR "\n", (uintptr_t) ptr);
	puts(ptr);

	puts("Alloc too much");
	message = "world";
	ptr = allocator.alloc(strlen(message) + 1);
	printf("CURRENT: 0x%" PRIXPTR "\n", (uintptr_t) ptr);
	puts("");

	puts("Alloc just right");
	message = "Sam\n";
	ptr = allocator.alloc(strlen(message) + 1);
	strcpy(ptr, message);
	printf("CURRENT: 0x%" PRIXPTR "\n", (uintptr_t) ptr);
	puts(ptr);

	puts("Reset");
	allocator.reset();
	message = "Hello, Sam!";
	ptr = allocator.alloc(strlen(message) + 1);
	strcpy(ptr, message);
	printf("CURRENT: 0x%" PRIXPTR "\n", (uintptr_t) ptr);
	puts(ptr);

	return 0;
}
