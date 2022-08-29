/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 09:00:45 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/28 18:41:57 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "dict_item.h"

char			*ft_find_char(char *str, char c);
char			*ft_memncpy(const char *src, char *dest, unsigned char size);
unsigned int	ft_strlen(char *str);
char			*ft_strcpy(char *dest, char *src);

void	ft_free_dict_items(t_dict_item **dict_items, int items_count)
{
	int	i;

	i = 0;
	while (dict_items && i < items_count)
	{
		if (dict_items[i])
			free(dict_items[i]);
		i++;
	}
	if (dict_items)
		free (dict_items);
}

void	ft_split_fields(char *line, char **key, char **num_name)
{
	char	*colon;
	int		i;
	int		len;

	len = ft_strlen(line);
				printf("en ft_split_fields\n");
				printf("line %s & len %d\n", line, len);
				printf("------------------\n");
	*key = line;
	while (**key <= ' ')
		(*key)++;
	i = 0;
	while (*(*key + i) >= '0' && *(*key + i) <= '9')
		i++;
	*(*key + i) = 0;
	colon = ft_find_char(line, ':');
	*colon = 0;
	*num_name = colon + 1;
	while (**num_name <= ' ')
		(*num_name)++;
	i = len;
	while (line[i] <= ' ')
		--i;
	line[i + 1] = 0;
}

t_dict_item	*ft_extract_dict_item(char *str)
{
	t_dict_item	*dict_item;
	int			key_size;
	int			num_name_size;
	char		*key_p;
	char		*num_name_p;

				printf("En ft_extract_di, linea: %s\n--\n", str);
	key_p = str;
	num_name_p = str;
	dict_item = (t_dict_item *) malloc(sizeof (t_dict_item));
	ft_split_fields(str, &key_p, &num_name_p);
					printf("partido:  %s -  %s\n", key_p, num_name_p);
	key_size = ft_strlen(key_p);
	num_name_size = ft_strlen(num_name_p);
	dict_item->key = (char *) malloc(key_size + 1);
	ft_strcpy(key_p, dict_item->key);
	dict_item->num_name = (char *) malloc(num_name_size + 1);
	ft_strcpy(num_name_p, dict_item->num_name);
	return (dict_item);
}

char	*ft_find_char(char *str, char to_find)
{
	char	*p;

	p = str;
	while (*p != to_find)
		p++;
	return (p);
}

t_dict_item	**ft_process_lines(char **lines, int lines_count)
{
	int			line;
	t_dict_item	**dict_items;

	dict_items = (t_dict_item **)malloc(lines_count * sizeof(t_dict_item *));
	line = 0;
	while (line < lines_count || dict_items)
	{
		if (lines[line])
		{
			dict_items[line] = ft_extract_dict_item(lines[line]);
			free(lines[line]);
			lines[line] = 0;
		}
		line++;
		printf("Despu'es de contar linea %d con %d\n", line, lines_count);
	}
	printf("Antes de liberar en ft_proces\n");
	ft_free_dict_items(dict_items, lines_count);
	return (dict_items);
}
