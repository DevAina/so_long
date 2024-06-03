NAME = so_long

CC = cc

FLAGS = -Wall -Werror -Wextra

FLAGS_MINILIBX = -L./minilibx-linux -lmlx -L/usr/lib -I/usr/include -Iminilibx-linux -lXext -lX11 -lm -lz

SRCS = ./srcs/init.c ./srcs/check_map.c ./srcs/check_map_utils.c \
		./srcs/check_map_utils_1.c ./srcs/get_map.c \
		./srcs/get_next_line.c ./srcs/get_next_line_utils.c \
		./srcs/move.c ./srcs/render_map.c ./srcs/so_long.c \
		./srcs/so_long_utils.c ./srcs/move_utils.c \

OBJS = ${SRCS:.c=.o}

.c.o:
	${CC} ${FLAGS} -I/usr/include -Iminilibx-linux -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	make -C ./ft_printf
	make -C ./minilibx-linux
	${CC} ${OBJS} ${FLAGS_MINILIBX} -L./ft_printf -lftprintf -o ${NAME}

clean:
	make clean -C ./ft_printf
	make clean -C ./minilibx-linux
	rm -f ${OBJS}

fclean: clean
	make fclean -C ./ft_printf
	rm -f {NAME}

re: fclean all

.PHONY: re clen fclean all
