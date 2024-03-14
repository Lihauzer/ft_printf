# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochurko <ochurko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 16:33:50 by ochurko           #+#    #+#              #
#    Updated: 2023/12/12 15:28:24 by ochurko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_printf.c ft_flag.c ft_convert_x.c ft_convert_u.c ft_convert_s.c \
				ft_convert_pro.c ft_convert_p.c ft_convert_d.c ft_convert_c.c ft_add_d.c

SRCSB	=	./bonus/ft_pointer_bonus.c

OBJS	= $(SRCS:.c=.o)

OBJSB	= $(SRCSB:.c=.o)

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra

NAME 	= 	libftprintf.a

NAMELIB	=	libft.a

DIRLIB =	./libft

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(OBJSB)
				$(MAKE) -C $(DIRLIB)
				cp libft/libft.a $(NAME)
				ar rc $(NAME) $(OBJS) $(OBJSB)
				
all:		$(NAME)

bonus:	$(NAME) $(OBJSB)
				ar rc $(NAME) $(OBJSB)

clean:	
			$(RM) $(OBJS) $(OBJSB)
			cd ./libft && $(MAKE) clean

fclean:		clean
			$(RM) $(NAMELIB) $(NAME)
			cd ./libft && $(MAKE) fclean

re:			fclean all

.PHONY: all clean fclean re bonus