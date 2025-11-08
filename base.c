#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* map(char *array, int array_length, char (*f) (char)) {
  char* mapped_array = (char*)malloc(array_length * sizeof(char));
  if (!mapped_array) return NULL;
  for (int i = 0; i < array_length; i++) {
    mapped_array[i] = f(array[i]);
  }
  return mapped_array;
}

char my_get(char c) {
  int ch = fgetc(stdin);
  return (ch == EOF) ? c : (char)ch;  // ignores c, returns input
}

char cxprt(char c) {
  unsigned char uc = (unsigned char)c;
  if (uc >= 0x20 && uc <= 0x7E) printf("%c ", uc);
  else                          printf(". ");
  printf("%02x\n", uc);
  return c;
}

char encrypt(char c) {
  unsigned char uc = (unsigned char)c;
  if (uc >= 0x20 && uc <= 0x7E) return (char)(uc + 1);
  return c;
}

char decrypt(char c) {
  unsigned char uc = (unsigned char)c;
  if (uc >= 0x21 && uc <= 0x7F) return (char)(uc - 1);
  return c;
}

char dprt(char c) {
  printf("%u\n", (unsigned int)(unsigned char)c);
  return c;
}

int main(int argc, char **argv) {
  int base_len = 5;
  char arr1[base_len];

  // read 5 chars from stdin
  char* arr2 = map(arr1, base_len, my_get);
  // print decimal
  char* arr3 = map(arr2, base_len, dprt);
  // print char/hex
  char* arr4 = map(arr3, base_len, cxprt);

  free(arr2);
  free(arr3);
  free(arr4);
  return 0;
}