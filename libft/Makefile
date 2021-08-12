# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bledda <bledda@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/05 05:34:19 by bledda            #+#    #+#              #
#    Updated: 2021/08/11 14:39:16 by bledda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libft.a

#	FILES	####################################################################
SRC_FOLDER			= src/
HEADER_FOLDER		= header/

HEADER_FILES		= libft.h

SRCS_FILES			= mlx_put_img_to_img.c

SRCS_FILES			= ft_memset.c \
						ft_bzero.c \
						ft_memcpy.c \
						ft_memccpy.c \
						ft_atoi.c \
						ft_strlen.c \
						ft_isdigit.c \
						ft_isalpha.c \
						ft_isalnum.c \
						ft_isascii.c \
						ft_isprint.c \
						ft_memchr.c \
						ft_memcmp.c \
						ft_memmove.c \
						ft_strchr.c \
						ft_strrchr.c \
						ft_strlcpy.c \
						ft_strlcat.c \
						ft_calloc.c \
						ft_strdup.c \
						ft_strncmp.c \
						ft_strnstr.c \
						ft_tolower.c \
						ft_toupper.c \
						ft_split.c \
						ft_strjoin.c \
						ft_itoa.c \
						ft_substr.c \
						ft_putchar_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c \
						ft_putstr_fd.c \
						ft_strmapi.c \
						ft_strtrim.c \
						ft_isset_tab.c \
						ft_isset.c \
						ft_iswhitespace.c \
						get_next_line.c \
						ft_printf_lite.c

SRCS_BONUS_FILES	= ft_lstnew.c \
						ft_lstadd_front.c \
						ft_lstsize.c \
						ft_lstlast.c \
						ft_lstadd_back.c \
						ft_lstdelone.c \
						ft_lstclear.c \
						ft_lstiter.c \
						ft_lstmap.c

SRCS				= $(addprefix ${SRC_FOLDER},${SRCS_FILES})
SRCS_BONUS			= $(addprefix ${SRC_FOLDER},${SRCS_BONUS_FILES})
HEADERS				= $(addprefix ${HEADER_FOLDER},${HEADER_FILES})

OBJS				= ${SRCS:.c=.o}
OBJS_BONUS			= ${SRCS_BONUS:.c=.o}

CC					= gcc
CFLAGS  			= -Wall -Wextra -Werror
RM					= rm -f
AR					= ar -rcs

ifdef BONUS_LIBFT
OBJS_LIBFT			= $(OBJS) $(OBJS_BONUS)
else
OBJS_LIBFT			= $(OBJS)
endif
################################################################################

#	RULES	####################################################################
$(NAME):	${OBJS_LIBFT}
			@${AR} ${NAME} ${OBJS_LIBFT}
			@printf $(yellow)
			@printf "\n$(NAME) done.\n"
			@printf $(reset)

all:		${NAME}

%.o: %.c	$(HEADERS)
			@printf $(yellow)
			@printf "Generating libft objects... %-28.28s\r" $@
			@$(CC) -c $(CFLAGS) -o $@ $<
			@printf $(reset)

bonus: 		
			@$(MAKE) BONUS_LIBFT=1

clean:
			@${RM} $(OBJS) $(OBJS_BONUS)
			@printf $(yellow)
			@printf "Objects for $(NAME) is delete\n"
			@printf $(reset)

fclean:		clean
			@$(RM) $(NAME)
			@printf $(yellow)
			@printf "$(NAME) is delete\n"
			@printf $(reset)

re:			fclean all

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
