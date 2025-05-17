# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carloga2 <carloga2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 16:33:12 by carloga2          #+#    #+#              #
#    Updated: 2025/05/17 21:21:40 by carloga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

# Source files
SRCS = ft_printf.c \
	   ft_format_char.c \
	   ft_format_string.c \
	   ft_format_pointer.c \
	   ft_format_integer.c \
	   ft_format_unsigned.c \
	   ft_format_hex_lower.c \
	   ft_format_hex_upper.c \
	   ft_format_percent.c \
	   ft_put_char.c \
		

# Object files
OBJS = $(SRCS:.c=.o)

# Header files
HEADER = ft_printf.h

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