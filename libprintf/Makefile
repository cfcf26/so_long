# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/10 23:21:56 by ekwak             #+#    #+#              #
#    Updated: 2022/09/19 23:49:27 by ekwak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar
ARFLAGS = -crs
RM = rm
RMFLAGS = -f
SRCS =  ft_print_cs.c ft_print_piux.c \
		ft_itoa.c ft_itobase.c \
		libft.c \

OBJS = $(SRCS:.c=.o)

$(NAME)	: $(OBJS)
				$(CC) $(CFLAGS) -c $(SRCS) -I./
				$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all : $(NAME)

clean :
				$(RM) $(RMFLAGS) $(OBJS) $(BNS_OBJS)

fclean : clean
				$(RM) $(RMFLAGS) $(NAME)

re : fclean all

.PHONY : all clean fclean re
