#ifndef SHELF_CLOCK_BUFFER_H
#define SHELF_CLOCK_BUFFER_H

template <typename T> 
class Buffer256 {
  private: 
  uint8_t write_ix;
  uint8_t read_ix;
  uint8_t _count;
  volatile T buff[256];
  
  public:
  Buffer256() : read_ix(0), write_ix(0), _count(0) {}
  ~Buffer256() {}

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
class Buffer {
  private: 
   uint8_t write_ix;
   uint8_t read_ix;
   uint8_t _count;
   T buff[SIZE];
  
  public:
  Buffer() : read_ix(0), write_ix(0), _count(0) {}
  ~Buffer() {}
  
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
