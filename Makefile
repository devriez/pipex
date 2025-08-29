CC = cc
NAME = pipex
FLAGS = -Wall -Werror -Wextra

SRC_DIR = ./src

#includes
INCLUDES = -I./includes

# Libft flags
LIBFT_DIR = ./libft
LIBFT_INCLUDES = -I$(LIBFT_DIR)
LIBFT_A = $(LIBFT_DIR)/libft.a


SRCS = $(SRC_DIR)/pipex.c $(SRC_DIR)/utils.c $(SRC_DIR)/error_and_free.c

all: $(NAME)

$(LIBFT_A):
		$(MAKE) -C $(LIBFT_DIR)

$(NAME):$(LIBFT_A)
		$(CC) $(SRCS) $(INCLUDES) \
		$(LIBFT_A) $(LIBFT_INCLUDES) \
		$(FLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C  $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

test:
	touch infile 
	./pipex infile "ls -l" "wc -l" outfile

