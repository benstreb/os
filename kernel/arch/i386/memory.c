#include <stdint.h>
#include <stdbool.h>

#pragma pack(1)
struct memory_region
{
    int64_t address;
    int64_t size;
    int32_t type;
    int32_t extended_attributes;
};


void read_region(struct memory_region *region)
{
    region->extended_attributes=1;
    __asm__("mov %0, %%di;\
             mov %1, %%eax;\
             mov %2, %%ebx;\
             mov %3, %%ecx;\
             mov %4, %%edx" :
            : "r" ((int16_t) region), "i" (0xE820), "i" (0), "i" (24), "i" (0x534D4150)
            : "%eax", "%ebx", "%ecx", "%edx");
    __asm__("int %0" : : "i" (0x15) : "memory");
}

bool memory_initialize()
{
    return true;
}

bool test_memory_initialize()
{
    struct memory_region region = {0, 0, 0, 0};
    read_region(&region);
    memory_initialize();
    return !region.address || !region.type;
}
