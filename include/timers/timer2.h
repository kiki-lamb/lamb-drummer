#ifndef SHELF_CLOCK_TIMER2_H
#define SHELF_CLOCK_TIMER2_H

class Timer2_ {
private:
  static Timer2_ *     _instance;
public:
  Timer2_();
  virtual ~Timer2_();
  void    setup();
  void    isr();
  static  Timer2_ &     instance();
};

#endif
