#include <string.h>
#include <stdio.h>
#include "String.h"

#define lli long long int

/*
  constructs a String and returns it, allocating enough memory to hold
  `initialCount` chars + 1 for nul-terminator
*/
String_t string_create(size_t const initialCount) {
  String_t string;

  size_t const bytesNeeded = initialCount + 1; // 1 for nul
  string.data = calloc(bytesNeeded, sizeof *string.data);
  string.bytesAllocated = bytesNeeded;
  string.length = 0;

  return string;
}

/*
  resizes `data` by `expansionAmount`,
  returns boolean indicating whether expansion was successful
*/
bool string_expand(String_t *const string, size_t const expansionAmount) {
  size_t const bytesNeeded = string->bytesAllocated + expansionAmount;

  char *newData = NULL;
  newData = realloc(string->data, bytesNeeded);
  if (newData == NULL) {
    return false;
  }

  string->data = newData;
  string->bytesAllocated = bytesNeeded;

  return true;
}

/*
  attempts to append `chars` to `string`,
  returns boolean indicating whether append was successful
*/
bool string_append_chars(String_t *const string, char const *const chars) {
  size_t const charCount = strlen(chars);

  lli const overflowCount =
    (string->length + charCount) - (string->bytesAllocated - 1);

  if (overflowCount > 0 && !string_expand(string, (size_t)overflowCount)) {
    return false;
  }

  size_t const writtenCount = (size_t)snprintf(
    string->data + string->length,
    charCount + 1,
    "%s",
    chars
  );

  string->length += writtenCount;
  bool const wasAppendSuccessful = writtenCount == charCount;
  return wasAppendSuccessful;
}

/*
  attempts to append `number` to `string`,
  returns boolean indicating whether append was successful
*/
bool string_append_int(String_t *const string, int const number) {
  char buffer[12];

  size_t const digitCount = (size_t)snprintf(
    buffer,
    sizeof buffer,
    "%d",
    number
  );

  lli const overflowCount =
    (string->length + digitCount) - (string->bytesAllocated - 1);

  if (overflowCount > 0 && !string_expand(string, (size_t)overflowCount)) {
    return false;
  }

  size_t const writtenCount = (size_t)snprintf(
    string->data + string->length,
    digitCount + 1,
    "%s",
    buffer
  );

  string->length += writtenCount;
  bool const wasAppendSuccessful = writtenCount == digitCount;
  return wasAppendSuccessful;
}

/*
  attempts to append `number` to `string`,
  returns boolean indicating whether append was successful
*/
bool string_append_uint64(String_t *const string, uint64_t const number) {
  char buffer[21];

  size_t const digitCount = (size_t)snprintf(
    buffer,
    sizeof buffer,
    "%" PRIu64,
    number
  );

  lli const overflowCount =
    (string->length + digitCount) - (string->bytesAllocated - 1);

  if (overflowCount > 0 && !string_expand(string, (size_t)overflowCount)) {
    return false;
  }

  size_t const writtenCount = (size_t)snprintf(
    string->data + string->length,
    digitCount + 1,
    "%s",
    buffer
  );

  string->length += writtenCount;
  bool const wasAppendSuccessful = writtenCount == digitCount;
  return wasAppendSuccessful;
}

/*
  destroys `string`, freeing `string->data`
*/
void string_destroy(String_t *const string) {
  free(string->data);
  string->data = NULL;
  string->bytesAllocated = 0;
  string->length = 0;
}

#undef lli
