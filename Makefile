# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 11:54:42 by jaimesan          #+#    #+#              #
#    Updated: 2024/11/12 13:53:19 by jaimesan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus

CC = cc
CFLAGS =  -I ./includes
AR = ar rcs
RM	= rm -rf

GREEN := \033[1;32m
RED := \033[1;31m
RESET := \033[0m

SRCS = ./src/pipex.c ./src/pipex_utils.c
SRCS_BONUS = ./bonus/src/pipex.c ./bonus/src/pipex_utils.c

# Archivos objeto
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Directorio de la libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MAKEFLAGS = --no-print-directory

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS) $(LIBFT) 
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "[100%] $(GREEN)(Pipex) Compilation  | pipex | successful!$(RESET)"

bonus: $(OBJS_BONUS) $(LIBFT)
	$(CC) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@echo "[100%] $(GREEN)(Pipex_Bonus) Compilation  | pipex_bonus | successful!$(RESET)"

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	@echo "[100%] $(RED)(Pipex)(Pipex_Bonus) Cleaning up exept compilers ..$(RESET)"

fclean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(NAME)
	$(RM) $(OBJS_BONUS) $(NAME_BONUS)
	@echo "[100%] $(RED)(Pipex)(Pipex_Bonus) Cleaning up...$(RESET)"

re: fclean all bonus

.PHONY:	all clean fclean re bonus

.SILENT: