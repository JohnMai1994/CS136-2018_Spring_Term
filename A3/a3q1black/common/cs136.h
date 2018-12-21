/*****************************************************************************
                _   _____    __   
    ___   ___  / | |___ /   / /_  
   / __| / __| | |   |_ \  | '_ \ 
  | (__  \__ \ | |  ___) | | (_) |
   \___| |___/ |_| |____/   \___/ 
   
   The CS 136 tools library
   by Dave Tompkins [dtompkins@uwaterloo.ca]
   (with help from other CS 136 team members)
   
   Version: 0.6 -- release for A3
   
 ****************************************************************************/

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/****************************************************************************
  TRACING TOOLS
****************************************************************************/

// These tracing tools can be used to help debug your code.
// They will not interfere with Marmoset tests or any I/O testing.


// trace_off() Turns off all tracing messages
//   [by default they are turned on]
void trace_off(void);


// trace_msg(msg) Displays msg in the console

// trace_X(exp) displays a message in the console of the form:
//   exp => final value

//   X can be one of: int, bool, char, double, string, ptr, symbol

// example usage:
//   trace_msg("Hello, World!");
//   trace_int(1 + 1);


// trace_sync() "Syncronizes" tracing and printf output by
//   forcing all of the tracing messages to go to the same
//   stream as printf (stdout)
//   NOTE: this may cause your Marmoset and I/O tests to fail
void trace_sync(void);


// trace_version() displays the current version of the cs136 tools library
void trace_version(void);

/****************************************************************************
  I/O TOOLS
 ****************************************************************************/

// the constant READ_FAIL is returned by read_int() when:
// * the next input could not be successfully read, or
// * the end of input (e.g., EOF) is encountered
extern const int READ_FAIL;

// read_int() returns either the next int from input or READ_FAIL
// effects: reads from input
int read_int(void);


// the constant INVALID_CHAR is returned by read_char when:
// * the next char in input is an invalid (unprintable) char, where
//   valid characters are in the range ' '...'~' or newline '\n'
// * the end of the input (e.g., EOF) is encountered
extern const char INVALID_CHAR;

// read_char(ignore_ws) returns the next valid char from input 
//   (which may or may not ignore_ws [whitespace]) or INVALID_CHAR
// effects: reads from input
char read_char(bool ignore_ws);

/****************************************************************************
  SYMBOL TOOLS
****************************************************************************/

// symbols follow the same naming convention as identifiers ("names") in C:
//   * they can only contain letters, underscores and numbers
//   * they must start with a letter
//   * they must be <= 63 characters
// at most there can be 255 symbols defined

// when reading or looking up symbols, they are assigned an int ID

// the constant INVALID_SYMBOL is returned by lookup_symbol & read_symbol when:
// * the next symbol in the input or the parameter is invalid
// * the end of the input (e.g., EOF) is encountered (read_symbol)
// * a new symbol is being defined and 255 symbols have already been defined
extern const int INVALID_SYMBOL;

// read_symbol(void) returns the ID for the next valid symbol from input
//   (which may be a new or existing ID) or INVALID_SYMBOL
// effects: reads from input
int read_symbol(void);

// lookup_symbol(symbol_string) returns the ID for symbol_string
//   (which may be a new or existing ID) or INVALID_SYMBOL
int lookup_symbol(const char *symbol_string);

// print_symbol(symbol_id) displays the symbol corresponding to symbol_id
// requires: symbol_id is a valid ID
// effects: displays a message
void print_symbol(int symbol_id);

/****************************************************************************
  TRACING MACROS
****************************************************************************/

// The following is a collection of macros that should be ignored
// They are an unfortuante but necessary evil to implement our tracing tools
// Seriously: Go away... there's nothing to see here...

#define _FFL __FILE__, __func__, __LINE__
#define _CCP const char *
#define trace_msg(msg) _TRACE_MSG(#msg, "", _FFL);
#define trace_int(exp) _TRACE_INT(#exp, (exp), _FFL);
#define trace_bool(exp) _TRACE_STRING(#exp, (exp) ? "true" : "false", _FFL);
#define trace_char(exp) _TRACE_CHAR(#exp, (exp), _FFL);
#define trace_double(exp) _TRACE_DOUBLE(#exp, (exp), _FFL);
#define trace_string(exp) _TRACE_STRING(#exp, (exp), _FFL);
#define trace_symbol(exp) _TRACE_SYMBOL(#exp, _SYM(exp), _FFL);
#define trace_ptr(exp) _TRACE_PTR(#exp, (void *) (exp), _FFL);
#define _DCLT(ctype, TYPE) void _TRACE_##TYPE(_CCP, ctype, _CCP, _CCP, int);
_CCP _SYM(int);
_DCLT(_CCP, MSG);
_DCLT(int, INT);
_DCLT(char, CHAR);
_DCLT(double, DOUBLE);
_DCLT(_CCP, STRING);
_DCLT(_CCP, SYMBOL);
_DCLT(void *, PTR);

/*****************************************************************************/
