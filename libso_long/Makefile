# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 12:14:51 by ekwak             #+#    #+#              #
#    Updated: 2023/01/09 18:38:07 by ekwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
DFLAGS = -g3 -fsanitize=address
NAME = libso_long.a
AR = ar
ARFLAGS = -crs
RM = rm
RMFLAGS = -f
SRCS =  dfs.c \
		display.c \
		ft_error.c \
		ft_strjoin_so_long.c \
		init_map.c \
		init_mlx.c \
		is_valid_file_extension.c \
		key.c \
		read_map_into_array.c \
		so_long.c \
		validate_map.c \

OBJS = $(SRCS:.c=.o)

$(NAME)	:
				$(CC) $(CFLAGS) -c $(SRCS) -I./
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean :
				$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
				$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all clean fclean re