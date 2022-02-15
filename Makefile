NAME = so_long

NAME_BONUS = so_long_bonus

CC = @cc -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror 

RM = @rm -f

B_FILES = ./map_utils/check_map_bonus.c \
			./utils/get_next_line.c \
			./utils/get_next_line_utils.c \
			./map_utils/map_print_bonus.c \
			./movements/movement_bonus.c \
			solong_bonus.c \
			./utils/ft_printf.c \
			./movements/move_utils_bonus.c \
			./utils/ft_itoa.c \
			./utils/utils_bonus.c \
			./enemy_utils/enemy_bonus.c \
			./enemy_utils/enemy_1_bonus.c \

C_FILES = ./map_utils/check_map.c \
			./utils/get_next_line.c \
			./utils/get_next_line_utils.c \
			./map_utils/map_print.c \
			./movements/movement.c \
			solong.c \
			./utils/ft_printf.c \
			./movements/move_utils.c \
			./utils/ft_itoa.c \

N_FLAG = -o

#  colors

C_PURPLE = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_RES = \033[0m

all : $(NAME)

$(NAME) : $(C_FILES) 
	@echo "$(C_GREEN)["so_long" CREATED]$(C_RES)"
	$(CC) $(FLAGS) $(C_FILES) $(N_FLAG) $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(B_FILES)
	@echo "$(C_L_BLUE)["so_long" BONUS CREATED]$(C_RES)"
	$(CC) $(FLAGS) $(B_FILES) $(N_FLAG) $(NAME_BONUS)

clean :
	@echo "$(C_PURPLE)["so_long" REMOVED]$(C_RES)"
	$(RM) $(NAME)

fclean :
	@echo "$(C_PURPLE)["so_long" REMOVED]$(C_RES)"
	$(RM) $(NAME)
	@echo "$(C_PURPLE)["so_long" BONUS REMOVED]$(C_RES)"
	$(RM) $(NAME_BONUS)

re : clean all