/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:08:21 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 11:27:17 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static int	my_mlx_loop_hook(t_config *config)
{
	(void)config;
	return (0);
}

static int	my_mlx_close_window(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

static int	my_mlx_handle_key(int code, t_config *config)
{
	if (code == XK_Escape)
		my_mlx_close_window(config->mlx);
	return (0);
}

void	my_mlx_events(t_config *config)
{
	mlx_loop_hook(config->mlx, my_mlx_loop_hook, config);
	mlx_hook(config->win, ClientMessage, StructureNotifyMask,
		my_mlx_close_window, config->mlx);
	mlx_hook(config->win, KeyPress, KeyPressMask, my_mlx_handle_key, config);
}
