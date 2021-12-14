# string

A tiny library for heap-allocated strings in C. Provides a basic skeleton to which features can easily be added. Compatible with any standard C-library functions.

## Using

To use this library in a project, simply copy `String.c` and `String.h` into your project - that's it. There are no dependencies.

The library is easily extendable/trimmable. The only essential functions are:
- `string_create`
- `string_destroy`
- `string_expand`
- `string_append_chars`

If you don't need the other functions, just delete them. If you want more functionality, just add more functions (use the included functions for reference).

## Issues

If you encounter any issues which you believe are bugs, please submit an issue.
