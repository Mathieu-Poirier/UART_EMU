#include "uart_driver.hpp"

uart_driver::uart_driver(const uart_config &config, const uart_memory &memory)
    : memory(memory), config(config) {}

