#include "caesar.h"
#include <ctype.h>
#include <stdio.h>

void CAESAR_ENCRYPT(char *word) {
  for (int i = 0; word[i] != '\0'; i++) {
    word[i] = ((word[i] - 'A' - 3 + 26) % 26) + 'A';
  }
}

void CAESAR_DECRYPT(char *word) {
  for (int i = 0; word[i] != '\0'; i++) {
    word[i] = ((word[i] - 'A' + 3) % 26) + 'A';
  }
}