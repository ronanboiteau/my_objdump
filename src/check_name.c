#include <stdbool.h>
#include "tools.h"

bool           check_name(char const *name)
{
  bool         ret;

  ret = false;
  if (my_strcmp(name, "") != 0 &&
      my_strcmp(name, ".bss") != 0 &&
      my_strcmp(name, ".shstrtab") != 0 &&
      my_strcmp(name, ".strtab") != 0 &&
      my_strcmp(name, ".symtab") != 0)
    ret = true;
  return (ret);
}
