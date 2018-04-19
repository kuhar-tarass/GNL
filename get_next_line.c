/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuhar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:17:17 by tkuhar            #+#    #+#             */
/*   Updated: 2018/04/19 12:17:14 by tkuhar           ###   ########.fr       */
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
			free(tmp1->dt);
			free(tmp1);
		}
		tmp = tmp->next;
	}
}

static t_ls *fnd(t_ls **ls, int fd)
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
	new->dt = 0;
	new->next = 0;	
	return (new);
}

static void rewrite(char **dest, char *s0, char *s2)
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
	t_ls		*f;
	char		*buf;
	int			ret;
	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	f = fnd(&ls, fd);
	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	while(1)
	{
		if (f->dt && ft_strchr(f->dt, '\n'))
		{
			*line = ft_strsub(f->dt,0,ft_strchr(f->dt, '\n') - f->dt);
			rewrite(&f->dt, 0, ft_strchr(f->dt, '\n') + 1);
			ret = 1;
			break ;
		}
		ft_memset(buf, 0, BUFF_SIZE + 1);
		read(fd, buf, BUFF_SIZE);
			if (!(*buf))
		{
			if (f->dt)
			{
				*line = ft_strdup(f->dt);
				del(&ls, fd);
				ret = 1;
				break ;
			}
			ret = 0;
			break ;
		}
		rewrite(&f->dt, f->dt, buf);
	}
	free(buf);
	return (ret);
	/*while (1)
	{
		if(f->dt && ft_strchr(f->dt,*buf ? '\n' : '\0'))
		{
			*line = ft_strsub(f->dt, 0, ft_strchr(f->dt, *buf ? '\n' : '\0') - f->dt);
			rewrite(0,&f->dt, ft_strchr(f->dt,*buf ? '\n' : '\0') + 1); 
			free(buf);
			return (1);
		}
		ft_memset(buf, 0, BUFF_SIZE + 1);
		read(fd,buf,BUFF_SIZE);
		if (!(*buf) && !f->dt)
		{
			free(buf);
			return (0);
		}
		rewrite(f->dt, &f->dt, buf);
	}*/
}
/*
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
	(void)argc;
	(void)argv;
	fd = open("123", O_RDONLY);
	fd2 = open("author", O_RDONLY);
	fd3 = open("12", O_RDONLY);
	// int i = atoi(argv[2]); 
	int i = -1;
	while (++i < 3)
	{
		//printf("%i %s\n", get_next_line(fd, &c), c);
		//printf("%i %s\n", get_next_line(fd2, &c), c);
		printf("%i %s\n", get_next_line(fd3, &c), c);
			free(c);
	}
	system("leaks a.out");
}*/
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
		printf("An error ocfed while opening file %s\n", filename);
	return (0);
}
*/
/*
int				main(void)
{
	char		*line1;
	char		*line2;
	char		*line3;
	int			fd1;
	int			fd2;
	int			fd3;
	int			ret1;
	int			ret2;
	int			ret3;
	char		*filename1;
	char		*filename2;
	int			errors;

	filename1 = "gnl11_1.txt";
	filename2 = "gnl11_2.txt";
	fd1 = open(filename1, O_RDONLY);
	fd2 = open(filename2, O_RDONLY);
	fd3 = -1;
	if (fd1 > 2 && fd2 > 2)
	{
		errors = 0;
		line1 = NULL;
		line2 = NULL;
		line3 = NULL;

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "The getdelim() function reads a line from stream, delimited by the character") != 0)
		{
			printf("-> must have returned '1' and read line #1 \"The getdelim() function reads a line from stream, delimited by the character\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "delimiter.  The getline() function is equivalent to getdelim() with the new-") != 0)
		{
			printf("-> must have returned '1' and read line #2 \"delimiter.  The getline() function is equivalent to getdelim() with the new-\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "line character as the delimiter.  The delimiter character is included as") != 0)
		{
			printf("-> must have returned '1' and read line #3 \"line character as the delimiter.  The delimiter character is included as\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "part of the line, unless the end of the file is reached.") != 0)
		{
			printf("-> must have returned '1' and read line #4 \"part of the line, unless the end of the file is reached.\" from file %s\n", filename1);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "The Festival de Radio France et Montpellier is a summer festival of opera and other music held in Montpellier.") != 0)
		{
			printf("-> must have returned '1' and read line #1 \"The Festival de Radio France et Montpellier is a summer festival of opera and other music held in Montpellier.\" from file %s\n", filename2);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "The festival concentrates on classical music and jazz with about 150 events, including opera, concerts, films, and talks. ") != 0)
		{
			printf("-> must have returned '1' and read line #2 \"The festival concentrates on classical music and jazz with about 150 events, including opera, concerts, films, and talks. \" from file %s\n", filename2);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "Most of these events are free and are held in the historic courtyards of the city or in the modern concert halls of Le Corum. ") != 0)
		{
			printf("-> must have returned '1' and read line #3 \"Most of these events are free and are held in the historic courtyards of the city or in the modern concert halls of Le Corum. \" from file %s\n", filename2);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "Le Corum cultural and conference centre contains 3 auditoriums. ") != 0)
		{
			printf("-> must have returned '1' and read line #4 \"Le Corum cultural and conference centre contains 3 auditoriums. \" from file %s\n", filename2);
			errors++;
		}

		ret3 = get_next_line(fd3, &line3);
		if (ret3 != -1)
		{
			printf("-> must have returned '-1' with invalid file descriptor\n");
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "") != 0)
		{
			printf("-> must have returned '1' and read line #5 \"\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "The caller may provide a pointer to a malloced buffer for the line in") != 0)
		{
			printf("-> must have returned '1' and read line #6 \"The caller may provide a pointer to a malloced buffer for the line in\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "*linep, and the capacity of that buffer in *linecapp.  These functions") != 0)
		{
			printf("-> must have returned '1' and read line #7 \"*linep, and the capacity of that buffer in *linecapp.  These functions\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "expand the buffer as needed, as if via realloc().  If linep points to a NULL") != 0)
		{
			printf("-> must have returned '1' and read line #8 \"expand the buffer as needed, as if via realloc().  If linep points to a NULL\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "pointer, a new buffer will be allocated.  In either case, *linep and") != 0)
		{
			printf("-> must have returned '1' and read line #9 \"pointer, a new buffer will be allocated.  In either case, *linep and\" from file %s\n", filename1);
			errors++;
		}

		ret1 = get_next_line(fd1, &line1);
		if (ret1 != 1 || strcmp(line1, "*linecapp will be up-dated accordingly.") != 0)
		{
			printf("-> must have returned '1' and read line #10 \"*linecapp will be up-dated accordingly.\" from file %s\n", filename1);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "The city is a center for cultural events since there are many students. ") != 0)
		{
			printf("-> must have returned '1' and read line #5 \"The city is a center for cultural events since there are many students. \" from file %s\n", filename2);
			errors++;
		}

		ret2 = get_next_line(fd2, &line2);
		if (ret2 != 1 || strcmp(line2, "Montpellier has two large concerts venues: Le Zenith Sud (7.000 seats) and L'Arena (14.000 seats).") != 0)
		{
			printf("-> must have returned '1' and read line #6 \"Montpellier has two large concerts venues: Le Zenith Sud (7.000 seats) and L'Arena (14.000 seats).\" from file %s\n", filename1);
			errors++;
		}

		// ret1 = get_next_line(fd1, &line1);
		// if (ret1 != 0)
		// {
		// 	printf("-> must have returned '0' at the end of file %s\n", filename1);
		// 	errors++;
		// }

		// ret2 = get_next_line(fd2, &line2);
		// if (ret2 != 0)
		// {
		// 	printf("-> must have returned '0' at the end of file %s\n", filename2);
		// 	errors++;
		// }

		close(fd1);
		close(fd2);
		if (errors == 0)
			printf("OK\n");
	}
	else
		printf("An error ocfed while opening files %s and/or %s\n", filename1, filename2);
	return (0);
}
*/