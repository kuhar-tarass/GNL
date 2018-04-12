/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuhar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 18:09:56 by tkuhar            #+#    #+#             */
/*   Updated: 2018/03/25 18:09:57 by tkuhar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;

	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	fresh = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (fresh == 0)
		return (0);
	i = 0;
	while (s1 && *s1 != '\0')
		fresh[i++] = *s1++;
	if (s2)
		while (s1 && *s2 != '\0')
			fresh[i++] = *s2++;
	fresh[i] = '\0';
	return (fresh);
}
