/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:03:47 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 19:03:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_finalsize(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*store(const char *s, int *start, char c)
{
	int		i;
	int		count;
	int		cur;
	char	*d;

	count = 0;
	i = 0;
	cur = *start;
	while (s[*start] != c && s[*start])
	{
		count++;
		(*start)++;
	}
	*start = cur;
	d = (char *)malloc((count + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	while (s[*start] && s[*start] != c)
	{
		d[i] = s[*start];
		i++;
		(*start)++;
	}
	d[i] = '\0';
	return (d);
}

static void	free_split(char **d, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(d[i]);
		i++;
	}
	free(d);
}

static	char	**createpointer(const char *s, char c)
{
	char	**p;

	if (s == NULL)
		return (NULL);
	p = (char **)malloc((get_finalsize(s, c) + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	return (p);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	**d;

	i = 0;
	j = 0;
	d = createpointer(s, c);
	if (d == NULL)
    	return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			d[j] = store(s, &i, c);
			if (d[j] == NULL)
			{
				free_split(d, get_finalsize(s, c));
				return (NULL);
			}
			j++;
		}
	}
	return (d[j] = NULL, d);
}

/*#include <stdio.h>
#include <stdlib.h>

char	**ft_split(const char *s, char c); // declare your function

void	print_result(char **res)
{
	int i = 0;
	if (!res)
	{
		printf("NULL\n");
		return;
	}
	while (res[i])
	{
		printf("\"%s\"\n", res[i]);
		i++;
	}
	printf("----\n");
}

int	main(void)
{
	char **result;

	// 1. Basic split
	result = ft_split("hello world", ' ');
	printf("Case 1:\n");
	print_result(result);

	// 2. Multiple spaces
	result = ft_split("   hello   world ", ' ');
	printf("Case 2:\n");
	print_result(result);

	// 3. Multiple delimiters
	result = ft_split(",,,a,,b,c,", ',');
	printf("Case 3:\n");
	print_result(result);

	// 4. Empty string
	result = ft_split("", ',');
	printf("Case 4:\n");
	print_result(result);

	// 5. NULL input
	result = ft_split(NULL, ',');
	printf("Case 5:\n");
	print_result(result);

	// 6. Only delimiters
	result = ft_split(",,,", ',');
	printf("Case 6:\n");
	print_result(result);

	// 7. No delimiters at all
	result = ft_split("abcdef", ',');
	printf("Case 7:\n");
	print_result(result);

	// 8. Delimiter at beginning
	result = ft_split(",abc", ',');
	printf("Case 8:\n");
	print_result(result);

	// 9. Delimiter at end
	result = ft_split("abc,", ',');
	printf("Case 9:\n");
	print_result(result);

	// 10. One character string
	result = ft_split("a", ',');
	printf("Case 10:\n");
	print_result(result);

	return (0);
}*/