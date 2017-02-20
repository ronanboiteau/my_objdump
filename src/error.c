#include <elf.h>
#include <stdbool.h>
#include <stdio.h>
#include "objdump.h"

static bool	check_magic(void *data)
{
  if (*(char *)(data + 0) != '\x7f' ||
      *(char *)(data + 1) != 'E' ||
      *(char *)(data + 2) != 'L' ||
      *(char *)(data + 3) != 'F')
    return (false);
  return (true);
}

static bool	check_size(int fd)
{
  off_t		actual_size;

  actual_size = get_file_size(fd);
  if (actual_size < (off_t)sizeof(Elf64_Ehdr))
    return (false);
  return (true);
}

static bool	check_struct_size(int fd, void *data)
{
  if (((Elf64_Ehdr *)data)->e_ident[EI_CLASS] == ELFCLASS32)
    {
      if ((off_t)((((Elf32_Ehdr *)data)->e_shentsize *
		   ((Elf32_Ehdr *)data)->e_shnum) +
		  ((Elf32_Ehdr *)data)->e_shoff) != get_file_size(fd))
	return (false);
      return (true);
    }
  else if (((Elf64_Ehdr *)data)->e_ident[EI_CLASS] == ELFCLASS64)
    {
      if ((off_t)((((Elf64_Ehdr *)data)->e_shentsize *
		   ((Elf64_Ehdr *)data)->e_shnum)
		  + ((Elf64_Ehdr *)data)->e_shoff) != get_file_size(fd))
	return (false);
      return (true);
    }
  return (false);
}

bool		check_file(char *progname, char *filepath, int fd, void *data)
{
  if (check_size(fd) == false || check_struct_size(fd, data) == false)
    {
      dprintf(2, "%s: %s: File truncated\n", progname, filepath);
      return (false);
    }
  if (check_magic(data) == false)
    {
      dprintf(2, "%s: %s: File format not recognized\n", progname, filepath);
      return (false);
    }
  return (true);
}
