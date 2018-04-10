/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuhar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:17:17 by tkuhar            #+#    #+#             */
/*   Updated: 2018/04/10 22:53:03 by tkuhar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t n)
{
	void *temp;

	temp = b;
	while (n-- > 0)
	{
		*(unsigned char *)b = (unsigned char)c;
		b++;
	}
	return (temp);
}

int	get_next_line(const int fd, char **line)
{
	static char	buf[BUFF_SIZE];
	static int	i;
	int			size;

	size = 0;
	if (buf != '\0')
		if (!read(fd,buf,BUFF_SIZE))
			return (0);
	while (buf[size] != '\0' && buf[i] != '\n')
		size++;
	*line = malloc(sizeof(char) * size);
	line[size] = '\0';
	i = 0;
	while(i < size)
		line[i] = buf[i++];
	return (1);
}

int main(int argc, char **argv)
{
	char	*c;
	int		fd;

	fd = open(argv[1], O_RDONLY)

}