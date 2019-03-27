#ifndef SHELF_CLOCK_BUFFER_H
#define SHELF_CLOCK_BUFFER_H

template <typename T>
class RingBuffer256 {
  private:
  uint8_t write_ix;
  uint8_t read_ix;
  uint8_t _count;
  volatile T buff[256];

  public:
  RingBuffer256() : write_ix(0), read_ix(0), _count(0) {}
  ~RingBuffer256() {}

  uint8_t count() const {
    return _count;
  }

  inline void write(T t) {
    buff[write_ix] = t;
    _count++;
    write_ix++;
  }

  inline T read() {
    T tmp = buff[read_ix];
    _count--;
    read_ix++;
    return tmp;
  }

  inline bool writeable() {
    return _count < 255;
  }

  inline bool readable() {
    return _count;
  }
};

template <typename T, uint8_t SIZE>
class RingBuffer {
  private:
   uint8_t write_ix;
   uint8_t read_ix;
   uint8_t _count;
   T buff[SIZE];

  public:
  RingBuffer() : write_ix(0), read_ix(0), _count(0) {}
  ~RingBuffer() {}

  uint8_t count() const {
    return _count;
  }

  inline void write(T t) {
    buff[write_ix] = t;
    _count++;
    write_ix++;
    write_ix %= SIZE;
  }

  inline T read() {
    T tmp = buff[read_ix];
    _count--;
    read_ix++;
    read_ix %= SIZE;

    return tmp;
  }

  inline bool writeable() {
    return _count < SIZE;
  }

  inline bool readable() {
    return _count;
  }
};

#endif
