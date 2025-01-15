#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef int8_t i8;
typedef int16_t i16;

typedef enum {
  RESET_POWER_ON,
  RESET_SOFTWARE,
} ResetType;

#endif // TYPES_H
