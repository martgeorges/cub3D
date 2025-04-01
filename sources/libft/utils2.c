/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:25:20 by ncollign          #+#    #+#             */
/*   Updated: 2025/04/01 07:14:36 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	is_charset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s, const char *set)
{
	char	*trimmed;
	int		start;
	int		end;
	int		i;

	start = 0;
	if (!s || !set)
		return (NULL);
	while (s[start] && is_charset(s[start], set))
		start++;
	end = ft_strlen(s) - 1;
	while (end > start && is_charset(s[end], set))
		end--;
	trimmed = (char *)malloc(end - start + 2);
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start <= end)
		trimmed[i++] = s[start++];
	trimmed[i] = '\0';
	return (trimmed);
}
