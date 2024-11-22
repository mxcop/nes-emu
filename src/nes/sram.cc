#include "sram.hh"

#include <cassert> /* assert */

SRAM::SRAM(const u16 size) {
    bounds = size;
    mem = new u8[bounds]{};
}

SRAM::~SRAM() { delete mem; }

u8 SRAM::fetch_zeropage(const u8 addr) const {
    return fetch((u16)addr); 
}

u8 SRAM::fetch(const u16 addr) const {
    assert(addr < bounds && "SRAM fetch out of range.");
    return mem[addr]; 
}
