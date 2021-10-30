# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmehran <mmehran@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 18:12:54 by bledda            #+#    #+#              #
#    Updated: 2021/10/30 14:20:40 by mmehran          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						= cub3D

#	FILES			############################################################
HEADER_FILES_COMMUN 		= ft_config.h \
								utils.h \
								color.h \
								cub3d.h

HEADER_FILES_MANDA 			= cub.h \
								struct.h

HEADER_FILES_BONUS 			= minimap_bonus.h \
								mouse_bonus.h \
								shooter_bonus.h \
								sound_bonus.h \
								cub_bonus.h \
								struct_bonus.h \
								utils_bonus.h \
								sprite_bonus.h \
								ft_config_bonus.h \
								queue_bonus.h

FOLDER_HEADER				= header/
FOLDER_SRC					= src/
FOLDER_PARSING				= $(addprefix ${FOLDER_SRC},parsing/)
FOLDER_UTILS				= $(addprefix ${FOLDER_SRC},utils/)
FOLDER_CUB3D				= $(addprefix ${FOLDER_SRC},cub3D/)

#  COMMUN
SRCS_FILES_COMMUN			=

SRCS_PARSING_FILES_COMMUN	= ft_extension.c \
								get_file.c \
								get_values.c \
								get_values_utils.c \
								map_is_valid.c \
								remove_newlines.c \
								empty_line_in_map.c \
								multi_pos_map.c \
								remove_end_space_map.c \
								remove_space_map.c \
								normalize_map.c \
								add_space.c \
								size_map.c

SRCS_UTILS_FILES_COMMUN		= add_value.c \
								ft_strisdigit.c \
								free_split.c \
								count_char.c \
								ft_error.c \
								anti_rgb.c \
								is_valid_int.c \
								color_to_rgb.c

SRCS_CUB3D_FILES_COMMUN		= is_in_air.c \
								scale_pos.c \
								generate_img.c

#  MANDA
SRCS_FILES_MANDA			= main.c

SRCS_PARSING_FILES_MANDA	= forbiden_char_map.c \
								min_char_map.c \
								wall_check_map.c \
								create_player_info.c \
								ft_config.c

SRCS_UTILS_FILES_MANDA		= free_cub.c

SRCS_CUB3D_FILES_MANDA		= render_next_frame.c \
								hook.c \
								cub3d.c \
								ray_cast.c \
								draw.c \
								free_image.c

#  BONUS
SRCS_FILES_BONUS			= main_bonus.c

SRCS_PARSING_FILES_BONUS	= forbiden_char_map_bonus.c \
								min_char_map_bonus.c \
								wall_check_map_bonus.c \
								create_player_info_bonus.c \
								ft_config_bonus.c \
								replace_ground_bonus.c

SRCS_UTILS_FILES_BONUS		= ft_get_current_time_bonus.c \
								ismove_bonus.c \
								isrotate_bonus.c \
								free_cub_bonus.c \
								queue_bonus.c

SRCS_CUB3D_FILES_BONUS		= render_next_frame_bonus.c \
								minimap_bonus.c \
								move_mouse_bonus.c \
								hook_bonus.c \
								shooter_bonus.c \
								cub3d_bonus.c \
								sound_bonus.c \
								get_map_char_bonus.c \
								ray_cast_bonus.c \
								draw_bonus.c \
								generate_img_bonus.c \
								free_image_bonus.c \
								sprite_bonus.c \
								fps_bonus.c \
								minimap_utils_bonus.c \
								print_balle_bonus.c \
								generate_img_intro.c


SRCS_COMMUN					= $(addprefix ${FOLDER_SRC},${SRCS_FILES_COMMUN})
SRCS_PARSING_COMMUN			= $(addprefix ${FOLDER_PARSING},${SRCS_PARSING_FILES_COMMUN})
SRCS_UTILS_COMMUN			= $(addprefix ${FOLDER_UTILS},${SRCS_UTILS_FILES_COMMUN})
SRCS_CUB3D_COMMUN			= $(addprefix ${FOLDER_CUB3D},${SRCS_CUB3D_FILES_COMMUN})
HEADERS_COMMUN				= $(addprefix ${FOLDER_HEADER},${HEADER_FILES_COMMUN})

