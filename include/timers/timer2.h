#ifndef LAMB_DRUMMER_TIMER2_H
#define LAMB_DRUMMER_TIMER2_H

class timer2 {
private:
  static timer2 *     _instance;
public:
  void    setup();
  void    isr();
  static  timer2 &     instance();
};

#endif
