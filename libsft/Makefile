# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hotph <hotph@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/29 16:31:02 by hotph             #+#    #+#              #
#    Updated: 2023/10/17 09:49:04 by hotph            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus ex clean fclean re

NAME	=	libsft.a
CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	+=	-I./includes

SRCS	=	ft_memchr.c	ft_strcpy.c ft_strtrim.c ft_memcmp.c ft_strdup.c\
			ft_memcpy.c ft_atoi.c ft_substr.c ft_bzero.c ft_strjoin.c\
			ft_tolower.c ft_calloc.c ft_memset.c ft_strlcat.c ft_toupper.c ft_isalnum.c\
			ft_strlcpy.c ft_isalpha.c ft_strlen.c\
			ft_strmapi.c ft_isascii.c ft_strncmp.c ft_isdigit.c\
			ft_split.c ft_strnstr.c ft_isprint.c ft_strcat.c ft_strrchr.c ft_strchr.c\
			ft_strstr.c\

EXSRCS	=	add_string_to_array.c\
			almost_equal.c\
			count_row_of_matrix.c\
			create_trgb_color.c\
			ends_with_str.c\
			free_map_null_terminated.c free_map.c free_null.c\
			ft_gnl.c\
			get_distance.c get_radian.c\
			is_space3.c\
			is_string_composedof.c\
			is_valid_matrix.c is_valid_string.c\
			is_which_direction.c\
			power_num.c\
			putstr_reverse_fd.c\
			split_multichar.c\

SRCS_DIR	=	./srcs/
OBJS_DIR	= 	./objs/

ifdef WITH_EX
	SRCS += ${EXSRCS}
endif

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS:%.c=%.o}}

all:	${OBJS_DIR} $(NAME)

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME):	$(OBJS)
	ar rcs $@ $^

ex:
	${MAKE} WITH_EX=1 all

clean:
	find $(OBJS_DIR) -name "*.o" -type f -exec rm {} +

fclean:	clean
	rm -f $(NAME)
	rmdir ${OBJS_DIR} 2>/dev/null || true

re: fclean all