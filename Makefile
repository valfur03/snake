# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 09:59:30 by vfurmane          #+#    #+#              #
#    Updated: 2021/07/02 12:17:17 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= snake
MLXDIR		= minilibx-linux
MLXFILE		= $(MLXDIR)/libmlx_Linux.a
SRCS		= $(addprefix srcs/, init.c main.c mlx_events.c my_mlx.c)
OBJS		= $(SRCS:.c=.o)
INCL		= $(addprefix -I , includes $(MLXDIR))
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
LIBS		= -Lminilibx-linux -lmlx_Linux -lX11 -lXext
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(INCL) -o $@

all:		$(MLXFILE) $(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $^ $(LIBS) -o $(NAME)

$(MLXFILE):
			git submodule init
			git submodule update
			make -C $(MLXDIR)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all nosanitize clean fclean re
