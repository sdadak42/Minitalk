NAMES 				= server client
NAMES_BONUS			= server_bonus client_bonus

OBJS 				= $(NAMES:=.o)
OBJS_BONUS 			= $(NAMES_BONUS:=.o)

CC 					= cc
CFLAGS 				= -Wall -Wextra -Werror
RM 					= rm -f

LIBFT_DIR 			= ./Printf
LIBFT_LIB 			= $(LIBFT_DIR)/libftprintf.a
LIBFT_MAKE 			= $(MAKE) -C $(LIBFT_DIR)

all: $(NAMES)

$(LIBFT_LIB):
	$(LIBFT_MAKE) all

$(NAMES): %: %.o $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $^

bonus: $(NAMES_BONUS)

$(NAMES_BONUS): %: %.o $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(LIBFT_MAKE) clean

fclean: clean
	$(RM) $(NAMES) $(NAMES_BONUS)
	$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re bonus