#include <stdbool.h>

int		my_char_isprintable(char letter)
{
  if (letter >= 32 && letter < 127)
    return (true);
  return (false);
}
