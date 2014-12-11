#include <stddef.h>
#include <stdint.h>
#include "kernel/tty.h"
 
#if defined(__linux__) || !defined(__i386__)
#error "You need to set up and use the cross compiler to build this OS"
#endif
 
#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
void kernel_main()
{
    terminal_initialize();
    /* Since there is no support for newlines in terminal_putchar yet, \n will
       produce some VGA specific character instead. This is normal. */
    terminal_writestring("Hello, kernel World!\n");
}
