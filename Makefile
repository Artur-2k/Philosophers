# Binary
BIN = philo

# Compiler
CC = gcc
CFLAGS = -I$(INC_DIR) -Wall -Wextra -Werror -fsanitize=thread -g
#CFLAGS = -I$(INC_DIR) -Wall -Wextra -Werror -fsanitize=address -g

# Directories
INC_DIR = inc/
SRC_DIR = src/
OBJ_DIR = obj/

# Files
MAIN_FILE = $(SRC_DIR)main.c
SRC_FILES = clean_up.c dinner.c get_set.c initializations.c \
	monitoring.c mutex_handle.c parse_input.c syncro_tools.c \
	thread_handle.c time_functions.c utils.c write_functions.c \
	one_philo_case.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# Phony targets
.PHONY: all clean fclean re

# Rules
all: $(BIN)

$(BIN): $(MAIN_FILE) $(OBJ) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(MAIN_FILE) $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(BIN)

re: fclean all