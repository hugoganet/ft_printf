# Name of the final library we are building
NAME = libftprintf.a

# Path to the libft directory
LIBFT_DIR = libft
# Name of the libft static library
LIBFT = $(LIBFT_DIR)/libft.a

# Directory containing ft_printf source files
SRC_DIR = src
# List of source files for ft_printf
SRC_FILES = ft_printf.c process_args.c

# Full paths to the source files
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# Directory where object files (.o) will be stored
OBJ_DIR = obj
# Full paths to object files, replacing .c with .o
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Include directories for header files
# - -I flag tells the compiler where to look for header files
# - `includes` contains ft_printf-specific headers
# - `$(LIBFT_DIR)` is for libft headers
INCLUDES = -Iinclude -I$(LIBFT_DIR)/include

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Default rule: Build the final library
all: $(NAME)

# Rule to build the libft library by invoking its Makefile
$(LIBFT):
	@echo "Building libft..."
	$(MAKE) -C $(LIBFT_DIR)

# Rule to compile source files into object files
# - $< is the first dependency (the source file)
# - $@ is the target (object file)
# - @mkdir -p $(OBJ_DIR)  (Ensure the object directory exists)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/ft_printf.h libft/include/libft.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to create the final ft_printf library
# This rule creates the `libftprintf.a` library by combining:
# 1. Object files specific to ft_printf (`$(OBJS)`).
# 2. Object files extracted from the precompiled `libft.a`.
$(NAME): $(OBJS) $(LIBFT)
# Step 1: Extract all object files from the libft.a static library.
# - `ar` is a tool to create, modify, and extract object files from static libraries.
# - `x` extracts all the `.o` object files from `$(LIBFT)` into the current directory.
	ar x $(LIBFT)
# Step 2: Create the libftprintf.a library.
# - `ar` is again used here, but this time to create or update a static library.
# - `r` means "replace" existing files in the archive, or add new ones if they don't exist.
# - `c` means "create" the library if it doesn’t already exist.
# - `s` means "write an index" (symbol table) to the library for faster linking.
# This combines:
# - The object files for ft_printf (`$(OBJS)`).
# - The extracted libft object files (`*.o`).
	ar rcs $(NAME) $(OBJS) *.o
# Step 3: Clean up the extracted object files.
	rm -f *.o
	@echo "$(NAME) created successfully."

# Clean rule: Remove object files from ft_printf and libft
clean:
	@echo "Cleaning up object files..."
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

# Full clean rule: Remove all compiled files, including the library
fclean: clean
	@echo "Removing $(NAME)..."
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Rule to rebuild the entire project from scratch
re: fclean all

# Phony targets: These are not actual files and should not conflict with file names
.PHONY: all clean fclean re
