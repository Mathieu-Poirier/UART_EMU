template <typename T, uint32_t N>
RingBuffer<T, N>::RingBuffer() noexcept : head(0), tail(0), size(0) {}

template <typename T, uint32_t N>
RingBuffer<T, N>::~RingBuffer() noexcept {}

template <typename T, uint32_t N>
RingBuffer<T, N>::RingBuffer(const RingBuffer& other) noexcept
    : head(other.head), tail(other.tail), size(other.size) {
    for (uint32_t i = 0; i < N; ++i) {
        buffer[i] = other.buffer[i];
    }
}

template <typename T, uint32_t N>
RingBuffer<T, N>& RingBuffer<T, N>::operator=(const RingBuffer& other) noexcept {
    if (this != &other) {
        head = other.head;
        tail = other.tail;
        size = other.size;
        for (uint32_t i = 0; i < N; ++i) {
            buffer[i] = other.buffer[i];
        }
    }
    return *this;
}

template <typename T, uint32_t N>
RingBuffer<T, N>::RingBuffer(RingBuffer&& other) noexcept
    : head(other.head), tail(other.tail), size(other.size) {
    for (uint32_t i = 0; i < N; ++i) {
        buffer[i] = static_cast<T&&>(other.buffer[i]);
    }
    other.head = 0;
    other.tail = 0;
    other.size = 0;
}

template <typename T, uint32_t N>
RingBuffer<T, N>& RingBuffer<T, N>::operator=(RingBuffer&& other) noexcept {
    if (this != &other) {
        head = other.head;
        tail = other.tail;
        size = other.size;
        for (uint32_t i = 0; i < N; ++i) {
            buffer[i] = static_cast<T&&>(other.buffer[i]);
        }
        other.head = 0;
        other.tail = 0;
        other.size = 0;
    }
    return *this;
}


template <typename T, uint32_t N>
void RingBuffer<T, N>::reset() noexcept {
    head = 0;
    tail = 0;
    size = 0;
}

template <typename T, uint32_t N>
bool RingBuffer<T, N>::is_empty() const noexcept {
    return size == 0;
}

template <typename T, uint32_t N>
bool RingBuffer<T, N>::is_full() const noexcept {
    return size == N;
}

template <typename T, uint32_t N>
bool RingBuffer<T, N>::push(const T& value) noexcept {
    if (is_full()) {
        return false; 
    }
    buffer[head] = value;
    head = (head + 1) & (N - 1);
    size++;
    return true;
}

template <typename T, uint32_t N>
bool RingBuffer<T, N>::pop(T& value) noexcept {
    if (is_empty()) {
        return false;
    }
    value = buffer[tail];
    tail = (tail + 1) & (N - 1);
    size--;
    return true;
}

template <typename T, uint32_t N>
bool RingBuffer<T, N>::peek(T& value) const noexcept {
    if (is_empty()) return false;
    value = buffer[tail];
    return true;
}
