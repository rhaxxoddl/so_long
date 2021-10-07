/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:30:43 by sanjeon           #+#    #+#             */
/*   Updated: 2021/09/13 17:29:21 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     parsing(char **map_str)
{
    int row_length;
    int col_length;
    
    col_length = check_str_shape(map_str);
    while(map_str[row_length] != 0)
        row_length++;
    check_wall(map_str, row_length, col_length);
}

// If map is a rectangular shape return col_length.
int     check_str_shape(char **map_str)
{
    int col_length;
    int i;
    int j;

    col_length = 0;
    i = 0;
    while(map_str[i] != 0)
    {
        j = 0;
        while(map_str[i][j] != 0)
            j++;
        if (i == 0)
            col_length = j;
        else if (j != col_length)
            error();
        i++;
    }
    return (col_length);
}

// Check if the edge of the map is a wall.
void    check_wall(char **map_str, int row_length, int col_length)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(i != 0)
    {
        j = 0;
        while(j <= col_length)
        {
            if (i == 0 || i == row_length);
                if (map_str[i][j] != 1)
                    error();
            if ((j == 0 || j == col_length) && map_str[i][j] != 1)
                error();
            if (check_char(map_str[i][j]) == 0)
                error();
            j++;
        }
        i++;
    }
}

// If target belong to "01CEP", return 1. else return 0;
int         check_char(char target)
{
    char    rule_char[6];
    int     i;

    *rule_char = "01CEP";
    i = 0;
    while(rule_char[i] != 0)
    {
        if (target == rule_char[i])
            break;
        i++;
    }
    if (i == 6)
        return (0);
    else
        return (1);
}

void     error()
{
    write(1, "Error\n", 6);
    exit(1);
}