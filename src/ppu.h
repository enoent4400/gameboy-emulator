// ppu.h
#ifndef PPU_H
#define PPU_H

#include "../include/types.h"

// LCD Control Register (0xFF40) bits
#define LCDC_DISPLAY_ENABLE    0x80
#define LCDC_WINDOW_MAP        0x40
#define LCDC_WINDOW_ENABLE     0x20
#define LCDC_TILE_DATA_SELECT  0x10
#define LCDC_BG_MAP           0x08
#define LCDC_OBJ_SIZE         0x04
#define LCDC_OBJ_ENABLE       0x02
#define LCDC_BG_ENABLE        0x01

// LCD Status Register (0xFF41) bits and modes
typedef enum {
    MODE_HBLANK = 0,
    MODE_VBLANK = 1,
    MODE_OAM    = 2,
    MODE_VRAM   = 3
} PPUMode;

// Basic PPU interface
void ppu_init(void);
void ppu_cleanup(void);
void ppu_reset(ResetType type);
void ppu_step(int cycles);

#endif // PPU_H
