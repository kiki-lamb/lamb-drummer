#ifndef LAMB_DRUMMER_TIMER2_H
#define LAMB_DRUMMER_TIMER2_H

class timer2_ {
private:
  static timer2_ *     _instance;
public:
  timer2_();
  /* virtual */ ~timer2_();
  void    setup();
  void    isr();
  static  timer2_ &     instance();
};

#endif
