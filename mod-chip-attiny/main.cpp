// cleaned-up Arduino main to save a few bytes

#include "Arduino.h"

int main(void) 
{
  //init();
  setup();
  for (;;) loop();
  return 0;
}
