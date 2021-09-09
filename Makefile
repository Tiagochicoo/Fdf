# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 10:19:16 by tpereira          #+#    #+#              #
#    Updated: 2021/09/09 18:58:06 by tpereira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FDF 		= fdf
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror

all :
	@make -s -C libft
	@gcc -g $(CFLAGS) ./srcs/*.c libft/libft.a -o $(FDF)
	@printf "\e[38;5;46m✅      Compiled Libft	    ✅ \e[0m\n"
	@printf "\e[38;5;46m✅   fdf build successfull  ✅ \e[0m\n"

clean :
	@make -s clean -C libft 
	@rm -rf ./srcs/*.o
	@printf "\e[31;5;200m🚮️ 	Clean complete      🚮️\e[0m\n"

fclean : clean
	@make -s fclean -C libft
	@rm -rf $(FDF)

re :	fclean all
bonus:	all

.PHONY: bonus re fclean clean all