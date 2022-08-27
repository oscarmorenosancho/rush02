/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:43:31 by omoreno-          #+#    #+#             */
/*   Updated: 2022/08/27 18:16:55 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>


int		ft_get_filelength(char *filename)
{
	int filedesc;
	int read_ret;
	int filesize;
	char buf[81];
	int error;

	filesize = 0;
	filedesc = open(filename, O_RDONLY);
	error = (filedesc < 0);
	filesize = 0;
	read_ret = 80;
	while (read_ret == 80 && ! error)
	{
		read_ret = read (filedesc, buf, 80);
		error = (read_ret < 0);
		filesize += read_ret; 
	}
	close(filedesc);
	return (filesize);
}

char	*ft_read_dict(char *filename)
{
	int		filedesc;
	int		read_ret;
	int 	filesize;
	char	*buf;
	int 	error;

	filesize = ft_get_filelength(filename);
	error = filesize == 0;
	filedesc = open(filename, O_RDONLY);
	error = (error || (filedesc < 0));
	if (! error)
	{
		buf = (char *)malloc(filesize);
		read_ret = read (filedesc, buf, filesize);
		error = (error || read_ret < 0 || ! buf);
	}
	close(filedesc);
	if (error)
	{		
		write (1, "Dict Error\n", 11);
		if (buf)
			free(buf);
		return (0);
	}
	return (buf);
}
