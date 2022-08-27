/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:58:34 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/27 13:37:05 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <fcntl.h>

unsigned int ft_strlen(char *str);

int main(int argc, char **argv)
{
	int		len;
	int		filedesc;
	char	buf[81];
	int		read_res;

	filedesc = open("numbers.dict", O_RDONLY);
	if (filedesc < 0)
		write(1, "error", 5);
	read_res = read(filedesc, buf, 80);
	if (read_res > 0)
		write(1, buf, read_res);
	else if (read_res < 0)
		write(1, "error read", 10);
	if (argc > 1)
	{
		len = ft_strlen(argv[1]);
		write(1, argv[1], len);
	}
	else
		write(1, "Faltan argumentos\n", 17);
	return (0);
}
