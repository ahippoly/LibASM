#ifndef	LIBASM_H
# define LIBASM_H

# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>


ssize_t		ft_write(int, char *, size_t);
ssize_t		ft_read(int, char *, size_t);
size_t		ft_strlen(const char *);
char		  *ft_strcpy(char *, const char *);
int			  ft_strcmp(const char *, const char *);
char		  *ft_strdup(const char *);
void			ft_set_errno(int);


#endif