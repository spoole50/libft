/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:06:42 by spoole            #+#    #+#             */
/*   Updated: 2018/12/17 20:28:34 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_strjoin
**	Allocates and returns a “fresh” NULL terminated string
**	that is the result of the concatenation of s1 and s2.
**	If the allocation fails the function returns NULL.
*/

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
    size_t	len;

    len = 0;
    if (s1 != NULL)
      len += strlen(s1);
    if (s2 != NULL)
      len += strlen(s2);
    if ((res = (char*)malloc(sizeof(char) * (len + 1))) == NULL) 
        return (NULL);
    else
    {
        while (s1 != NULL && *s1)
            *res++ = *s1++;
        while (s2 != NULL && *s2)
            *res++ = *s2++;
        *res = '\0';
        return (res - len);
    }
}
