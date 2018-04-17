/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuhar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:17:17 by tkuhar            #+#    #+#             */
/*   Updated: 2018/04/17 20:05:06 by tkuhar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

/////////////////////////////
#include <stdio.h>
/////////////////////////////

void del(t_ls **ls, int fd)
{
	t_ls *tmp1;
	t_ls *tmp;

	tmp = *ls;
	while (tmp->next)
	{
		if(tmp->next->fd == fd)
		{
			tmp1 = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp1->data);
			free(tmp1);
		}
		tmp = tmp->next;
	}
}

t_ls *fnd(t_ls **ls, int fd)
{
	t_ls *new;
	t_ls *tmp;

	tmp = *ls;
	while (tmp)
	{
		if(tmp->fd == fd)
			return (tmp);
		if(tmp->next == 0)
			break ;
		tmp = tmp->next; 
	}
	new = malloc(sizeof(t_ls));
	if (*ls != 0)
		(tmp)->next = new;
	else
		*ls = new;
	new->fd = fd;
	new->data = 0;
	new->next = 0;	
	return (new);
}

void rewrite(char *s0, char **dest, char *s2)
{
	char		*tmp;

	tmp = ft_strjoin(s0, s2);
	if (*dest)
		free(*dest);
	*dest = tmp;
}

int	get_next_line(const int fd, char **line)
{
	static t_ls	*ls = 0;
	t_ls		*cur;
	char		*buf;

	if (fd < 0 || !line)
		return (-1);
	cur = fnd(&ls, fd);
	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	while (1)
	{
		ft_bzero(buf, BUFF_SIZE + 1);	
		if(cur->data && ft_strchr(cur->data,'\n'))
		{
			*line = ft_strsub(cur->data, 0, ft_strchr(cur->data,'\n') - cur->data);
			rewrite(0,&cur->data, ft_strchr(cur->data,'\n') + 1); 
			free(buf);
			return (1);
		}
		if (read(fd,buf,BUFF_SIZE) == 0)
		{
			*line = cur->data ? ft_strsub(cur->data,0,ft_strlen(cur->data)) : 0;
			free(buf);
			if (cur->data && !(cur->data = 0))
				return (1);
			return (0);
		}
		rewrite(cur->data, &cur->data, buf);
	}
}

int main(int argc, char **argv)
{
	char	*c;
	int		fd;
	int		fd2;
	int		fd3;
//	char	*s;

//	s = ft_strjoin("123", "1234567");
//	printf("%s\n", s);
//	s = remalloc(&s,"qwert");
	//printf("%s\n", s);
	//if (argc != 3)
	//	return(0);
	(void)argc ;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);
	// int i = atoi(argv[2]); 
	int i = -1;
	while (++i < 5)
	{
		printf("%i %s\n", get_next_line(fd, &c), c);
		printf("%i %s\n", get_next_line(fd2, &c), c);
		printf("%i %s\n", get_next_line(fd3, &c), c);
		// if (c)
		// 	free(c);
	}
	// system("leaks a.out");
}
/*
int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl7_1.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			if (count_lines == 0 && strcmp(line, "12345678") != 0)
				errors++;
			count_lines++;
			if (count_lines > 50)
				break ;
		}
		close(fd);
		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"12345678\" instead of \"%s\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}
*/