/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 14:05:43 by mkarakul          #+#    #+#             */
/*   Updated: 2023/02/04 14:05:47 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	mem;

	mem = count * size;
	ptr = malloc(mem);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, mem);
	return (ptr);
}
