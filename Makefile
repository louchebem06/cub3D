# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 18:12:54 by bledda            #+#    #+#              #
#    Updated: 2021/08/12 19:04:22 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= cub3D

#	FILES			############################################################
HEADER_FILE 		= cub3d.h

FOLDER_HEADER		= header/
FOLDER_SRC			= src/

SRCS_FILES			= main.c

SRCS				= $(addprefix ${FOLDER_SRC},${SRCS_FILES})

SRCS_OBJS			= ${SRCS:.c=.o}
####################################################################################

#	COMPILATION		################################################################
CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -rf
MAKE_EXT			= @make -s --no-print-directory -C
LIB					= -L ./libft -L ./mlx_utils -lm

UNAME_S				= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LIBS 			= $(LIB) -lmlx -lXext -lX11
endif
ifeq ($(UNAME_S),Darwin)
	LIBS 			= $(LIB) -lmlx -framework OpenGL -framework AppKit -lz
endif
#####################################################################################

#	RULES	#########################################################################
$(NAME):	${SRCS_OBJS}
			@printf $(magenta)
			@printf "Start build ⏳\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)
			$(MAKE_EXT) ./libft
			$(MAKE_EXT) ./mlx_utils
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Compiling cub3D🔨\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)
			@$(CC) $(CFLAGS) ${SRCS_OBJS} $(LIBS) -o $(NAME)
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Your cub3D is ready ✅\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)

all:		${NAME}

%.o: %.c	$(HEADERS)
			@printf $(yellow)
			@printf "Generating cub3D objects... %-28.28s\r" $@
			@$(CC) -c $(CFLAGS) -o $@ $<
			@printf $(reset)

re: 		fclean all

clean:
			$(MAKE_EXT) ./libft clean
			$(MAKE_EXT) ./mlx_utils clean
			@${RM} ${SRCS_OBJ}
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Object files have been deleted 🚮\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)

fclean:		clean
			$(MAKE_EXT) ./libft fclean
			$(MAKE_EXT) ./mlx_utils fclean
			@${RM} $(NAME)
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Your folder is now clean 🧹\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)

.PHONY: 	all clean fclean re
#################################################################################

#	COLOR SETTING	#############################################################
black 				=	"[1;30m"
red 				=	"[1;31m"
green 				=	"[1;32m"
yellow 				=	"[1;33m"
blue 				=	"[1;34m"
magenta 			=	"[1;35m"
cyan 				=	"[1;36m"
white 				=	"[1;37m"

bg_black 			=	"[40m"
bg_red 				=	"[41m"
bg_green 			=	"[42m"
bg_yellow 			=	"[43m"
bg_blue 			=	"[44m"
bg_magenta 			=	"[45m"
bg_cyan 			=	"[46m"
bg_white 			=	"[47m"

reset 				=	"[0m"
#################################################################################