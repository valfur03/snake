/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:00:26 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 23:36:07 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

int	main(void)
{
	t_config	config;

	srand(time(NULL));
	init_snake(&config);
	if (init_mlx(&config) < 0)
		return (1);
	render_map(&config);
	config.win = mlx_new_window(config.mlx, config.width, config.height,
			"snek");
	mlx_put_image_to_window(config.mlx, config.win, config.img.ptr, 0, 0);
	my_mlx_events(&config);
	mlx_loop(config.mlx);
	printf("Score: %d\n", config.score);
	mlx_destroy_image(config.mlx, config.img.ptr);
	mlx_destroy_window(config.mlx, config.win);
	mlx_destroy_display(config.mlx);
	free(config.mlx);
	return (0);
}
