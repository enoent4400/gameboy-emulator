#include "cpu.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLAG_Z 0x80 // Zero Flag
#define FLAG_N 0x40 // Subtract Flag
#define FLAG_H 0x20 // Half Carry Flag
#define FLAG_C 0x10 // Carry Flag

CPU *cpu_create() {
  CPU *cpu = (CPU *)malloc(sizeof(CPU));
  if (!cpu) {
    fprintf(stderr, "Error: Could not allocate memory for CPU\n");
    return NULL;
  } // Memory allocation check

  // Initialize all registers to power-up values
  if (!cpu_initialize(cpu)) {
    fprintf(stderr, "Error: Could not initialize CPU\n");
    free(cpu);
    return NULL;
  }

  return cpu;
}

bool cpu_initialize(CPU *cpu) {
  if (!cpu) {
    fprintf(stderr, "Error: CPU is NULL\n");
    return false;
  }

  memset(cpu, 0, sizeof(CPU)); // Zero out all memory first

  // Set power-up register values
  cpu->registers.af = 0x01B0;
  cpu->registers.bc = 0x0013;
  cpu->registers.de = 0x00D8;
  cpu->registers.hl = 0x014D;
  cpu->pc = 0x0100;
  cpu->sp = 0xFFFE;

  return true;
}

bool cpu_validate_state(const CPU *cpu, uint8_t *validation_flags) {
  uint8_t flags = 0;
  bool is_valid = true;

  // Validate Program Counter (PC) w
  // PC should be within addressable memory range
  if (cpu->pc <= 0xFFFF) {
    flags |= CPU_VALID_PC;
  } else {
    is_valid = false;
  }

  // Validate Stack Pointer (SP)
  // SP should be within valid RAM areas
  if (cpu->sp >= 0xC000 && cpu->sp <= 0xFFFE) {
    flags |= CPU_VALID_SP;
  } else {
    is_valid = false;
  }

  // Validate Flag Register
  // Lower 4 bits should always be 0
  if ((cpu->registers.f & 0x0F) == 0) {
    flags |= CPU_VALID_FLAGS;
  } else {
    is_valid = false;
  }

  if (validation_flags) {
    *validation_flags = flags;
  }

  return is_valid;
}

const char *cpu_get_validation_error(uint8_t validation_flags) {
  static char error_buffer[256];
  error_buffer[0] = '\0';

  if (!(validation_flags & CPU_VALID_PC)) {
    strcat(error_buffer, "Invalid PC value\n");
  }
  if (!(validation_flags & CPU_VALID_SP)) {
    strcat(error_buffer, "Invalid SP value\n");
  }
  if (!(validation_flags & CPU_VALID_FLAGS)) {
    strcat(error_buffer, "Invalid flag register state\n");
  }

  return error_buffer;
}

void cpu_dump_state(const CPU *cpu) {
  if (!cpu)
    return;

  printf("CPU State:\n");
  printf("AF: 0x%04X (A: 0x%02X, F: 0x%02X)\n", cpu->registers.af,
         cpu->registers.a, cpu->registers.f);
  printf("BC: 0x%04X (B: 0x%02X, C: 0x%02X)\n", cpu->registers.bc,
         cpu->registers.b, cpu->registers.c);
  printf("DE: 0x%04X (D: 0x%02X, E: 0x%02X)\n", cpu->registers.de,
         cpu->registers.d, cpu->registers.e);
  printf("HL: 0x%04X (H: 0x%02X, L: 0x%02X)\n", cpu->registers.hl,
         cpu->registers.h, cpu->registers.l);
  printf("PC: 0x%04X\n", cpu->pc);
  printf("SP: 0x%04X\n", cpu->sp);

  uint8_t validation_flags;
  if (!cpu_validate_state(cpu, &validation_flags)) {
    printf("Validation Errors:\n%s",
           cpu_get_validation_error(validation_flags));
  }
}

bool cpu_reset(CPU *cpu, ResetType type) {
  if (!cpu) {
    fprintf(stderr, "Error: CPU is NULL\n");
    return false;
  }
  if (type == RESET_POWER_ON) {
    // Power-on reset values as per Game Boy hardware docs
    cpu->registers.af = 0x01B0;
    cpu->registers.bc = 0x0013;
    cpu->registers.de = 0x00D8;
    cpu->registers.hl = 0x014D;
    cpu->sp = 0xFFFE;
  } else {
    // Software reset preserves some register values
    // but resets program flow
    cpu->registers.a &= 0xF0; // Preserve upper bits of A
    cpu->registers.f = 0x00;  // Clear all flags
  }
  cpu->pc = 0x0100;
  // Reset all registers to power-up values
  return true;
}
