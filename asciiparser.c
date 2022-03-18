#include "./resources/defs.h"
#include "asciiparser.h"



int ascii_parser(char* str, char **sentences, char div)
{
  //Check null pointer parameters, if detected, return an error code.
  CHECK_NULL_PTR(      str, ERROR);
  CHECK_NULL_PTR(sentences, ERROR);
  CHECK_EQU_VALUE(div, '\0', ERROR);

  DEF_BUFFER(char, stmp, PARSER_BUFFER_SIZE);

  char* s = str;
  int pos = 0;
  int parameters = 1;

  //find how many parameters have in string str, start at least with 1.
  while(*s != '\0')
  {
    if(*s == div)
    {
      parameters++;
    }
    s++;
  }

  *sentences = calloc(parameters, sizeof(char*));
  CHECK_NULL_PTR(*sentences, ERROR);

  //restart string pointer to the beggining.
  s = str;

  //find each parameter and sotore it in the pointer vector.
  while(*s != '\0')
  {
    int idx = 0;

    //store char by char while not find an end of string ('\0') or 
    //not find a divisor parameter character ',' or ';' or '.' etc according to *div parameter.
    while ( (*s != '\0') && (*s != div) )
    {
      stmp[idx++] = *s;
      s++;
    }

    stmp[idx] = '\0';
    sentences[pos++] = (char*)STRDUP(stmp);
    if(*s == div)
    {
      s++;
    }
  }

  return pos;
}

int ascii_free_buffer( char **str, int num)
{
  CHECK_NULL_PTR(str, ERROR);
  CHECK_EQU_VALUE(num, 0, ERROR);

  int idx;

  for (idx = 0; idx < num; idx++ )
  {
    FREE( str[idx] );
  }

  FREE( *str );

  return SUCCESSFUL;
}