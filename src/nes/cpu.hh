#pragma once

#include "isa.hh"

/* Memory */
struct SRAM;
struct ROM;

/**
 * @brief 6502 CPU emulator.
 */
struct CPU {
    /* CPU data types */
    using byte = u8;
    using word = u16;

    /* Registers */
    word r_pc = 0x00; /* PC - Program Counter */
    byte r_ac = 0x00; /* AC - Accumulator Register */
    byte r_xr = 0x00; /* XR - X Register */
    byte r_yr = 0x00; /* YR - Y Register */
    byte r_sr = 0x00; /* SR - Status Register [NV-BDIZC] (also known as P Register) */
    byte r_sp = 0x00; /* SP - Stack Pointer */

    CPU();

    /** @brief Reset all CPU registers to their default state. */
    void reset();

    /** @brief Print all CPU registers to the standard output. */
    void print();

    /** @brief Set a flag in the status register. */
    inline void set_status_flag(const u8 bit, const bool status) {
        if (status) r_sr |= (0b1 << bit);
        else r_sr &= ~(0b1 << bit);
    }

    /** @brief Update the status register based on the given register. */
    void update_status(const byte r);

    bool execute(SRAM& m_ram, const ROM& m_rom);
};
