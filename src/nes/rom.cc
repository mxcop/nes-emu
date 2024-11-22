#include "rom.hh"

#include <cassert> /* assert */
#include <cstring>

ROM::ROM(const u8* bytes, const u16 size) : bounds(size) {
    mem = new u8[size]{};
    memcpy(mem, bytes, size);
}
ROM::~ROM() { delete mem; }

u8 ROM::fetch_zeropage(const u8 addr) const { return fetch((u16)addr); }

u8 ROM::fetch(const u16 addr) const {
    assert(addr < bounds && "ROM fetch out of range.");
    return mem[addr];
}
