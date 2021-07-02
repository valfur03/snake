/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:00:26 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 12:18:06 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

static int	pixel_is_border(t_pixel *pixel)
{
	if (pixel->x == 0 || pixel->x == 800 - pixel->size
		|| pixel->y == 0 || pixel->y == 800 - pixel->size)
		return (1);
	return (0);
}

void	render_map(t_mlx_img *img)
{
	t_pixel	pixel;

	pixel.size = 40;
	pixel.x = 0;
	while (pixel.x < 800)
	{
		pixel.y = 0;
		while (pixel.y < 800)
		{
			if (pixel_is_border(&pixel))
				pixel.color = BORDER;
			else
				pixel.color = FLOOR;
			my_mlx_put_pixel(img, &pixel);
			pixel.y += pixel.size;
		}
		pixel.x += pixel.size;
	}
}

int	main(void)
{
	t_config	config;

	if (init_mlx(&config) < 0)
		return (1);
	render_map(&config.img);
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
