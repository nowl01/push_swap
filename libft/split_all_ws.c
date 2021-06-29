/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_all_ws.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:25:20 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/29 09:31:30 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

static int     _is_white_space(char c)
{
    if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
        return (1);
    return (0);
}

static int			_count_words(char const *s)
{
	int	count;

	count = 0;
	while (*s && _is_white_space(*s))
		s++;
	while (*s)
	{
		if ((_is_white_space(*s) && !(_is_white_space(*(s + 1)))) || *(s + 1) == '\0')
			count++;
		s++;
	}
	return (count);
}

static int			_len_words(char const *s)
{
	int	k;

	k = 0;
	while (s[k] && !(_is_white_space(s[k])))
		k++;
	return (k);
}

char				**_split_all(char const *s)
{
	char		**p;
	int			size;
	int			i;
	int			j;

	if (!s)
		return (NULL);
	size = _count_words(s);
	if (!(p = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*s && _is_white_space(*s))
			s++;
		if (!(p[i] = (char *)malloc(sizeof(char) * (_len_words(s) + 1))))
			return (ft_free(p, size));
		j = 0;
		while (*s && !(_is_white_space(*s)))
			p[i][j++] = *s++;
		p[i++][j] = '\0';
	}
	p[i] = NULL;
	return (p);
}



