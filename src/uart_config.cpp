#include "uart_config.hpp"

constexpr uart_config::uart_config(const Rate& baud_rate, const Length& data_bits, const Endianness& endianness)
    : baud_rate(baud_rate), data_bits_length(data_bits), endianness(endianness) {}

constexpr Rate uart_config::get_baud_rate() const noexcept {
    return baud_rate;
}

constexpr Length uart_config::get_data_bits_length() const noexcept {
    return data_bits_length;
}

constexpr Endianness uart_config::get_endianness() const noexcept {
    return endianness;
}

void uart_config::set_baud_rate(const Rate& baud_rate) noexcept {
    this->baud_rate = baud_rate;
}

void uart_config::set_data_bits(const Length& data_bits) noexcept {
    this->data_bits_length = data_bits;
}

void uart_config::set_endianness(const Endianness& endianness) noexcept {
    this->endianness = endianness;
}