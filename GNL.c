/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuhar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:17:17 by tkuhar            #+#    #+#             */
/*   Updated: 2018/04/14 20:13:30 by tkuhar           ###   ########.fr       */
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
	int 		ss;
	
	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_bzero(buf, BUFF_SIZE + 1);	
	ss = 5;
	while (ss--)
	{
		i = 0;
		// while (mem && mem[i])
		// {
		// 	if(mem[i] == '\n')
		// 	{
		// 		*line = ft_strsub(mem, 0, i);
		// 		tmp = ft_strjoin(0,&mem[i]);
		// 		free(mem);
		// 		mem = tmp;
		// 		return (1);
		// 	}
		// 	i++;
		// }
	printf("																							%i\n",ss);
		if (read(fd,buf,BUFF_SIZE))
		{
			printf("	:%s\n",mem);
			tmp = ft_strjoin(mem, buf);
			free(mem);
			mem = tmp;
			printf("join	:%s\n",mem);
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
	return (1);
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
	if (argc != 2)
		return(0);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &c);
//	ft_strlen(0);
	printf("\nout:	%s\n", c);
	//system("leaks a.out");
}