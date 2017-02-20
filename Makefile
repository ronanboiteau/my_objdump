NAME		= my_objdump

INC		= include/

CC		= gcc
CFLAGS		+= -I $(INC)
CFLAGS		+= -Wall -Wextra -Werror

RM		= rm -f

TOOLS_DIR	= tools/
TOOLS_FILES	= match.c			\
		  my_char_isprintable.c		\
		  my_strcmp.c			\
		  my_strdup.c			\
		  my_strlen.c
TOOLS		= $(addprefix $(TOOLS_DIR), $(TOOLS_FILES))

SRCS_DIR	= src/
SRCS_FILES	= check_name.c			\
		  add_extra_spaces.c		\
		  main.c			\
		  objdump32.c			\
		  objdump64.c			\
		  error.c			\
		  print_content_hex.c		\
		  $(TOOLS)
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS		= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
