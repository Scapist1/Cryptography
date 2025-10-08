#include "caesar.h"
#include "menu.h"
#include "vigenere.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  // Check if enough arguments are provided
  if (argc < 4) {
    MENU();
    return 1;
  }

  // Declare a function pointer for the chosen cipher function
  void (*crypt_func)(char *) = NULL;

  // Get mode and cipher type from arguments
  char *mode = argv[1];
  char *cipher = argv[2];

  // Select the correct cipher function and its mode based on arguments
  if (strcmp(cipher, "c") == 0) {
    if (strcmp(mode, "e") == 0) {
      crypt_func = CAESAR_ENCRYPT;
    } else if (strcmp(mode, "d") == 0) {
      crypt_func = CAESAR_DECRYPT;
    }
  } else if (strcmp(cipher, "v") == 0) {
    if (strcmp(mode, "e") == 0) {
      crypt_func = VIGENERE_ENCRYPT;
    } else if (strcmp(mode, "d") == 0) {
      crypt_func = VIGENERE_DECRYPT;
    }
  }

  // If no valid function was selected, print usage and exit
  if (crypt_func == NULL) {
    MENU();
    return 1;
  }

  // Loop through all words provided as arguments and apply cipher
  for (int i = 3; i < argc; i++) {
    crypt_func(argv[i]);
    printf("%s", argv[i]);
    if (i < argc - 1)
      printf(" ");
  }
  printf("\n");

  return 0;
}