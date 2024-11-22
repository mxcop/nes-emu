#pragma once

/**
 * @brief Static random-access memory.
 */
struct SRAM {
    /* Heap memory */
    u8* mem = nullptr;
    u16 bounds = 0u;

    SRAM() = delete;
    /**
     * @brief Create a new SRAM instance.
     * @param size Size in bytes.
     */
    SRAM(const u16 size);
    ~SRAM();

    /** @brief Fetch a byte from SRAM in the zeropage using an 8-bit address. */
    u8 fetch_zeropage(const u8 addr) const;

    /** @brief Fetch a byte from SRAM using a 16-bit address. */
    u8 fetch(const u16 addr) const;
};
