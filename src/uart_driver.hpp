#include "ring_buffer.hpp"
#include "uart_config.hpp"
#include "uart_memory.hpp"
#include <stdint.h>

constexpr Byte BufSize = 16;

class uart_driver {
private:
    uart_memory memory;
    uart_config config;
    RingBuffer<Byte, BufSize> rx_buffer;
    RingBuffer<Byte, BufSize> tx_buffer;


public:
  uart_driver() = default;
  uart_driver(const uart_config& config, const uart_memory& memory);
  virtual ~uart_driver() = default;

};