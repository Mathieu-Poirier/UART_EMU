#include "ring_buffer.hpp"
#include "uart_config.hpp"
#include "device_driver.hpp"
#include "stdint.h"

constexpr uint32_t BufSize = 1024;

class uart_driver: public device_driver {
private:
    uart_config config;
    RingBuffer<Byte, BufSize> rx_buffer;
    RingBuffer<Byte, BufSize> tx_buffer;


public:
    uart_driver() = default;
    ~uart_driver() override;
    void init() override;
    void close() override;
};