SRCS_MANDA					= $(addprefix ${FOLDER_SRC},${SRCS_FILES_MANDA})
SRCS_PARSING_MANDA			= $(addprefix ${FOLDER_PARSING},${SRCS_PARSING_FILES_MANDA})
SRCS_UTILS_MANDA			= $(addprefix ${FOLDER_UTILS},${SRCS_UTILS_FILES_MANDA})
SRCS_CUB3D_MANDA			= $(addprefix ${FOLDER_CUB3D},${SRCS_CUB3D_FILES_MANDA})
HEADERS_MANDA				= $(addprefix ${FOLDER_HEADER},${HEADER_FILES_MANDA})

SRCS_BONUS					= $(addprefix ${FOLDER_SRC},${SRCS_FILES_BONUS})
SRCS_PARSING_BONUS			= $(addprefix ${FOLDER_PARSING},${SRCS_PARSING_FILES_BONUS})
SRCS_UTILS_BONUS			= $(addprefix ${FOLDER_UTILS},${SRCS_UTILS_FILES_BONUS})
SRCS_CUB3D_BONUS			= $(addprefix ${FOLDER_CUB3D},${SRCS_CUB3D_FILES_BONUS})
HEADERS_BONUS				= $(addprefix ${FOLDER_HEADER},${HEADER_FILES_BONUS})

SRCS_OBJS_COMMUN			= ${SRCS_COMMUN:.c=.o}
SRCS_PARSING_OBJS_COMMUN	= ${SRCS_PARSING_COMMUN:.c=.o}
SRCS_UTILS_OBJS_COMMUN		= ${SRCS_UTILS_COMMUN:.c=.o}
SRCS_CUB3D_OBJS_COMMUN		= ${SRCS_CUB3D_COMMUN:.c=.o}

SRCS_OBJS_COMMUN_B			= ${SRCS_COMMUN:.c=_B.o}
SRCS_PARSING_OBJS_COMMUN_B	= ${SRCS_PARSING_COMMUN:.c=_B.o}
SRCS_UTILS_OBJS_COMMUN_B	= ${SRCS_UTILS_COMMUN:.c=_B.o}
SRCS_CUB3D_OBJS_COMMUN_B	= ${SRCS_CUB3D_COMMUN:.c=_B.o}

SRCS_OBJS_MANDA				= ${SRCS_MANDA:.c=.o}
SRCS_PARSING_OBJS_MANDA		= ${SRCS_PARSING_MANDA:.c=.o}
SRCS_UTILS_OBJS_MANDA		= ${SRCS_UTILS_MANDA:.c=.o}
SRCS_CUB3D_OBJS_MANDA		= ${SRCS_CUB3D_MANDA:.c=.o}

SRCS_OBJS_BONUS				= ${SRCS_BONUS:.c=.o}
SRCS_PARSING_OBJS_BONUS		= ${SRCS_PARSING_BONUS:.c=.o}
SRCS_UTILS_OBJS_BONUS		= ${SRCS_UTILS_BONUS:.c=.o}
SRCS_CUB3D_OBJS_BONUS		= ${SRCS_CUB3D_BONUS:.c=.o}

OBJS_COMMUN					= $(SRCS_OBJS_COMMUN) $(SRCS_PARSING_OBJS_COMMUN) $(SRCS_UTILS_OBJS_COMMUN) $(SRCS_CUB3D_OBJS_COMMUN)
OBJS_COMMUN_B				= $(SRCS_OBJS_COMMUN_B) $(SRCS_PARSING_OBJS_COMMUN_B) $(SRCS_UTILS_OBJS_COMMUN_B) $(SRCS_CUB3D_OBJS_COMMUN_B)
OBJS_MANDA					= $(SRCS_OBJS_MANDA) $(SRCS_PARSING_OBJS_MANDA) $(SRCS_UTILS_OBJS_MANDA) $(SRCS_CUB3D_OBJS_MANDA)
OBJS_BONUS					= $(SRCS_OBJS_BONUS) $(SRCS_PARSING_OBJS_BONUS) $(SRCS_UTILS_OBJS_BONUS) $(SRCS_CUB3D_OBJS_BONUS)
####################################################################################

