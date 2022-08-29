/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_text_in_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:53:59 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/28 19:10:51 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

char	*ft_memncpy(const char *src, char *dest, unsigned char size);
char	*ft_strcpy(const char *src, char *dest);

int	ft_count_lines(char *str)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			line++;
		i++;
	}
	return (line);
}

void	ft_initialize_lines_to_null(char **lines, int lines_count)
{
	int	i;

	i = 0;
	while (i < lines_count)
	{
		lines[i] = 0;
		i++;
	}
}

void	ft_free_all_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		lines[i] = 0;
		i++;
	}
	free(lines);
}

char	**ft_save_line(char **lines, int line, char *p, char *prev_p)
{
	unsigned int	line_size;

	line_size = p - prev_p;
	lines[line] = (char *)malloc(line_size);
	if (lines[line])
	{
		ft_memncpy(prev_p, lines[line], line_size);
		prev_p[line_size - 1] = 0;
		printf("-->%s<--\n", lines[line]);
	}
	else
	{
		ft_free_all_lines(lines);
		lines = 0;
	}
	return (lines);
}

char	**ft_split_str_in_lines(char *str, int *lines_count)
{
	char	**lines;
	int		line;
	char	*p;
	char	*prev_p;

	prev_p = str;
	line = 0;
	*lines_count = ft_count_lines(str);
	lines = (char **)malloc((sizeof (char *) * (*lines_count)));
	ft_initialize_lines_to_null(lines, *lines_count);
	p = str;
	while (*p && lines)
	{
		if (*p == '\n' && lines)
		{
			lines = ft_save_line(lines, line, p, prev_p);
			prev_p = p + 1;
			line++;
		}
		p++;
	}
	return (lines);
}
