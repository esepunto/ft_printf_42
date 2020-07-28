# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssacrist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/17 15:14:53 by ssacrist          #+#    #+#              #
#    Updated: 2020/07/22 11:30:54 by ssacrist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRC			=	ft_printf.c \
				src/dec_left_minus.c \
				src/dec_neg.c \
				src/dec_no_minusneg.c \
				src/hexa_all.c \
				src/unsign_all.c \
				src/pointer.c \
				src/pointer2.c \
				src/utils/dec_to_hexa.c \
				src/utils/flags.c \
				src/utils/fts_to_print.c \
				src/utils/lib.c \
				src/utils/print_spaces.c \
				src/utils/print_zeros.c \
				src/utils/print_intmin.c \
				conversions/jotdown_char.c \
				conversions/jotdown_dec.c \
				conversions/jotdown_hexadec.c \
				conversions/jotdown_pointer.c \
				conversions/jotdown_string.c \
				conversions/jotdown_percent.c \
				conversions/jotdown_unsign.c

OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
