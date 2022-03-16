# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 19:00:57 by ryesenia          #+#    #+#              #
#    Updated: 2022/03/16 20:15:11 by ryesenia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c  ft_split.c \
			chekers_liba.c c_p_e_process.c \

HEAD		=		pipex.h

OBJC    	=       ${SRCS:.c=.o}

OBJCB    	=		${SRCS_bonus:.c=.o}

NAME		=       pipex

CC      	=       gcc

FLAGS		=		-Wall -Wextra -Werror

RM			=       rm -rf

%.o:%.c 		$(HEAD)
				$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all:            $(NAME)

$(NAME):        $(OBJC)
				$(CC) $(OBJC)  -o $(NAME)

bonus:			$(NAMEB)

$(NAMEB):		$(OBJCB)
				gcc -c $(SRCS_bonus)
				$(CC) $(OBJCB) -o $(NAMEB)

clean:
				${RM} ${OBJC} ${OBJCB}

fclean:			clean
				${RM} ${NAME} ${NAMEB}

re:				fclean	all

.PHONY:			all clean fclean re bonus
