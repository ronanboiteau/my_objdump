#include <stdlib.h>
#include "my_typedef.h"

int		my_strcmp(char const *str1, char const *str2)
{
  t_uint	idx;

  if (str1 == NULL || str2 == NULL)
    return (-1);
  idx = 0;
  while (str1[idx] != '\0' && str2[idx] != '\0')
    {
      if (str1[idx] != str2[idx])
	return (str1[idx] - str2[idx]);
      idx += 1;
    }
  if (str1[idx] == '\0' && str2[idx] == '\0')
    return (0);
  return (-1);
}
