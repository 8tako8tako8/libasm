NAME = libasm.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = srcs/
SRCFILE = ft_strlen.s \
			ft_strcpy.s \
	   		ft_strcmp.s \
			ft_write.s \
			ft_read.s\
			ft_strdup.s
SRCS = $(addprefix $(SRCDIR), $(SRCFILE))
INCLUDE = -I includes/libasm.h
OBJS = $(SRCS:.s=.o)
RM = rm -f

%.o : %.s
	nasm -f macho64 $< -o $@

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

all	: $(NAME)

grademe : all
	$(CC) $(CFLAGS) -L. -lasm $(INCLUDE) $(NAME) main.c -o libasm -fsanitize=address -g
	./libasm

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re