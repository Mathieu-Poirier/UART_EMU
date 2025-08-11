#pragma once

#include "stdint.h"

using RegisterWidth = uint32_t;
using RegisterValue = uint32_t;
using Byte = uint8_t;

enum class register_id : Byte {
  UARTD0 = 0,
  UARTD1 = 1,
  UARTD2 = 2,
  UARTD3 = 3,
  UARTD4 = 4,
  UARTD5 = 5,
  UARTD6 = 6,
  UARTD7 = 7,
  UARTRW = 8,
  UARTCLK = 9,
  UARTINT = 10,
  REGISTER_COUNT = 11,
};

class registers {
protected:
  RegisterWidth regs[static_cast<unsigned long>(register_id::REGISTER_COUNT)];
  
public:
    registers() = default;
    virtual ~registers() = default;

    [[nodiscard]] virtual const RegisterWidth* dump_registers() const noexcept = 0;
    virtual void write_register(RegisterWidth address, RegisterValue value) noexcept = 0;
    [[nodiscard]] virtual RegisterValue read_register(RegisterWidth address) const noexcept = 0;

};