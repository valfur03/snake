/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:08:21 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 14:18:30 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static uint8_t	snake_is_border(t_pixel *snake)
{
	if (snake[0].x == 0 || snake[0].x == 19
		|| snake[0].y == 0 || snake[0].y == 19)
		return (1);
	return (0);
}

static int	my_mlx_loop_hook(t_config *config)
{
	static uint16_t		i;

	if (config->playing == 0)
		return (0);
	else if (i == 1800)
	{
		memmove(config->snake + 1, config->snake, 323 * sizeof (*config->snake));
		config->snake[0] = config->snake[1];
		config->snake[0].x += (config->direction == RIGHT)
			- (config->direction == LEFT);
		config->snake[0].y += (config->direction == DOWN)
			- (config->direction == UP);
		if (snake_is_border(config->snake))
		{
			config->playing = 0;
			return (0);
		}
		config->snake[0].color = HEAD;
		config->snake[1].color = BODY;
		render_map(config);
		mlx_put_image_to_window(config->mlx, config->win, config->img.ptr, 0, 0);
		i = 0;
	}
	else
		i++;
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
	else if (code == XK_Up && config->direction != DOWN)
		config->direction = UP;
	else if (code == XK_Down && config->direction != UP)
		config->direction = DOWN;
	else if (code == XK_Left && config->direction != RIGHT)
		config->direction = LEFT;
	else if (code == XK_Right && config->direction != LEFT)
		config->direction = RIGHT;
	return (0);
}

void	my_mlx_events(t_config *config)
{
	config->playing = 1;
	mlx_loop_hook(config->mlx, my_mlx_loop_hook, config);
	mlx_hook(config->win, ClientMessage, StructureNotifyMask,
		my_mlx_close_window, config->mlx);
	mlx_hook(config->win, KeyPress, KeyPressMask, my_mlx_handle_key, config);
}
