#include <stdio.h>

#ifndef MENU_H
#define MENU_H

static inline void MENU() {
  printf("./main e c 'word' -> to encrypt with caesar\n");
  printf("./main d c 'word' -> to decrypt with caesar\n");
  printf("./main e v 'word' -> to encrypt with vigenére\n");
  printf("./main d v 'word' -> to decrypt with vigenére\n");
}

#endif