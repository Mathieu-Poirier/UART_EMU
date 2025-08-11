#include "registers.hpp"

class uart_memory : public registers {
public:
    uart_memory() = default;
    ~uart_memory() = default;

    [[nodiscard]] const RegisterWidth* dump_registers() const noexcept override;
    void write_register(RegisterWidth address, RegisterValue value) noexcept override;
    [[nodiscard]] RegisterValue read_register(RegisterWidth address) const noexcept override;
};