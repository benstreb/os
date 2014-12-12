# Declare constants used for creating a multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Multiboot standard header
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Reserve space for the stack
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16 KiB
stack_top:

# Start function. This is the entry point to the kernel and does not return
.section .text
.global _start
.type _start, @function
_start:
    # Have the stack pointer point to the stack
    movl $stack_top, %esp

    # Initialize core kernel functionality
    call kernel_early

    # Initialize global constructors. None yet, so this is commented out
    # call _init

    # Main entry point
    call kernel_main

    # Hang if kernel_main returns
    cli
    hlt
.Lhang:
    jmp .Lhang

# Set the size of the _start symbol
.size _start, . - _start
