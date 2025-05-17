# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 16:33:12 by carloga2          #+#    #+#              #
#    Updated: 2025/05/17 18:25:34 by carloga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Source files
SRCS = ft_printf.c

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADER = printf.h

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

# Compile source files
%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@$(RM) $(OBJS)

# Clean object files and library
fclean: clean
	@$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Non-file targets
.PHONY: all clean fclean re test