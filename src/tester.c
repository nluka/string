#include <stdio.h>
#include "String.h"

String_t s;

void print_header(void) {
  printf("| data             | bytesAllocated | length | content\n");
  printf("------------------------------------------------------\n");
}

void print_string(void) {
  printf(
    "| %p | %-14zu | %-6zu | %s\n",
    s.data, s.bytesAllocated, s.length, s.data
  );
}

int main(void) {
  printf("string tester:\n\n");
  print_header();

  s = string_create(0);
  print_string();

  string_append_chars(&s, "Hello");
  print_string();

  string_expand(&s, 100);
  print_string();

  string_append_chars(&s, " ");
  print_string();

  string_append_chars(&s, "Hello");
  print_string();

  string_append_chars(&s, " ");
  print_string();

  string_append_uint64(&s, (uint64_t)0 - 1);
  print_string();

  string_append_chars(&s, " ");
  print_string();

  string_append_int(&s, 1 << 31);
  print_string();

  string_destroy(&s);
  print_string();

  return 0;
}
