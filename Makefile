# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtomiki <rtomiki@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 14:58:30 by rtomiki           #+#    #+#              #
#    Updated: 2021/05/24 15:49:41 by rtomiki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_output.c ft_output_int.c ft_printf_utils.c ft_output_usint_ten.c ft_output_usint_hex.c ft_output_char.c ft_output_pchar.c ft_output_address.c ft_output_percent.c ft_output_input.c
OBJS = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.c.o:
			${CC} ${CFLAGS} -I . -c $< -o $*.o

$(NAME):	${OBJS}
			ar rcs $(NAME) $(OBJS)
			ranlib $(NAME)

all:		${NAME}

clean:
			${RM} ${OBJS} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: clean fclean all re
