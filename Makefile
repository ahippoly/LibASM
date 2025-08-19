LIB_NAME = libasm.a

SRCS = 	ft_write.s ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_strlen.s ft_set_errno.s

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NASM = nasm

NASMFLAGS = -f elf64

OBJ = $(SRCS:.s=.o)

%.o : %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all : $(LIB_NAME)

$(LIB_NAME) : $(OBJ)
	ar rcs $(LIB_NAME) $(OBJ)

a.out: main.c $(LIB_NAME)
	$(CC) $(CFLAGS) main.c $(LIB_NAME) -o a.out

main: a.out
	
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIB_NAME)
	rm -f ./a.out

re : fclean all