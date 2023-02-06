/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 00:53:26 by segurbuz          #+#    #+#             */
/*   Updated: 2023/02/07 00:53:27 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

size_t	strlen_plus(char *buff, int rule);
int		find_nl(char *s1);
char	*get_new_buffer(char *buffer);
char	*copy(char *s1, char *s2);
char	*linex(int fd, char *buffer);
char	*get_next_line(int fd);
char	*get_new_line(char *buffer);
char	*copy_next(char *dst, char *src);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 31
# endif
#endif
