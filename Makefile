# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmakynen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/06 17:17:29 by lmakynen          #+#    #+#              #
#    Updated: 2020/09/06 19:54:34 by lmakynen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INCLUDES = libft/ -I /usr/local/include -L libft/ -lft -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit 

SOURCE = main.c create_map.c create_window.c draw_map.c

OFILES = $(subst .c,.o,$(SOURCE))

FLAGS = -Wall -Werror -Wextra

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@ make -C libft/ fclean && make -C libft/
	@ make -C libft/ clean
	@ gcc $(FLAGS) -c $(SOURCE)
	@ gcc -o $(NAME) $(OFILES) -I $(INCLUDES)

clean:
	@ rm -f $(OFILES)
	@ make -s clean -C ./libft

fclean: clean
	@ rm -f $(NAME)
	@ make -s fclean -C ./libft

re: fclean all

new: re
	@ rm -f $(OFILES)
