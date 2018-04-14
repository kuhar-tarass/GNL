/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuhar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:17:17 by tkuhar            #+#    #+#             */
/*   Updated: 2018/04/14 20:50:29 by tkuhar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

// char	*remalloc(char **s1, char *s2)
// {
// 	char	*fresh;
// 	int		i;
// 	char	*tmp;

// 	tmp = s1
// 	if (!*s1)
// 		return ((char *)s2);
// 	if (!s2)
// 		return ((char *)(*s1));
// 	fresh = (char *)malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2) + 1));
// 	if (fresh == 0)
// 		return (0);
// 	i = 0;
// 	while ((*s1) && *(s1[0]) != '\0')
// 		fresh[i++] = *s1[0]++;
// 	//printf("@%c@\n",*(*(s1)));
// 	if (s2)
// 		while (s1[0] && *s2 != '\0')
// 			fresh[i++] = *s2++;
// 	fresh[i] = '\0';
// 	free(*s1);
// 	return (fresh);

// }





int	get_next_line(const int fd, char **line)
{
	static char	*mem = 0;
	char		*buf;
	int			i;
	char		*tmp;
	
	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_bzero(buf, BUFF_SIZE + 1);	
	while (1)
	{
		i = -1;
		while (mem && mem[++i])
			if(mem[i] == '\n')
			{
				*line = ft_strsub(mem, 0, i);
				tmp = ft_strjoin(0,&mem[i + 1]);
				free(mem);
				mem = tmp;
				free(buf);
				return (1);
			}
		if (read(fd,buf,BUFF_SIZE))
		{
			tmp = ft_strjoin(mem, buf);
			free(mem);
			mem = tmp;
			ft_bzero(buf, BUFF_SIZE + 1);
		}
		else
		{
			*line = ft_strsub(mem, 0, ft_strlen(mem));
			free(mem);
			free(buf);
			return (1);
		}
	}
}

int main(int argc, char **argv)
{
	char	*c;
	int		fd;
//	char	*s;

//	s = ft_strjoin("123", "1234567");
//	printf("%s\n", s);
//	s = remalloc(&s,"qwert");
	//printf("%s\n", s);
	if (argc != 3)
		return(0);
	fd = open(argv[1], O_RDONLY);
	int i = atoi(argv[2]); 
	while (i--)
	{
		get_next_line(fd, &c);
		printf("%s\n", c);
		free(c);
	}
	system("leaks a.out");
}