NAME = libft.a
CFLAGS = -c -g
lib_FILES = ft_strlen.c ft_atoi.c ft_isalpha.c ft_strdup.c ft_strchr.c ft_strcpy.c ft_strncpy.c ft_memset.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strupr.c ft_strlwr.c ft_strbuf.c ft_isnum.c ft_itoa_base.c ft_ftoa.c
pf_FILES = ft_printf.c ft_vasprintf.c node_init.c arg_node.c modifier.c is_checks.c is_checks2.c str_tasks.c mod_string.c mod_assist.c mod_assist2.c width_prec.c width_prec2.c num_tasks.c
lib_OBJ = $(lib_FILES:.c=.o)
pf_OBJ = $(pf_FILES:.c=.o)

all: $(NAME)

$(NAME): obj
	@ar rc $(NAME) $(lib_OBJ) $(pf_OBJ)
	@ranlib $(NAME)

obj: $(lib_FILES) $(pf_FILES)
	@gcc $(CFLAGS) $(lib_FILES) $(pf_FILES)

clean:
	@rm -f $(lib_OBJ) $(pf_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) obj clean fclean re
