#include "vigenere.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_KEY "LEMON"

void VIGENERE_ENCRYPT(char *word) {
  const char *key = DEFAULT_KEY;
  int keylen = strlen(key);
  for (int i = 0, j = 0; word[i] != '\0'; i++) {
    if (isalpha(word[i])) {
      char k = key[j % keylen] - 'A';
      word[i] = ((word[i] - 'A' + k + 26) % 26) + 'A';
      j++;
    }
  }
}

void VIGENERE_DECRYPT(char *word) {
  const char *key = DEFAULT_KEY;
  int keylen = strlen(key);
  for (int i = 0, j = 0; word[i] != '\0'; i++) {
    if (isalpha(word[i])) {
      char k = key[j % keylen] - 'A';
      word[i] = ((word[i] - 'A' - k + 26) % 26) + 'A';
      j++;
    }
  }
}