#include <stdint.h>

// log_10(2^64) ~= 19.27, so 20 digits is enough for a uint64_t
const int DIGITS_IN_UINT64 = 20;

void num_to_chars(uint64_t num, char chars[DIGITS_IN_UINT64])
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
