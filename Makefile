# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 20:47:21 by ekwak             #+#    #+#              #
#    Updated: 2023/02/12 20:35:23 by ekwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
RM = rm
RMFLAGS = -f
MAKE = make
SRCS =  ./libso_long/libso_long.a \
		./libft/libft.a \
		./gnl/libftgnl.a \
		./libprintf/libftprintf.a \
		./minilibx_opengl_20191021/libmlx.a \

all : $(NAME)

$(SRCS) :
		$(MAKE) -C ./libso_long all
		$(MAKE) -C ./libft all
		$(MAKE) -C ./gnl all
		$(MAKE) -C ./libprintf all
		$(MAKE) -C ./minilibx_opengl_20191021 all

MLX = -L minilibx_opengl_20191021 -lmlx -framework OpenGl -framework Appkit -lz

$(NAME) : $(SRCS)
		$(CC) $(CFLAGS) $(MLX) -o $(NAME) main.c $(SRCS)

clean :
		$(MAKE) -C ./libso_long clean
		$(MAKE) -C ./libft clean
		$(MAKE) -C ./gnl clean
		$(MAKE) -C ./libprintf clean
		$(MAKE) -C ./minilibx_opengl_20191021 clean

fclean : clean
		$(MAKE) -C ./libso_long fclean
		$(MAKE) -C ./libft fclean
		$(MAKE) -C ./gnl fclean
		$(MAKE) -C ./libprintf fclean
		$(RM) $(RMFLAGS) ./minilibx_opengl_20191021/libmlx.a
		$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all clean fclean re
