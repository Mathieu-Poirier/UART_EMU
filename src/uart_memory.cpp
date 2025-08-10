#include "uart_memory.hpp"

enum class register_id : Byte {
    UARTDR = 0,
    UARTECR = 1,
    UARTSR = 2,
    UARTDRR = 3,
};

const RegisterWidth* uart_memory::dump_registers() const noexcept {
   return regs;
}

void uart_memory::write_register(RegisterWidth address, RegisterValue value) noexcept {
    regs[address] = value;
}

RegisterValue uart_memory::read_register(RegisterWidth address) const noexcept {
    return regs[address];
}

RegisterWidth uart_memory::get_register_width() const noexcept {
    return sizeof(RegisterWidth);
}
