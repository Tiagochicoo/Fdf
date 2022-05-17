# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 10:19:16 by tpereira          #+#    #+#              #
#    Updated: 2022/05/17 21:15:05 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FDF 		= fdf
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -g
INC			= -Iincludes -Ilibft -I/opt/X11/include
LIB			= libft/libft.a
SRCS		= ./srcs/*.c
MAC			= -framework OpenGL -framework Appkit
LINUX		= -lXext -lX11
OS			= $(shell uname -s)

all :
	@make -s -C libft
ifeq ($(OS),Darwin)
	@make -s -C minilibx_opengl
	@$(CC) $(CFLAGS) $(SRCS) $(LIB) minilibx_opengl/libmlx.a $(MAC) -o $(FDF)
endif
ifeq ($(OS),Linux)
	@make -s -C minilibx_linux
	@$(CC) $(CFLAGS) $(SRCS) $(LIB) minilibx_linux/libmlx_Linux.a $(LINUX) -o $(FDF) 
endif
	@printf "\e[38;5;46m ╔════════════════════════════════════╗\e[0m\n"
	@printf "\e[38;5;46m█▓▒░	     Compiled Libft	    ░▒▓█ \e[0m\n"
	@printf "\e[38;5;46m█▓▒░   MinilibX build successful    ░▒▓█ \e[0m\n"
	@printf "\e[38;5;46m ╚════════════════════════════════════╝\e[0m\n"

cc: all
	./fdf 42.fdf

clean :
	@make -s clean -C libft
	@make -s clean -C minilibx_opengl
	@rm -rf ./srcs/*.o
	@printf "\e[31;5;200m ╔════════════════════════════════════╗\e[0m\n"
	@printf "\e[31;5;200m░▒▓█         Clean complete  	    █▓▒░\e[0m\n"
	@printf "\e[31;5;200m ╚════════════════════════════════════╝\e[0m\n"

fclean : clean
	@make -s fclean -C libft
	@make -s clean -C minilibx_opengl
	@rm -rf $(FDF)

re :	fclean all
bonus:	all

.PHONY: bonus re fclean clean all