#pragma once

#include <stdint.h>

using Rate = uint32_t;
using Length = uint32_t;
using Byte = uint8_t;

enum class Endianness : Byte {
    BIG    = 0,
    LITTLE = 1
};

class uart_config final {
    private:
        Rate baud_rate = 0;
        Length packet_length = 0;
        Endianness endianness = Endianness::LITTLE;

    public:
        constexpr uart_config() = default;
        constexpr uart_config(const Rate& baud_rate, const Length& packet_length, const Endianness& endianness);
        
        uart_config(const uart_config& other) = default;
        uart_config& operator=(const uart_config& other) = default;
        
        uart_config(uart_config&& other) = default;
        uart_config& operator=(uart_config&& other) = default;

        ~uart_config() = default;

        [[nodiscard]] constexpr Rate get_baud_rate() const noexcept;
        [[nodiscard]] constexpr Length get_packet_length() const noexcept;
        [[nodiscard]] constexpr Endianness get_endianness() const noexcept;

        void set_baud_rate(const Rate& baud_rate) noexcept;
        void set_packet_length(const Length& packet_length) noexcept;
        void set_endianness(const Endianness& endianness) noexcept;
};