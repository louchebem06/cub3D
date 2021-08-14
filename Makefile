# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 18:12:54 by bledda            #+#    #+#              #
#    Updated: 2021/08/14 23:33:45 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= cub3D

#	FILES			############################################################
HEADER_FILES 		= cub3d.h \
						ft_config.h \
						utils.h

FOLDER_HEADER		= header/
FOLDER_SRC			= src/
FOLDER_PARSING		= $(addprefix ${FOLDER_SRC},parsing/)
FOLDER_UTILS		= $(addprefix ${FOLDER_SRC},utils/)

SRCS_FILES			= main.c

SRCS_PARSING_FILES	= ft_config.c \
						ft_extension.c \
						get_file.c \
						get_values.c \
						get_values_utils.c \
						map_is_valid.c \
						remove_newlines.c \
						empty_line_in_map.c \
						forbiden_char_map.c \
						multi_pos_map.c \
						min_char_map.c \
						remove_end_space_map.c \
						remove_space_map.c \
						create_player_info.c \
						wall_check_map.c

SRCS_UTILS_FILES	= add_value.c \
						ft_strisdigit.c

SRCS				= $(addprefix ${FOLDER_SRC},${SRCS_FILES})
SRCS_PARSING		= $(addprefix ${FOLDER_PARSING},${SRCS_PARSING_FILES})
SRCS_UTILS			= $(addprefix ${FOLDER_UTILS},${SRCS_UTILS_FILES})
HEADERS				= $(addprefix ${FOLDER_HEADER},${HEADER_FILES})

SRCS_OBJS			= ${SRCS:.c=.o}
SRCS_PARSING_OBJS	= ${SRCS_PARSING:.c=.o}
SRCS_UTILS_OBJS		= ${SRCS_UTILS:.c=.o}

OBJS				= $(SRCS_OBJS) $(SRCS_PARSING_OBJS) $(SRCS_UTILS_OBJS)
####################################################################################

#	COMPILATION		################################################################
CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -rf
MAKE_EXT			= @make -s --no-print-directory -C
LIB					= -L ./libft -lft -L ./mlx_utils -lm

UNAME_S				= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LIBS 			= $(LIB) -lmlx -lXext -lX11
endif
ifeq ($(UNAME_S),Darwin)
	LIBS 			= $(LIB) -lmlx -framework OpenGL -framework AppKit -lz
endif
#####################################################################################

#	RULES	#########################################################################
$(NAME):	${OBJS}
			@printf $(magenta)
			@printf "\nStart build ⏳\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)
			$(MAKE_EXT) ./libft
			$(MAKE_EXT) ./mlx_utils
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Compiling cub3D🔨\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)
			@$(CC) $(CFLAGS) ${OBJS} $(LIBS) -o $(NAME)
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
			@${RM} ${OBJS}
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
