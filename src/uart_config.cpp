#include "uart_config.hpp"

constexpr uart_config::uart_config(const Rate& baud_rate, const Length& packet_length, const Endianness& endianness)
    : baud_rate(baud_rate), packet_length(packet_length), endianness(endianness) {}

constexpr Rate uart_config::get_baud_rate() const noexcept {
    return baud_rate;
}

constexpr Length uart_config::get_packet_length() const noexcept {
    return packet_length;
}

constexpr Endianness uart_config::get_endianness() const noexcept {
    return endianness;
}

void uart_config::set_baud_rate(const Rate& baud_rate) noexcept {
    this->baud_rate = baud_rate;
}

void uart_config::set_packet_length(const Length& packet_length) noexcept {
    this->packet_length = packet_length;
}

void uart_config::set_endianness(const Endianness& endianness) noexcept {
    this->endianness = endianness;
}