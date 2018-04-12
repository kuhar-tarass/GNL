/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuhar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:17:17 by tkuhar            #+#    #+#             */
/*   Updated: 2018/04/12 17:21:30 by tkuhar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

t_list	*lstfree(t_list **l)
{
	t_list		*tmp;

	while (*l)
	{
		tmp = (*l)->next;
		free((void *)(*l)->content);
		free(*l);
		(*l) = tmp;
	}
	*l = 0;
	return (0);
}

int	datasize(t_list *l)
{
	int n;

	n = 0;
	while(l)
	{
		n += l->content_size;
		l = l->next;
	}
	return (n);
}

int	readlist(const int fd, char **line, int datasz, t_list *lst)
{
	int i;

	i = 0;
	if (!(*line = (char *)malloc(sizeof(char) * (datasz + 1))))
		return(0);
	while(lst)
	{
		ft_memcpy(&line[0][i], lst->content, lst->content_size);
		i += lst->content_size;
		lst = lst->next;
	}
	line[0][datasz] = '\0';
	return (1);
}

int f(t_list **l, char **line, int fd)
{
	int i;
	char *bf;

	while(l)
	{
		i = 0;
		while (i < (*l)->content_size)
			if (&((*l)->content)[i] == '\n')
			{
				if ( !l || !(readlist(fd, line, datasize(*l), *l)))
					return (-1);
				*l = lstfree(&l);
				bf =
				ft_lstpush_back(&ls, &buf[j + 1], rd - j - 1);
				printf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±	");
				free(buf);
				return (1);
			}
	}
	
}

int	get_next_line(const int fd, char **line)
{
	char			*buf;
	static t_list	*ls = 0;
	int 			j;
	int				rd;

	rd = 0;
	buf = malloc(sizeof(char) * BUFF_SIZE);
	while ((rd = read(fd,buf, BUFF_SIZE)))
	{
		j = -1;
		while (++j < rd)
			if (buf[j] == '\n')
			{
				ft_lstpush_back(&ls, buf, j);
				if ( !ls || !(readlist(fd, line, datasize(ls), ls)))
				return (-1);
				ls = lstfree(&ls);
				if 
				ft_lstpush_back(&ls, &buf[j + 1], rd - j - 1);
				printf("±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±	");
				free(buf);
				return (1);
			}
		ft_lstpush_back(&ls, buf, rd);
	}
	free(buf);
	return (0);
}



int main(int argc, char **argv)
{
	char	*c;
	int		fd;

	if (argc != 2)
		return(0);
	fd = open(argv[1], O_RDONLY);
	for (int i= 3; i > 0; i--)
	{
		get_next_line(fd, &c);
		printf("%s\n", c);
	}
	//system("leaks a.out");
}