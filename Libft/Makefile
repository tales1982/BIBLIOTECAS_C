SRC = 	ft_strlen.c \
	ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strlcpy.c

NAME	=	libft.a
OBJS	=	${SRC:.c=.o}
CC	=	cc
RM	=	rm -f

CFLAGS =	-Wall -Wextra -Werror

.c.o:
	@ ${CC}  ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@ ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
		@ ${RM} ${OBJS}

fclean:	clean
				@ ${RM} ${NAME}

re:			fclean all
