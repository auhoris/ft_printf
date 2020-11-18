SRCS	=  ft_strmapi.c ft_putnbr_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_itoa.c ft_memmove.c ft_isalpha.c ft_memchr.c ft_strchr.c ft_strlen.c ft_substr.c ft_atoi.c ft_isascii.c ft_memcmp.c ft_strdup.c ft_strncmp.c ft_tolower.c ft_bzero.c ft_isdigit.c ft_memcpy.c ft_strjoin.c ft_strnstr.c ft_toupper.c ft_calloc.c ft_isprint.c ft_memset.c ft_strlcat.c ft_strrchr.c ft_isalnum.c ft_memccpy.c ft_split.c ft_strlcpy.c ft_strtrim.c ft_putchar.c ft_putstr.c ft_strndup.c ft_strncpy.c ft_itoa_u_base.c

HDR		= libft.h

SRCS_B	= ft_lstmap.c  ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c 

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

NAME	= libft.a

.c.o:
		${CC} ${CFLAGS} -c $< -o $@ -I ${HDR}
	

$(NAME):	${OBJS}
			ar rc $(NAME) ${OBJS}
			ranlib $(NAME)
	
bonus:		${OBJS_B} ${OBJS}
			ar rc $(NAME) ${OBJS_B} ${OBJS}
			ranlib $(NAME)

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBJS_B}

fclean:	clean
		${RM} ${NAME}
	
re:		fclean all

.PHONY:	fclean clean re all bonus
