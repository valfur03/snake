/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:00:26 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 13:28:53 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static int	pixel_is_border(t_pixel *pixel)
{
	if (pixel->x == 0 || pixel->x == 19
		|| pixel->y == 0 || pixel->y == 19)
		return (1);
	return (0);
}

static int	pixel_is_snake(t_pixel *snake, t_pixel *pixel, uint32_t *color)
{
	uint16_t	i;

	i = 0;
	while (i < 4)
	{
		if (snake[i].x == pixel->x && snake[i].y == pixel->y)
		{
			*color = snake[i].color;
			return (1);
		}
		i++;
	}
	return (0);
}

void	render_map(t_config *config)
{
	t_pixel		pixel;
	uint32_t	color;

	pixel.size = 40;
	pixel.x = 0;
	while (pixel.x < 20)
	{
		pixel.y = 0;
		while (pixel.y < 20)
		{
			if (pixel_is_border(&pixel))
				pixel.color = BORDER;
			else if (pixel_is_snake(config->snake, &pixel, &color))
				pixel.color = color;
			else
				pixel.color = FLOOR;
			my_mlx_put_pixel_size(&config->img, &pixel);
			pixel.y++;
		}
		pixel.x++;
	}
}

int	main(void)
{
	t_config	config;

	if (init_mlx(&config) < 0)
		return (1);
	init_snake(&config);
	render_map(&config);
	config.win = mlx_new_window(config.mlx, 800, 800, "snek");
	mlx_put_image_to_window(config.mlx, config.win, config.img.ptr, 0, 0);
	my_mlx_events(&config);
	mlx_loop(config.mlx);
	mlx_destroy_image(config.mlx, config.img.ptr);
	mlx_destroy_window(config.mlx, config.win);
	mlx_destroy_display(config.mlx);
	free(config.mlx);
	return (0);
}
