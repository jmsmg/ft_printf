CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbr_hexa.c ft_putnbr_unsign.c ft_putstr.c
INCLUDED = libftprintf.h
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDED)

$(NAME) : $(OBJS)
	ar -rc $@ $(OBJS)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
