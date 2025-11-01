NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRCS = ft_printf.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putsigned.c \
	ft_puthex.c \
	ft_putptr.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	ar rsc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
