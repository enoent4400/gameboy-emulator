#include "memory.h"
#include <stdlib.h>
#include <string.h>

void memory_init(void) {
  // Allocate memory for each region
  rom_bank_0 = (uint8_t *)malloc(ROM_BANK_SIZE); // 16KB
  rom_bank_n = (uint8_t *)malloc(ROM_BANK_SIZE); // 16KB
  vram = (uint8_t *)malloc(VRAM_SIZE);           // 8KB
  wram = (uint8_t *)malloc(WRAM_SIZE);           // 8KB
  external_ram = (uint8_t *)malloc(WRAM_SIZE);   // 8KB
  oam = (uint8_t *)malloc(OAM_SIZE);             // 160B
  io_registers = (uint8_t *)malloc(IO_REG_SIZE); // 128B
  hram = (uint8_t *)malloc(HRAM_SIZE);           // 127B

  // Initial memory reset
  memory_reset(RESET_POWER_ON);
}
bool memory_reset(ResetType type) {
  if (type == RESET_POWER_ON) {
    // Clear all RAM areas using our defined constants
    memset(wram, 0, WRAM_SIZE);           // 8KB Work RAM
    memset(vram, 0, VRAM_SIZE);           // 8KB Video RAM
    memset(oam, 0, OAM_SIZE);             // 160B Sprite Memory
    memset(io_registers, 0, IO_REG_SIZE); // 128B I/O Registers
    memset(hram, 0, HRAM_SIZE);           // 127B High RAM
    ie_register = 0;                      // Interrupt Enable
  } else {
    memset(io_registers, 0, IO_REG_SIZE);
    ie_register = 0;
  }
  return true;
}
void memory_cleanup(void) {
  free(rom_bank_0);
  free(rom_bank_n);
  free(vram);
  free(wram);
  free(external_ram);
  free(oam);
  free(io_registers);
  free(hram);
}
