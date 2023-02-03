//
// Created by Semih Gurbuz on 1/12/23.
//

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "stdio.h"
# include "fcntl.h"

size_t	ft_strlen(char *str);
int		find_nl(char *s1);
char	*new_buffer(char *buffer);
char	*copy(char *s1, char *s2);
char	*linex(int fd, char *buffer);
char	*get_next_line(int fd);

#endif