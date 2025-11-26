/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 00:11:56 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/24 22:44:38 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char **s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!*s1 || !s2)
		return (NULL);
	i = ft_strlen(*s1);
	j = ft_strlen(s2);
	str = (char *)malloc((i + j + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, i + 1);
	ft_strlcat(str, s2, i + j + 1);
	free(*s1);
	return (*s1 = str);
}
