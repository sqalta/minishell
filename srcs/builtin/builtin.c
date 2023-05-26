/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:34:03 by mkarakul          #+#    #+#             */
/*   Updated: 2023/05/26 18:09:55 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin(void)
{
	if (ft_strcmp(temp->arg, "echo"))
		ft_echo(data);
	else if (ft_strcmp(temp->arg, "cd"))
		ft_cd(data);
	else if (ft_strcmp(temp->arg, "pwd"))
		ft_pwd(data);
	else if (ft_strcmp(temp->arg, "export"))
		ft_export(data);
	else if (ft_strcmp(temp->arg, "unset"))
		ft_unset(data);
	else if (ft_strcmp(temp->arg, "env"))
		ft_env(data);
	else
		return (-1);
	return (0);
}
