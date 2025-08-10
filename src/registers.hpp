#pragma once

#include "stdint.h"

using RegisterWidth = uint32_t;
using RegisterValue = uint32_t;
constexpr uint32_t RegisterCount = 10;

class registers {
protected:
  RegisterWidth regs[RegisterCount];
  
public:
    registers() = default;
    virtual ~registers() = default;

    [[nodiscard]] virtual const RegisterWidth* dump_registers() const noexcept = 0;
    virtual void write_register(RegisterWidth address, RegisterValue value) noexcept = 0;
    [[nodiscard]] virtual RegisterValue read_register(RegisterWidth address) const noexcept = 0;
    [[nodiscard]] virtual RegisterWidth get_register_width() const noexcept = 0;

};