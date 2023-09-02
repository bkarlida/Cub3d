/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:32:59 by muerdoga          #+#    #+#             */
/*   Updated: 2023/09/02 18:46:32 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	i;
	size_t	k;
	size_t	j;
	size_t	len;

	len = (ft_strlen(s1) + ft_strlen(s2));
	i = 0;
	k = 0;
	j = 0;
	nstr = (char *)malloc(sizeof(char) * (len + 1));
	if (nstr == NULL)
		return (0);
	while (s1[i])
		nstr[i++] = s1[j++];
	while (s2[k])
		nstr[i++] = s2[k++];
	nstr[i] = '\0';
	return (nstr);
}
