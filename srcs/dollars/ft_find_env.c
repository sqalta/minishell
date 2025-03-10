/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:59:12 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/17 15:30:26 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_equal_finder(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '=')
		return (1);
	else
		return (0);
}

char	*line_connect(char *arg)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (arg[i] && ft_isalnum(arg[i]))
		i++;
	line = malloc(sizeof(char) * i + 1);
	i = 0;
	while (arg[j] && ft_isalnum(arg[j]))
	{
		line[i] = arg[j];
		i++;
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_find_env(char *arg)
{
	int		i;
	int		len;
	char	*line;
	char	*ret;

	i = 0;
	line = line_connect(arg);
	len = ft_strlen(line);
	free(line);
	while (g_data.envp[i])
	{
		if (ft_equal_finder(line, g_data.envp[i]) == 1)
		{
			ret = ft_strdup(g_data.envp[i] + len + 1);
			free(arg);
			return (ret);
		}
		i++;
	}
	line = ft_strdup("");
	free(arg);
	return (line);
}
