#ifndef CPU_H
#define CPU_H

#include "../include/types.h"
#include <stdbool.h>
#include <stdint.h>
// Validation flags that might be used by other modules
#define CPU_VALID_PC (1 << 0)
#define CPU_VALID_SP (1 << 1)
#define CPU_VALID_FLAGS (1 << 2)
#define CPU_VALID_ALL (CPU_VALID_PC | CPU_VALID_SP | CPU_VALID_FLAGS)

typedef struct {
  // CPU registers
  struct {
    union {
      struct {
        u8 f; // flags
        u8 a; // accumulator
      };
      u16 af;
    };
    union {
      struct {
        u8 c;
        u8 b;
      };
      u16 bc;
    };
    union {
      struct {
        u8 e;
        u8 d;
      };
      u16 de;
    };
    union {
      struct {
        u8 l;
        u8 h;
      };
      u16 hl;
    };
  } registers;

  u16 pc; // program counter
  u16 sp; // stack pointer
} CPU;

CPU *cpu_create();
void cpu_destroy(CPU *cpu);
bool cpu_initialize(CPU *cpu);
bool cpu_validate_state(const CPU *cpu, uint8_t *validation_flags);
const char *cpu_get_validation_error(uint8_t validation_flags);
void cpu_dump_state(const CPU *cpu);
bool cpu_reset(CPU *cpu, ResetType type);
#endif // CPU_H
