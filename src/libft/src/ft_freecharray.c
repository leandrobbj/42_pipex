/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freecharray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 00:11:56 by lbraga            #+#    #+#             */
/*   Updated: 2025/11/24 20:09:54 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freecharray(char **array)
{
	int		word;

	word = 0;
	while (array[word])
		free(array[word++]);
	free(array);
}
