SRC	= ft_printf.c \
	  ft_start_parsing.c \
	  ft_inset.c \
	  ft_disp_char.c \
	  ft_make_filler.c \
	  ft_disp_str.c \
	  ft_disp_int.c \
	  ft_int_sign.c \
	  ft_prep_for_print.c \
	  ft_disp_u.c \
	  ft_disp_p.c \
	  ft_disp_percent.c \
	  ft_itoa_ll.c \

OBJ	= $(SRC:.c=.o)

LIBFT	= libft/

L_COMP	= libft.a

HDR	= ft_printf.h

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= libftprintf.a

RM	= rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HDR)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp $(LIBFT)$(L_COMP) .
	@mv $(L_COMP) $(NAME)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all:	$(NAME)

bonus:	all

clean:
	$(RM) $(OBJ)
	@make -C $(LIBFT) clean

fclean:	clean
	$(RM) $(NAME)
	@make -C $(LIBFT) fclean

re:	fclean all

.PHONY:	fclean clean re all .c.o bonus