#	COMPILATION		################################################################
CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror -O3
#CFLAGS  			= -Wall -Wextra -O3
RM					= rm -rf
MAKE_EXT			= @make -s --no-print-directory -C
REMAKE				= @make --no-print-directory
LIB					= ./libft/libft.a ./mlx_utils/mlx_utils.a -lm

UNAME_S				= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LIBS 			= $(LIB) -lmlx -lXext -lX11
endif
ifeq ($(UNAME_S),Darwin)
	LIBS 			= $(LIB) ./libmlx.dylib -framework OpenGL -framework AppKit
	MLX_MAC			= $(MAKE_EXT) ./mlx_mac && cp -r ./mlx_mac/libmlx.dylib ./
endif

ifdef CUB3D_BONUS
OBJS 				= $(OBJS_COMMUN_B) $(OBJS_BONUS)
HEADERS 			= $(HEADERS_COMMUN) $(HEADERS_BONUS)
ifeq ($(UNAME_S),Linux)
	EXEC_BASE24		= $(MAKE_EXT) ./base24-linux
	LIBS			+= ./base24-linux/x64/libbass.so
endif
ifeq ($(UNAME_S),Darwin)
	EXEC_BASE24		= $(MAKE_EXT) ./base24-osx intel && cp -r ./base24-osx/intel/libbass.dylib ./
	LIBS			+= libbass.dylib
endif
LIBS				+= -lpthread
MSG_BASE24			= @printf "libbase24 is created.\n"
DEFINE				= -D CUB_BONUS
else
OBJS 				= $(OBJS_COMMUN) $(OBJS_MANDA)
HEADERS 			= $(HEADERS_COMMUN) $(HEADERS_MANDA)
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
			@$(MLX_MAC)
			$(EXEC_BASE24)
			@printf $(yellow)
			$(MSG_BASE24)
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Compiling cub3D🔨\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)
			@$(CC) $(CFLAGS) ${OBJS} $(LIBS) $(DEFINE) -o $(NAME)
			@printf $(magenta)
			@printf "Your cub3D is ready ✅\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)

all:		${NAME}

%.o: %.c	$(HEADERS)
			@printf $(yellow)
			@printf "Generating cub3D objects... %-28.28s\r" $@
			@$(CC) -c $(CFLAGS) $(DEFINE) -o $@ $<
			@printf $(reset)

%_B.o: %.c	$(HEADERS)
			@printf $(yellow)
			@printf "Generating cub3D objects... %-28.28s\r" $@
			@$(CC) -c $(CFLAGS) $(DEFINE) -o $@ $<
			@printf $(reset)

re: 		fclean all

clean:
			$(MAKE_EXT) ./libft clean
			$(MAKE_EXT) ./mlx_utils clean
			$(MAKE_EXT) ./mlx_mac clean
			@${RM} ${OBJS_COMMUN} ${OBJS_COMMUN_B} ${OBJS_MANDA} ${OBJS_BONUS}
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Object files have been deleted 🚮\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)

fclean:		clean
			$(MAKE_EXT) ./libft fclean
			$(MAKE_EXT) ./mlx_utils fclean
			$(MAKE_EXT) ./base24-linux clean
			@${RM} $(NAME) base24-osx/intel libbass.dylib libbass.so libmlx.dylib
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(magenta)
			@printf "Your folder is now clean 🧹\n"
			@printf "➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n"
			@printf $(reset)

bonus:
			$(REMAKE) CUB3D_BONUS=1

.PHONY: 	all clean fclean re bonus
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
