#pragma once
#include <stdint.h>
extern const int DIGITS_IN_UINT64;

void num_to_chars(uint64_t num, char chars[DIGITS_IN_UINT64]);
