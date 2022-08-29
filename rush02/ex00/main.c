/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:58:34 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/28 16:54:37 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "dict_item.h"

unsigned int 	ft_strlen(char *str);
char			*ft_read_dict(char *filename);
char    		**ft_split_str_in_lines(char *str, int *lines_count);
void			ft_free_all_lines(char **lines);
t_dict_item 	**ft_process_lines(char **lines, int lines_count);

void			ft_print_dict_item(t_dict_item *dict_item)
{
	int	key_size;
	int num_name_size;
	
	key_size = ft_strlen(dict_item->key);
	num_name_size = ft_strlen(dict_item->num_name);

	write(1, dict_item->key ,key_size);
	write(1, " : ", 3);
	write(1, dict_item->num_name, num_name_size);
	write(1, "\n", 1);
}

void			ft_print_dict_items(t_dict_item **dict_items, int item_count)
{
	int	i;

	i = 0;
	while (i < item_count)
	{
		if (dict_items[i])
			ft_print_dict_item(dict_items[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	int		len;
	char	*read;
	char	**lines;
	int		lines_count;
	t_dict_item **dict_items;

	if (argc > 1)
	{
		len = ft_strlen(argv[1]);
		write(1, argv[1], len);
	}
	else
		write(1, "Faltan argumentos\n", 18);
	read = ft_read_dict("numbers.dict");
	if (read)
	{
		lines = ft_split_str_in_lines(read, &lines_count);
		if (lines && lines_count > 0)
		{
			free(read);
			dict_items = ft_process_lines(lines, lines_count);
			if (dict_items)
				ft_print_dict_items(dict_items, lines_count);
			if (lines)
				ft_free_all_lines(lines);
		}
		else
		{
			write(1, "No line in file\n", 17);
		}
	}
	else
	{
		write(1, "Nothing read from file\n",21);
	}
	return (0);
}
