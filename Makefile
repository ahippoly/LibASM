NAME = libasm

LIB_NAME = libasm.a

SRCS = 	ft_write.s ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_strlen.s ft_set_errno.s

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NASM = nasm

# Detect OS and set appropriate NASM format
UNAME_S := $(shell uname -s 2>/dev/null || echo "Windows")
ifeq ($(UNAME_S),Linux)
    NASMFLAGS = -f elf64
else ifeq ($(UNAME_S),Darwin)
    NASMFLAGS = -f macho64
else
    # Windows or unknown OS - assume Windows
    NASMFLAGS = -f win64
endif

OBJ = $(SRCS:.s=.o)

%.o : %.s
	$(NASM) $(NASMFLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(LIB_NAME) $(OBJ)

main : all
	$(CC) $(CFLAGS) main.c $(LIB_NAME)
	
clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIB_NAME)
	rm -f ./a.out

re : fclean all