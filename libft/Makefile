NAME = libft.a

SRC_DIR = src

SRC_FILES = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_atoi.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putnbr_unsigned_fd.c \
			ft_putnbr_base_fd.c \
			ft_calloc.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

INCLUDES = -Iinclude

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/libft.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re