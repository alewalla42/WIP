/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alewalla <alewalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:19:46 by alewalla          #+#    #+#             */
/*   Updated: 2022/05/07 15:13:23 by alewalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_alloc_path_tab(t_core *core)
{
	int		i;
	char *str;
	t_env *tmp;

	i = -1;
	tmp = core->envl;
	str = ft_get_value_from_envl(tmp, "PATH");
	core->path->path_env = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	core->path->path_env = str;
	core->path->path_tab = ft_split(core->path->path_env, ':');
	while (core->path->path_tab[++i] != NULL)
		core->path->path_tab[i] = ft_strjoin(core->path->path_tab[i], "/");
}

/*
t_llist		*ft_case_cmd_found(t_llist *list, char *cmd)
{
	if (!list->first_cmd)
		list->first_cmd = add_first_t_cmd(cmd, 0);
	else
		list->first_cmd = add_last_t_cmd(list->first_cmd, cmd, 0);
	return (list);
}

t_llist	*ft_check_cmd_path(t_llist *list, char *line_read)
{
	int		i;
	int		y;
	char	*cpy;
	char	*tmp;

	y = list->index;
	while (line_read[y] && line_read[y] != '|' && line_read[y] != '<' && line_read[y] != '>' && line_read[y] != ' ' && line_read[y] != '\'' && line_read[y] != '\"')
		y++;
	cpy = malloc(sizeof(char) * (y - list->index + 1));
	i = 0;
	while (list->index < y)
	{
		cpy[i] = line_read[list->index];
		i++;
		list->index++;
	}
	cpy[i] = '\0';
	tmp = ft_strdup(cpy);
	cpy = test_cmd(list, cpy);
	if (cpy == NULL)
	{
		printf("%s: command not found\n", tmp);
		if (tmp)
			free(tmp);
		return (list);
	}
	free(tmp);
	list = ft_case_cmd_found(list, cpy);
	free(cpy);
	return (list);
}*/