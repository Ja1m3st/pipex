# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:24:10 by jaimesan          #+#    #+#              #
#    Updated: 2024/11/11 11:53:27 by jaimesan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
FLAGS = -Wall -Wextra -Werror -I ../includes
FLAGS_GNL = -Wall -Wextra -Werror -I ../../includes
FLAGS_PRINTF = -Wall -Wextra -Werror -I ../../includes

GREEN := \033[1;32m
RED := \033[1;31m
RESET := \033[0m

AR = ar rcs
RM	= rm -rf

FILES = ft_isdigit.c ft_isalnum.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strncmp.c \
		ft_atoi.c ft_strdup.c ft_substr.c ft_strjoin.c ft_itoa.c ft_split.c

GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c 

PRINTF = ./ft_printf/ft_printf.c ./ft_printf/ft_printf_hexa.c ./ft_printf/ft_printf_nbr.c \
		./ft_printf/ft_printf_ptr.c ./ft_printf/ft_printf_unsigned.c ./ft_printf/ft_printf_utils.c

OBJS		= $(FILES:.c=.o)
OBJS_GNL	= $(GNL:.c=.o)
OBJS_PRINTF	= $(PRINTF:.c=.o)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)
	$(AR) $(NAME) $(OBJS) $(OBJS_GNL) $(OBJS_PRINTF)
	@echo "[100%] $(GREEN)(Libft) Compilation | libft | ft_printf | get_next_line | successful!$(RESET)"

all: ${NAME} $(PRINTF_NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_GNL)
	$(RM) $(OBJS_PRINTF)
	@echo "[100%] $(RED)(Libft) Cleaning up exept compilers ..$(RESET)"

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJS_GNL)
	$(RM) $(OBJS_PRINTF)
	@echo "[100%] $(RED)(Libft) Cleaning up...$(RESET)"

re: fclean all

.PHONY:	all clean fclean re

.SILENT: