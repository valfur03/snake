/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 23:45:23 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/03 15:22:35 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static uint8_t	can_update_frame(suseconds_t initial_time,
	struct timeval *time_now, t_config *config)
{
	return ((time_now->tv_usec > initial_time
			&& time_now->tv_usec - initial_time >= (long)config->speed)
		|| (time_now->tv_usec < initial_time
			&& 1000000 - initial_time
			+ time_now->tv_usec >= (long)config->speed)
		|| config->last_direction != config->direction);
}

static uint8_t	is_going_to_die(t_config *config)
{
	static uint8_t		going_to_die;

	if ((config->snake[0].x + (config->direction == RIGHT)
			== config->width / config->tile_size - 1
			|| config->snake[0].x - (config->direction == LEFT) == 0
			|| config->snake[0].y + (config->direction == DOWN)
			== config->height / config->tile_size - 1
			|| config->snake[0].y - (config->direction == UP) == 0)
		&& going_to_die < 1)
	{
		going_to_die++;
		return (1);
	}
	else
		going_to_die = 0;
	return (0);
}

static uint8_t	snake_is_border(t_config *config)
{
	if (config->snake[0].x == 0
		|| config->snake[0].x == config->width / config->tile_size - 1
		|| config->snake[0].y == 0
		|| config->snake[0].y == config->height / config->tile_size - 1)
		return (1);
	return (0);
}

static uint8_t	move_snake(t_config *config)
{
	memmove(config->snake + 1, config->snake,
		(config->tile_nbr - 1) * sizeof (*config->snake));
	config->snake[0] = config->snake[1];
	config->snake[0].x += (config->direction == RIGHT)
		- (config->direction == LEFT);
	config->snake[0].y += (config->direction == DOWN)
		- (config->direction == UP);
	interpolate_snake_colors(config);
	if (snake_is_border(config)
		|| pixel_is_snake(config, &config->snake[0], 1, NULL))
	{
		config->playing = 0;
		return (0);
	}
	if (config->snake[0].x == config->collectible.x
		&& config->snake[0].y == config->collectible.y)
	{
		generate_new_collectible(config);
		config->score++;
		config->snake_size++;
		config->speed -= 70000 / config->tile_nbr;
	}
	return (1);
}

int	loop_hook(t_config *config)
{
	static suseconds_t	initial_time;
	struct timeval		time_now;

	if (config->pause == 1)
		return (0);
	if (gettimeofday(&time_now, NULL) == -1)
		return (0);
	if (config->playing == 0)
		return (0);
	else if (can_update_frame(initial_time, &time_now, config))
	{
		initial_time = time_now.tv_usec;
		if (is_going_to_die(config))
			return (0);
		if (move_snake(config) == 0)
			return (0);
		render_map(config);
		mlx_put_image_to_window(config->mlx, config->win, config->img.ptr,
			0, 0);
		config->last_direction = config->direction;
	}
	return (0);
}
