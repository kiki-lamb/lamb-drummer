#ifndef SHELF_CLOCK_FLAG_H
#define SHELF_CLOCK_FLAG_H

class Flag {
public:
  char * name;
  Flag(
    char * _name = 0,
    bool _value = false
  );
  void flag();
  bool consume();
  void unflag();
private:
  bool value;
};

#endif
