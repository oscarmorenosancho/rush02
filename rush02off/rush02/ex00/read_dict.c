/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:43:31 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/27 15:04:40 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>


char	**read_dict(char *filename)
{
	int filedesc;
	int read_ret;
	char buf[81];
   
	filedesc = open(filename, O_RDONLY);
	if (filedesc < 0)
		write(1, "Dict Error\n", 10);
	read_ret = read (filedest, buf,80);
	if (
}
