.PHONY: all clean fclean re

NAME	=  libft.a
CC		=  gcc
CFLAGS	= -Wall -Wextra -Werror
# LDFLAGS	=
HEAD	=  -I includes/

isx_src =  ft_isalnum.c	ft_isalpha.c	ft_isascii.c	ft_isdigit.c		\
		   ft_isprint.c
isx		=  $(addprefix srcs/isx/, $(isx_src))

mem_src	=  ft_bzero.c	ft_memccpy.c	ft_memcmp.c	ft_memdel.c	ft_memset.c	\
		   ft_memalloc.c	ft_memchr.c	ft_memcpy.c	ft_memmove.c
memory	=  $(addprefix srcs/memory/, $(mem_src))

put_src	=  ft_putchar.c	ft_putendl.c	ft_putnbr.c	ft_putstr.c				\
		   ft_putwchar.c	ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	\
		   ft_putstr_fd.c	ft_putwstr.c
put		=  $(addprefix srcs/put/, $(put_src))

str_src	=  ft_strcat.c	ft_strdup.c	ft_strlen.c	ft_strnequ.c	ft_strsub.c	\
		   ft_strchr.c	ft_strequ.c	ft_strmap.c	ft_strnew.c	ft_strtrim.c	\
		   ft_strclr.c	ft_striter.c	ft_strmapi.c	ft_strnstr.c		\
		   ft_strcmp.c	ft_striteri.c	ft_strncat.c	ft_strrchr.c		\
		   ft_strcpy.c	ft_strjoin.c	ft_strncmp.c	ft_strsplit.c		\
		   ft_strdel.c	ft_strlcat.c	ft_strncpy.c	ft_strstr.c
string	=  $(addprefix srcs/string/, $(str_src))

xtox_src=  ft_atoi.c	ft_itoa.c	ft_tolower.c	ft_toupper.c
xtox	=  $(addprefix srcs/xtox/, $(xtox_src))

pf_src	=  convert_str.c	read_length.c	conversion_handler.c			\
		   convert_uint.c		tool_txt_color.c	convert_char.c			\
		   convert_wildcard.c	tool_txt_format.c	convert_int.c			\
		   ft_printf.c	tool_txt_mods.c	convert_n.c		padding.c			\
		   tool_txt_reset.c	convert_ptr.c	read_format.c	tool_txt_validate.c
printf	=  $(addprefix srcs/ft_printf/, $(pf_src))

extra	=  srcs/get_next_line/get_next_line.c

src		=  $(isx) $(memory) $(put) $(string) $(xtox)
obj		=  $(src:.c=.o)
dep		=  $(obj:.o=.d)

all: $(NAME)

$(NAME): $(obj)
	@ar rc $(NAME) $^
	@echo "libft compiled."

-include $(dep)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEAD) -o $@ -c $<

%.d: %.c
	@$(CPP) $(CFLAGS) $(HEAD) $< -MM -MT $(@:.d=.o) >$@

clean:
	@rm -f $(obj)
	@echo "Files cleaned."

fclean: clean
	@rm -f $(NAME) $(dep)

re: fclean all