/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:22:04 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/29 14:22:09 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	pos;

	pos = 0;
	while (str[pos])
		pos++;
	return (pos);
}

char	*ft_strdup(const char *src)
{
	char	*ptrdup;
	size_t	slen;
	size_t	i;

	slen = ft_strlen((char *)src);
	ptrdup = malloc((slen + 1) * sizeof(char));
	if (!ptrdup)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		ptrdup[i] = src[i];
		i++;
	}
	ptrdup[i] = '\0';
	return (ptrdup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*temp_s;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	temp_s = malloc((len + 1) * sizeof(char));
	if (!temp_s)
		return (NULL);
	while (i < len)
	{
		temp_s[i] = s[start + i];
		i++;
	}
	temp_s[len] = 0;
	return (temp_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*new_str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = malloc((len1 + len2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		new_str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		new_str[i + len1] = s2[i];
		i++;
	}
	new_str[i + len1] = '\0';
	return (new_str);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
