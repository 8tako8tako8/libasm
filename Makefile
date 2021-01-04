NAME = libasm.a
SRCFILE = ft_read.s\
	   ft_strcmp.s\
	   ft_strcpy.s\
	   ft_strdup.s\
	   ft_strlen.s\
	   ft_write.s
BONUSFILE = ft_atoi_base_bonus.s\
	   ft_list_push_front_bonus.s\
	   ft_list_size_bonus.s\
	   ft_list_sort_bonus.s\
	   ft_list_remove_if_bonus.s
SRCDIR = srcs/
SRCS = $(addprefix $(SRCDIR), $(SRCFILE))
BONUSES = $(addprefix $(SRCDIR), $(BONUSFILE))
HEADER = includes/libasm.h
BHEADER = includes/libasm_bonus.h
OBJS = $(SRCS:.s=.o)
BOBJS = $(BONUSES:.s=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror

%.o : %.s
	nasm -f macho64 $< -o $@
$(NAME) : $(OBJS)
	ar rcs $(NAME) $^
all	: $(NAME)
grademe : all
	$(CC) $(FLAGS) -L. -lasm -I./$(HEADER) $(NAME) main.c -o libasm -fsanitize=address -g
	./libasm
clean :
	rm -f $(OBJS) $(BOBJS)
fclean : clean
	rm -f $(NAME)
	rm -f libasm
re : fclean all
bonus : $(OBJS) $(BOBJS)
	ar rcs $(NAME) $^
grademee : bonus
	$(CC) $(FLAGS) -I./$(BHEADER) $(NAME) bonus.c -o libasm -fsanitize=address -g
	./libasm
.PHONY : all clean fclean re bonus grademe grademee
