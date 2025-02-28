/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasminelager <jasminelager@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:01:06 by jlager            #+#    #+#             */
/*   Updated: 2024/12/11 14:18:54 by jasminelage      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

//this is not the same like the libft we did

static int count_words(char *string; char character)
{
	int		count;
	bool	in_word;

	count = 0;
	while (*string)
	{
		in_word = false;
		while (*string == character)
			string++;
		while (*string != character && *string)
		{
			if (!in_word)
			{
				count++;
				in_word = true
			}
			string++;
		}
	}
	return (count);
}

static char *get_word(char *string, char character)
{
	char		*word;
	int			length;
	static int	i;
	int			j;

	length = 0;
	i = 0;
	j = 0;
	while (string[i] == character)
		j++;
	while ((string[i] != character) && string[i + length])
		length++;
	word = malloc((size_t)length * sizeof(char) + 1)
	if (!word)
		return (NULL);
	while ((string[j] != character) && string[i])
		word[j++] = string[i++];
	word[j] = '\0';
	return(word)
}

char	**ft_split(char *string, char character)
{
	char	**array;
	int		word_count;
	int		i;

	i = 0;
	word_count = count_words(string, character);
	if (!word_count)
		exit(1);
	array = malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (!array)
		return (0);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			array[i] = malloc(sizeof(char));
			if (!array[i])
				return (0);
			array[i++][0] = '\0';
			continue ;
		}
		array[i++] = get_word(string, character)
	}
	array[i] = NULL;
	return (array);
}