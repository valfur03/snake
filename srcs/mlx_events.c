/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:08:21 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/03 00:17:40 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static int	my_mlx_close_window(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}

static int	my_mlx_handle_key(int code, t_config *config)
{
	if (code == XK_Escape)
		my_mlx_close_window(config->mlx);
	else if (code == XK_Up && config->last_direction != DOWN)
		config->direction = UP;
	else if (code == XK_Down && config->last_direction != UP)
		config->direction = DOWN;
	else if (code == XK_Left && config->last_direction != RIGHT)
		config->direction = LEFT;
	else if (code == XK_Right && config->last_direction != LEFT)
		config->direction = RIGHT;
	return (0);
}

void	my_mlx_events(t_config *config)
{
	config->playing = 1;
	mlx_loop_hook(config->mlx, loop_hook, config);
	mlx_hook(config->win, ClientMessage, StructureNotifyMask,
		my_mlx_close_window, config->mlx);
	mlx_hook(config->win, KeyPress, KeyPressMask, my_mlx_handle_key, config);
}
