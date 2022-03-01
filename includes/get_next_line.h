/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 05:04:20 by sanjeon           #+#    #+#             */
/*   Updated: 2022/03/01 15:09:06 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

# define BUFFER_SIZE 1

int		get_next_line(int fd, char **line);
int		find_new_line(int fd, char **line, char *buf, char **backup);
char	*add_buf(char *buf);
int		out_line(char *buf, char *nl, char **backup, char **line);

#endif
