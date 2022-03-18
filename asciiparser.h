

#ifndef __ASCIIPARSER_H__
#define __ASCIIPARSER_H__

#include "./resources/defs.h"

#define PARSER_BUFFER_SIZE 64

int ascii_parser(char* str, char **sentences, char div);
int ascii_free_buffer( char **str, int num);

#endif  // #ifndef __ASCIIPARSER_H__
