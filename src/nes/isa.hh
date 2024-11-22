#pragma once

/**
 * @brief MOS 6502 ISA.
 */
namespace isa {
    /* BRK - Break / Interrupt */
    constexpr u8 BRK = 0x00;
    /* LDA - Load Accumelator */
    constexpr u8 LDA_IM = 0xA9;
    /* STA - Store Accumulator */
    constexpr u8 STA_ZP = 0x85;
}
