SRCS = ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memccpy.c\
	   ft_memmove.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strlen.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strnstr.c\
	   ft_strncmp.c\
	   ft_atoi.c\
	   ft_isalpha.c\
	   ft_strncmp.c\
	   ft_atoi.c\
	   ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_calloc.c\
	   ft_strdup.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_split.c\
	   ft_itoa.c\
	   ft_strmapi.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   get_next_line.c\
	   get_next_line_utils.c
BONUS = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c
OBJS = $(SRCS:.c=.o)
OBONUS = $(BONUS:.c=.o)
NAME = libft.a
GCC = gcc
ARRC = ar rc
RLIB = ranlib
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
		$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

${NAME}:	$(OBJS)
			$(ARRC) $(NAME) $(OBJS)
			$(RLIB) $(NAME)

bonus:		$(OBJS) $(OBONUS)
			$(ARRC) $(NAME) $(OBJS) $(OBONUS)
			$(RLIB) $(NAME)
clean:
			$(RM) $(OBJS) $(OBONUS)
			
fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all bonus clean fclean re
