#include "registers.hpp"

using Byte = uint8_t;

class uart_memory : public registers {
private:
    enum class register_id : Byte {
        // Implement later
    };
public:
    uart_memory() = default;
    ~uart_memory() = default;

    [[nodiscard]] const RegisterWidth* dump_registers() const noexcept override;
    void write_register(RegisterWidth address, RegisterValue value) noexcept override;
    [[nodiscard]] RegisterValue read_register(RegisterWidth address) const noexcept override;
    [[nodiscard]] RegisterWidth get_register_width() const noexcept override;
};