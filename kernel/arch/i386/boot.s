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

    # In case the function returns, we'll want to put the computer into an
    # infinite loop. To do that, we use the clear interrupt ('cli') instruction
    # to disable interrupts, the halt instruction ('hlt') to stop the CPU until
    # the next interrupt arrives, and jumping to the halt instruction if it ever
    # continues execution, just to be safe. We will create a local label rather
    # than real symbol and jump to there endlessly.
    cli
    hlt
.Lhang:
    jmp .Lhang

# Set the size of the _start symbol to the current location '.' minus its start.
# This is useful when debugging or when you implement call tracing.
.size _start, . - _start
