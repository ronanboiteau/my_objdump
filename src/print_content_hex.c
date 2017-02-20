#include <stdio.h>
#include "my_typedef.h"

void		print_content_hex(char *offset, t_uint idx, t_uint size)
{
  t_uint	idx_hex;

  idx_hex = 0;
  while (idx_hex < 16)
    {
      if (idx + idx_hex < size)
	printf("%02x", *(unsigned char *)(offset + idx + idx_hex));
      else
	printf("  ");
      ++idx_hex;
      if (idx_hex % 4 == 0)
	printf(" ");
    }
  if (idx_hex % 4 != 0)
    printf(" ");
  printf(" ");
}
