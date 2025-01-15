#ifndef MEMORY_H
#define MEMORY_H

#include "../include/types.h"
#include "cpu.h"
// Memory regions (internal to memory.c)
static uint8_t *rom_bank_0;   // 16KB ROM Bank 0
static uint8_t *rom_bank_n;   // 16KB ROM Bank 1-N
static uint8_t *vram;         // 8KB Video RAM
static uint8_t *wram;         // 8KB Work RAM
static uint8_t *external_ram; // 8KB External RAM
static uint8_t *oam;          // 160B Sprite Attribute Memory
static uint8_t *io_registers; // 128B I/O Registers
static uint8_t *hram;         // 127B High RAM
static uint8_t ie_register;   // Interrupt Enable Register
// Memory map constants
#define ROM_BANK_0_START 0x0000
#define ROM_BANK_0_END 0x3FFF
#define ROM_BANK_N_START 0x4000
#define ROM_BANK_N_END 0x7FFF
#define VRAM_START 0x8000
#define VRAM_END 0x9FFF
#define EXTERNAL_RAM_START 0xA000
#define EXTERNAL_RAM_END 0xBFFF
#define WRAM_START 0xC000
#define WRAM_END 0xDFFF
#define ECHO_START 0xE000
#define ECHO_END 0xFDFF
#define OAM_START 0xFE00
#define OAM_END 0xFE9F
#define IO_START 0xFF00
#define IO_END 0xFF7F
#define HRAM_START 0xFF80
#define HRAM_END 0xFFFE
#define IE_REGISTER 0xFFFF
// Memory Regions Size Constants
#define WRAM_SIZE 0x2000     // 8KB Work RAM
#define VRAM_SIZE 0x2000     // 8KB Video RAM
#define OAM_SIZE 0xA0        // 160B Sprite Attribute Memory
#define IO_REG_SIZE 0x80     // 128B I/O Registers
#define HRAM_SIZE 0x7F       // 127B High RAM
#define ROM_BANK_SIZE 0x4000 // 16KB ROM Bank

// Memory Bank Controller Constants
#define MBC1_ROM_BANKS 128 // Maximum number of ROM banks for MBC1
#define MBC1_RAM_BANKS 4   // Maximum number of RAM banks for MBC1

// Memory Map Constants (as you had before)
#define ROM_BANK_0_START 0x0000
#define ROM_BANK_0_END 0x3FFF
#define ROM_BANK_N_START 0x4000
#define ROM_BANK_N_END 0x7FFF
// Basic memory operations
void memory_init(void);
void memory_cleanup(void);
uint8_t memory_read(uint16_t address);
void memory_write(uint16_t address, uint8_t value);
bool memory_reset(ResetType type);
#endif // MEMORY_H
