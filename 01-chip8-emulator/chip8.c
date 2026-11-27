#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MEMORY_SIZE   4096
#define NUM_REGISTERS 16
#define STACK_SIZE    16
#define DISPLAY_W     64
#define DISPLAY_H     32
#define NUM_KEYS      16
#define FONT_START    0x50
#define PROGRAM_START 0x200

static const uint8_t FONT[80] = {
    0xF0,0x90,0x90,0x90,0xF0, // 0
    0x20,0x60,0x20,0x20,0x70, // 1
    0xF0,0x10,0xF0,0x80,0xF0, // 2
    0xF0,0x10,0xF0,0x10,0xF0, // 3
    0x90,0x90,0xF0,0x10,0x10, // 4
    0xF0,0x80,0xF0,0x10,0xF0, // 5
    0xF0,0x80,0xF0,0x90,0xF0, // 6
    0xF0,0x10,0x20,0x40,0x40, // 7
    0xF0,0x90,0xF0,0x90,0xF0, // 8
    0xF0,0x90,0xF0,0x10,0xF0, // 9
    0xF0,0x90,0xF0,0x90,0x90, // A
    0xE0,0x90,0xE0,0x90,0xE0, // B
    0xF0,0x80,0x80,0x80,0xF0, // C
    0xE0,0x90,0x90,0x90,0xE0, // D
    0xF0,0x80,0xF0,0x80,0xF0, // E
    0xF0,0x80,0xF0,0x80,0x80  // F
};

/* ---------- A. The machine ---------- */
typedef struct {
    uint8_t  memory[MEMORY_SIZE];          // 4 KB of RAM
    uint8_t  V[NUM_REGISTERS];             // V0..VF, 1 byte each
    uint16_t I;                            // index register (holds an address)
    uint16_t pc;                           // program counter (address of next instr)
    uint16_t stack[STACK_SIZE];            // return addresses for subroutine calls
    uint8_t  sp;                           // stack pointer: index of next free slot
    uint8_t  delay_timer;                  // counts down at 60 Hz
    uint8_t  sound_timer;                  // beeps while > 0
    uint8_t  display[DISPLAY_W * DISPLAY_H]; // 1 = pixel on, 0 = off
    uint8_t  keypad[NUM_KEYS];             // 1 = pressed, 0 = not pressed
} Chip8;

/* ---------- B. Reset the machine ---------- */
void chip8_init(Chip8 *c) {
    memset(c, 0, sizeof(Chip8));              // wipe everything (no garbage values)
    c->pc = PROGRAM_START;                    // games start at 0x200
    memcpy(&c->memory[FONT_START], FONT, sizeof(FONT)); // font into memory at 0x50
}

/* ---------- C. Create one and inspect it ---------- */
int main(void) {
    Chip8 chip;
    chip8_init(&chip);

    printf("pc          = 0x%04X\n", chip.pc);
    printf("Total sizeof(Chip8) = %zu bytes\n", sizeof(Chip8));

    printf("font bytes  = ");
    for (int i = 0; i < 5; i++) {
        printf("%02X ", chip.memory[FONT_START + i]);
    }
    printf("\n");

    return 0;
}