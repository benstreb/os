#include <stdint.h>
#include <stddef.h>
#include "kernel/vga.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;
 
void terminal_initialize()
{
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
    terminal_buffer = VGA_MEMORY;
    for ( size_t y = 0; y < VGA_HEIGHT; y++ )
    {
        for ( size_t x = 0; x < VGA_WIDTH; x++ )
        {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = make_vgaentry(' ', terminal_color);
        }
    }
}
 
void terminal_setcolor(uint8_t color)
{
    terminal_color = color;
}
 
void terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
    const size_t index = y * VGA_WIDTH + x;
    terminal_buffer[index] = make_vgaentry(c, color);
}
 
void terminal_putchar(char c)
{
    terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
    if ( ++terminal_column == VGA_WIDTH )
    {
        terminal_column = 0;
        if ( ++terminal_row == VGA_HEIGHT )
        {
            terminal_row = 0;
        }
    }
}

size_t strlen(const char* str)
{
    size_t ret = 0;
    while ( str[ret] != 0 )
        ret++;
    return ret;
}
 
void terminal_writestring(const char* data)
{
    size_t datalen = strlen(data);
    for ( size_t i = 0; i < datalen; i++ )
        terminal_putchar(data[i]);
}

// log_10(2^64) ~= 19.27, so 20 digits is enough for a uint64_t
const int DIGITS_IN_UINT64 = 20;

void num_to_chars(uint64_t num, char chars[20])
{
    char digits[DIGITS_IN_UINT64];
    int i;
    for (i = 0; num != 0; i++)
    {
        int digit = num - ((num/10)*10);
        digits[i] = '0' + digit;
    }
    i--;
    int j;
    for (j = 0; i >= 0; i--, j++)
    {
        chars[j] = digits[i];
    }
    chars[j] = 0;
}

void terminal_writenum(uint64_t num)
{
    char out[20];
    num_to_chars(num, out);
    terminal_writestring(out);
}
