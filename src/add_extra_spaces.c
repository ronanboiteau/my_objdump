#include <stdio.h>
#include "tools.h"
#include "my_typedef.h"

void		add_extra_spaces(t_uint *idx)
{
  if (*idx % 16 != 0)
    {
      while (*idx % 16 != 0)
	{
	  printf(" ");
	  *idx += 1;
	}
      printf("\n");
    }
}
