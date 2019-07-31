/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_indx_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:21:11 by spoole            #+#    #+#             */
/*   Updated: 2019/07/24 23:21:13 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 ** ft_c(har)_ind(e)x_s(tring)
 ** Returns integer index (int i) of the first instance of chatacter (char q) in a string (char **str) 
 */

#include "libft.h"

int     ft_c_indx_str(char *str, char q)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == q)
            return (i);
        i++;
    }
    return (-1);
}