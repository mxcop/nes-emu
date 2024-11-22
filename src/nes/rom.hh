#pragma once

/**
 * @brief Read-only memory.
 */
struct ROM {
    /* Heap memory */
    u8* mem = nullptr;
    const u16 bounds = 0u;

    ROM() = delete;
    /**
     * @brief Create a new ROM instance.
     * @param bytes Memory to copy into ROM.
     * @param size Size in bytes.
     */
    ROM(const u8* bytes, const u16 size);
    ~ROM();

    /** @brief Fetch a byte from ROM in the zeropage using an 8-bit address. */
    u8 fetch_zeropage(const u8 addr) const;

    /** @brief Fetch a byte from ROM using a 16-bit address. */
    u8 fetch(const u16 addr) const;
};
