#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include "kernel/tty.h"
#include "kernel/memory.h"
 
#if defined(__linux__) || !defined(__i386__)
#error "You need to set up and use the cross compiler to build this OS"
#endif

void test_kernel_early()
{
    bool success;
    terminal_initialize();
    terminal_writestring("Testing memory initialization");
    success = test_memory_initialize();
    if (!success) {
        while (1);
        //__asm__("hlt");
    }
}

void kernel_early()
{
    bool success;
    terminal_initialize();
    success = memory_initialize();
}


void test_kernel()
{
    terminal_writestring("Running Tests");
}

void kernel_main()
{
    terminal_writestring("Hello, kernel World!\n");
}
