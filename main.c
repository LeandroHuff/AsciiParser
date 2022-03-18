#include "./resources/defs.h"
#include "asciiparser.h"

char *text = "one,two,three,four,five,six,seven,eight,nine,bla,ble,bli,blo,blu,crc*,16";

char *str[] = {0};

int main ( int argc , char **argv )
{
  printf("Running ascii parser for string:\n\"%s\"\n\n", text);
  int numparams = ascii_parser( text, str, ',' );
  printf( "Num parameters: %d\n", numparams );
  int i;
  for(i = 0; i < numparams; i++)
  {
    printf("Parameter[%d]: %s\n", i+1, str[i]);
  }
  if(ascii_free_buffer(str, numparams) == SUCCESSFUL)
  {
    puts("Sucessful release parser memory.");
  }
  puts("\nFinished!\n");
  return 0;
}
