NAME = ft_ls
SRCS = 	main \
		ft_file \
		ft_file2 \
		ft_read_folder \
		ft_display \
		ft_order \
		ft_order_asc \
		ft_order_desc \
		ft_tools \
		ft_options \
		ft_errors
SRCS_PATH = ./srcs
INCLUDES_PATH = ./includes/ \
		./libft/includes/
LIBDIR = ./libft/
LIB = -L$(LIBDIR) -lft
SRCS_FILES = $(patsubst %, $(SRCS_PATH)/%.c, $(SRCS))
OBJECT_FILES = $(patsubst %, %.o, $(SRCS))
#CFLAGS = -Wall -Werror -Wall
CC = gcc -m32

all: libft_all ${NAME}

libft_all:
	@make -C $(LIBDIR) all

libft_make:
	@make -C $(LIBDIR)

libft_clean:
	make -C $(LIBDIR) clean

libft_fclean:
	make -C $(LIBDIR) fclean

libft_re: libft_fclean
	make -C $(LIBDIR) re

${NAME}: libft_make
	@echo Compilation ft_ls
	@$(CC) -c $(CFLAGS) $(patsubst %, -I%, $(INCLUDES_PATH)) $(SRCS_FILES) $(LIB)
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJECT_FILES) $(LIB)

clean: libft_clean
	@rm -rf *.o

fclean: clean libft_fclean
	@rm -rf $(NAME)

re: libft_re fclean all
