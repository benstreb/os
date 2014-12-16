#include <stddef.h>
#include <stdint.h>
#include "kernel/tty.h"
 
#if defined(__linux__) || !defined(__i386__)
#error "You need to set up and use the cross compiler to build this OS"
#endif

void kernel_early()
{
    terminal_initialize();
}


void test_kernel()
{
    terminal_writestring("Running Tests");
}

void kernel_main()
{
    terminal_writestring("Hello, kernel World!\n");
}
