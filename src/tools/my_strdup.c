#include <stdlib.h>
#include "tools.h"

char		*my_strdup(const char *src)
{
  int		lenght;
  int		idx;
  char		*new_str;

  if (src == NULL)
    return (NULL);
  idx = 0;
  lenght = my_strlen(src);
  if ((new_str = malloc(sizeof(char) * (lenght + 1))) == NULL)
    return (NULL);
  while (src[idx])
    {
      new_str[idx] = src[idx];
      idx += 1;
    }
  new_str[idx] = '\0';
  return (new_str);
}
