#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#include <stdint.h>
#include <stddef.h>
#include <math.h>

#define DIGITS_ARRAY_SIZE 64

size_t rebase(int8_t digits[], uint16_t input_base, uint16_t output_base, size_t input_length);

#endif
