#pragma once
#include "stdint.h"

template <typename T, uint32_t N>
class RingBuffer {
private:
    T buffer[N];
    uint32_t head;
    uint32_t tail;
    uint32_t size;

public:
    
    static_assert((N & (N - 1)) == 0, "RingBuffer size N must be a power of two.");

    RingBuffer() noexcept;
    virtual ~RingBuffer() noexcept;

    RingBuffer(const RingBuffer& other) noexcept;
    RingBuffer& operator=(const RingBuffer& other) noexcept;

    RingBuffer(RingBuffer&& other) noexcept;
    RingBuffer& operator=(RingBuffer&& other) noexcept;

    void reset() noexcept;

    [[nodiscard]] bool is_empty() const noexcept;
    [[nodiscard]] bool is_full()  const noexcept;

    bool push(const T& value) noexcept;
    bool pop(T& value) noexcept;
    bool peek(T& value) const noexcept;
};

#include "ring_buffer.tpp"
