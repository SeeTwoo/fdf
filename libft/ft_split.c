/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:47:09 by wbeschon          #+#    #+#             */
/*   Updated: 2024/11/29 12:04:05 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static size_t	ft_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static char	*ft_dup(char const *s, char c)
{
	char	*dest;
	size_t	len;

	len = ft_len(s, c);
	dest = ft_calloc(ft_len(s, c) + 1, sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s, len + 1);
	return (dest);
}

static void	free_tab(char **tab, size_t i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

char	**ft_split(char	const *s, char c)
{
	char	**tab;
	size_t	i;

	tab = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	i = 0;
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			tab[i] = ft_dup(s, c);
			if (!tab)
				return (free_tab(tab, i), NULL);
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	tab[i] = NULL;
	return (tab);
}

/*
int	main(void)
{
	char	s[] = "salade tomate oignon";
	char	c = ' ';
	char	**ptr;
	size_t	i;

	i = 0;
	ptr = ft_split(s, c);
	if (ptr)
	{
		while (ptr[i])
		{
			printf("%s\n", ptr[i]);
			i++;
		}
	}
	return (0);
}
*/
