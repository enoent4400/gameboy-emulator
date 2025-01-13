# GameBoy Emulator in C

A Game Boy emulator implementation in C language. 

## Features

- Sharp LR35902 (modified Z80) CPU emulation
- Complete memory management system
- Tile-based graphics rendering
- Support for multiple cartridge types (MBC1, MBC2, MBC3)
- Game saving functionality
- Debug features for development and learning

## Project Structure

```
gameboy/
├── src/              # Source files
│   ├── main.c       # Entry point
│   ├── cpu.c        # CPU emulation
│   ├── cpu.h
│   ├── memory.c     # Memory management
│   ├── memory.h
│   ├── ppu.c        # Picture Processing Unit
│   ├── ppu.h
│   ├── cartridge.c  # Cartridge handling
│   └── cartridge.h
├── include/         # Header files
│   └── types.h     # Common type definitions
├── tests/          # Test files
├── docs/           # Documentation
└── Makefile        # Build system
```

## Prerequisites

- GCC or Clang compiler
- GNU Make
- SDL2 library (for graphics and input)

### Installing Dependencies

#### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install build-essential libsdl2-dev
```

#### macOS
```bash
brew install sdl2
```

## Building

1. Clone the repository:
```bash
git clone https://github.com/yourusername/gameboy-emu.git
cd gameboy-emu
```

2. Run the setup script:
```bash
./setup_gameboy_emu.sh
```

3. Build the project:
```bash
cd gameboy
make
```

## Usage

```bash
./gameboy_emu [rom_file]
```

### Controls

- Arrow keys: D-pad
- Z: A button
- X: B button
- Enter: Start
- Right Shift: Select
- Space: Pause emulation
- F1: Save state
- F2: Load state
- Esc: Exit

## Development

### Running Tests

```bash
make test
```

### Debug Mode

Run with debug flag:
```bash
./gameboy_emu -d [rom_file]
```

Debug commands:
- `b [address]`: Set breakpoint
- `c`: Continue execution
- `s`: Step instruction
- `p`: Print CPU state
- `m [address]`: Dump memory
- `q`: Quit debugger

## Implementation Details

See [IMPLEMENTATION.md](docs/IMPLEMENTATION.md) for detailed documentation about:
- CPU instruction set
- Memory mapping
- Graphics system
- Timer system
- Sound system (future implementation)
- Cartridge types and memory banking

## Testing

We use several test ROMs to verify the emulator's accuracy:
- Blargg's test ROMs
- Mooneye GB test suite
- Custom test ROMs

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## Resources

### Documentation
- [Game Boy CPU Manual](http://marc.rawer.de/Gameboy/Docs/GBCPUman.pdf)
- [Pan Docs](https://gbdev.io/pandocs/)
- [Game Boy Programming Manual](https://archive.org/details/GameBoyProgManVer1.1)

### Tools
- [BGB (Game Boy emulator/debugger)](http://bgb.bircd.org/)
- [Game Boy Tile Designer](http://www.devrs.com/gb/hmgd/gbtd.html)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

- [Pan Docs](https://gbdev.io/pandocs/) for the extensive Game Boy documentation
- The Game Boy development community for their invaluable resources
- Various test ROM creators for helping ensure accuracy
