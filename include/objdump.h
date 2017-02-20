#ifndef OBJDUMP_H_
# define OBJDUMP_H_

# include <stdbool.h>
# include "my_typedef.h"

off_t		get_file_size(int fd);
void		add_extra_spaces(t_uint *idx);
bool		check_name(char const *name, bool is_exec);
void		objdump32(char *filepath, void *data, t_uchar *ret);
void		objdump64(char *filepath, void *data, t_uchar *ret);
void		print_content_hex(char *offset, t_uint idx, t_uint size);
bool		check_file(char *progname, char *filepath, int fd, void *data);

#endif /* !OBJDUMP_H_ */
