/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:43:54 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 14:04:17 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static uint8_t	pixel_is_border(t_pixel *pixel)
{
	if (pixel->x == 0 || pixel->x == 19
		|| pixel->y == 0 || pixel->y == 19)
		return (1);
	return (0);
}

static uint8_t	pixel_is_snake(t_pixel *snake, t_pixel *pixel, uint32_t *color)
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
