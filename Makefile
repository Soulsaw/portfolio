CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs)

# Directories
SRC_DIR = src
OBJ = obj
EXCEC = prog
RM = rm -f
# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ)/%.o,$(SRC_FILES))

all:$(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $(EXCEC) $(LDFLAGS) -lm
$(OBJ)/%.o:$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $< -lm

clean:
	$(RM) *~ $(EXCEC) && clear
oclean:
	$(RM) $(OBJ_FILES) && clear
fclean: clean oclean
re: clean oclean all