/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollars_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafakarakulak <mustafakarakulak@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:46:34 by mustafakara       #+#    #+#             */
/*   Updated: 2023/06/05 19:03:02 by mustafakara      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    ft_parse_dollars(void)
{
    int i;

    if (g_data.list->arg[1] == '0')
        g_data.list->arg = ft_strdup("minishell");
    else if (g_data.list->arg[1] == '?')
        g_data.list->arg = ft_strdup(ft_itoa(g_data.status));
    else
        g_data.list->arg = ft_strdup(ft_find_env(g_data.list->arg));
}

void    ft_dollars_line(void)
{
    t_arg   *temp_s;

    temp_s = g_data.list;
    while (g_data.list)
    {
        if (g_data.list->type == DOLLAR)
            ft_parse_dollars();
        g_data.list = g_data.list->next;
    }
    g_data.list = temp_s;
}