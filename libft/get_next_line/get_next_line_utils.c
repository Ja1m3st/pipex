/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaimesan <jaimesan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:59:46 by jaimesan          #+#    #+#             */
/*   Updated: 2024/10/24 13:28:52 by jaimesan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_get(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_get(char *save, int c)
{
	size_t	i;

	if (!save)
		return (0);
	i = 0;
	if (c == '\0')
		return (&save[ft_strlen_get(save)]);
	while (save[i] != '\0')
	{
		if (save[i] == (char) c)
			return (&save[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin_get(char *save, char *buffer)
{
	size_t		i;
	size_t		j;
	size_t		max;
	char		*str;

	if (!save)
	{
		save = (char *)malloc(1 * sizeof(char));
		save[0] = '\0';
	}
	if (!save || !buffer)
		return (NULL);
	max = ft_strlen_get(save) + ft_strlen_get(buffer);
	str = malloc(sizeof(char) * (max + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (save)
		while (save[++i] != '\0')
			str[i] = save[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen_get(save) + ft_strlen_get(buffer)] = '\0';
	return (free(save), str);
}
