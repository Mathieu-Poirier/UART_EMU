#include "uart_memory.hpp"

const RegisterWidth* uart_memory::dump_registers() const noexcept {
   return regs;
}

void uart_memory::write_register(RegisterWidth address, RegisterValue value) noexcept {
    regs[address] = value;
}

RegisterValue uart_memory::read_register(RegisterWidth address) const noexcept {
    return regs[address];
}

