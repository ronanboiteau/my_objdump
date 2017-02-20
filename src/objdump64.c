#include <elf.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_typedef.h"
#include "objdump.h"
#include "tools.h"

static void	print_section_content(void *data, Elf64_Shdr *shdr)
{
  t_uint	idx;
  t_uint	addr;

  addr = shdr->sh_addr;
  idx = 0;
  while (idx < shdr->sh_size)
    {
      if (idx % 16 == 0)
	{
	  printf(" %04x ", addr);
	  addr += 16;
	  print_content_hex(data + shdr->sh_offset, idx, shdr->sh_size);
	}
      if (my_char_isprintable(*(char *)(data + shdr->sh_offset + idx)) == true)
	printf("%c", *(char *)(data + shdr->sh_offset + idx));
      else
	printf(".");
      ++idx;
      if (idx % 16 == 0)
	printf("\n");
    }
  add_extra_spaces(&idx);
}

static void	print_sections(void *data,
			       Elf64_Ehdr *elf,
			       Elf64_Shdr *shdr,
			       char *str_tab)
{
  t_uint	idx;

  idx = 0;
  while (idx < elf->e_shnum)
    {
      if (check_name(&str_tab[shdr[idx].sh_name],
		     (elf->e_type == ET_REL ? false : true)) == true)
	{
	  printf("Contents of section %s:\n", &str_tab[shdr[idx].sh_name]);
	  print_section_content(data, shdr + idx);
	}
      ++idx;
    }
}

static t_uint	get_text_address(Elf64_Ehdr const *elf,
				 Elf64_Shdr const *shdr,
				 char const *str_tab)
{
  t_uint	idx;

  idx = 0;
  while (idx < elf->e_shnum)
    {
      if (my_strcmp(".text", &str_tab[shdr[idx].sh_name]) == 0)
	return (shdr[idx].sh_addr);
      ++idx;
    }
  return (0);
}

static int	print_file_headers(char const *prog_name,
				   void const *data,
				   Elf64_Ehdr const *elf,
				   Elf64_Shdr const *shdr)
{
  char		*str_tab;
  t_uint	text_addr;

  str_tab = (char *)(data + shdr[elf->e_shstrndx].sh_offset);
  printf("\n%s:     file format ", prog_name);
  printf("elf64-x86-64\n");
  printf("architecture: i386:x86-64, flags ");
  if (elf->e_type == ET_REL)
    {
      printf("0x00000011:\n");
      printf("HAS_RELOC, HAS_SYMS\n");
    }
  else
    {
      printf("0x00000112:\n");
      printf("EXEC_P, HAS_SYMS, D_PAGED\n");
    }
  text_addr = get_text_address(elf, shdr, str_tab);
  printf("start address 0x%016x\n\n", text_addr);
  return (0);
}

void		objdump64(char *filepath, void *data, t_uchar *ret)
{
  Elf64_Ehdr	*elf;
  Elf64_Shdr	*shdr;
  char		*str_tab;

  elf = (Elf64_Ehdr *)data;
  shdr = (Elf64_Shdr *)(data + elf->e_shoff);
  str_tab = (char *)(data + shdr[elf->e_shstrndx].sh_offset);
  if (print_file_headers(filepath, data, elf, shdr) == -1)
    *ret = 1;
  print_sections(data, elf, shdr, str_tab);
}
