#include "cpu.hh"

#include <cstdio>
#include <cassert>

/* Memory */
#include "sram.hh"
#include "rom.hh"

CPU::CPU() { reset(); }

void CPU::reset() {
    r_pc = 0x00; /* Reset the program counter */
    r_sp = 0x00; /* Reset the stack pointer */
    r_sr = 0x00; /* Reset the status flags */
    /* Reset all general purpose registers */
    r_ac = r_xr = r_yr = 0x00;
}

void CPU::print() {
    printf("  PC    SR   AC   XR   YR   SP\n");
    printf("0x%04X 0x%02X 0x%02X 0x%02X 0x%02X 0x%02X\n", 
        r_pc, r_sr, r_ac, r_xr, r_yr, r_sp);
}

void CPU::update_status(const byte r) {
    set_status_flag(1, r == 0x00); /* Zero flag */
    set_status_flag(7, r & 0b1000'0000); /* Negative flag */
    /* TODO: add other flags here... */
}

bool CPU::execute(SRAM& m_ram, const ROM& m_rom) {
    print();

    /* Keep executing until we hit a 0x00 break */
    for (byte ins = m_rom.fetch(r_pc); ins; ++r_pc, ins = m_rom.fetch(r_pc)) {

        switch (ins)
        {
        case isa::LDA_IM:
            /* Load immediate into AC register */
            r_ac = m_rom.fetch(++r_pc);
            update_status(r_ac);
            break;
        default:
            assert(false && "unknown instruction!");
            break;
        }

        print();
    }

    printf("finished execution.\n");

    return true;
}
