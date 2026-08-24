/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:04:44 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/07 03:33:18 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	// 君のロジックそのまま：文字の終わり（次が区切りor終端）を数える
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static size_t	word_size(const char *s, char c)
{
	size_t	size;

	size = 0;
	// 次の区切り文字か、終端が来るまで進む
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

static char	*ft_strndup(const char *s, size_t size)
{
	char	*elem;
	size_t	i;

	i = 0;
	elem = (char *)malloc(sizeof(char) * (size + 1));
	if (!elem)
		return (NULL);
	while (i < size)
	{
		elem[i] = s[i];
		i++;
	}
	elem[i] = '\0';
	return (elem);
}

static void	*free_memory(char **newstr, size_t word_count)
{
	size_t	i;

	i = 0;
	while (i < word_count)
	{
		free(newstr[i]);
		i++;
	}
	free(newstr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	row;
	size_t	i;
	char	**split;

	if (!s)
		return (NULL);
	row = count_word(s, c);
	split = (char **)malloc(sizeof(char *) * (row + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < row)
	{
		// 1. 最初にある区切り文字を飛ばす
		while (*s == c)
			s++;
		
		// 2. 文字列をコピーする
		split[i] = ft_strndup(s, word_size(s, c));
		if (!split[i])
			return (free_memory(split, i));
		
		// 3. 次の単語のためにポインタを進める
		s += word_size(s, c);
		i++;
	}
	split[i] = NULL;
	return (split);
}
