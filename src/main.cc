#include <cstdlib> /* EXIT_SUCCESS */
#include <cstdio>  /* printf */

/* NES Components */
#include "nes/cpu.hh"
#include "nes/rom.hh"
#include "nes/sram.hh"

const u8 program[] {
    isa::LDA_IM, 0x34,
    isa::STA_ZP, 0x05,
    isa::BRK
};

int main() {
    /* Create CPU & SRAM */
    CPU cpu {};
    SRAM ram {0xFA00}; /* 64 kB */

    /* Load program into ROM */
    ROM rom {program, sizeof(program)};

    /* Execute program */
    if (cpu.execute(ram, rom)) return EXIT_SUCCESS;
    return EXIT_FAILURE;
}
