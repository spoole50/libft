/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 23:52:22 by spoole            #+#    #+#             */
/*   Updated: 2019/07/31 23:52:25 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_charspn
** computes the string array index of character (q) in charset (str), else -1
*/

#include "libft.h"

int		ft_charspn(char *chset, char q)
{
	int	i;

	i = 0;
	while (chset[i] != '\0')
	{
		if (chset[i] == q)
			return (i);
		i++;
	}
	return (-1);
}
