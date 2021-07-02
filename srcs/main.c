/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:00:26 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 11:29:09 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

int	main(void)
{
	t_config	config;

	config.mlx = mlx_init();
	config.win = mlx_new_window(config.mlx, 800, 800, "snek");
	my_mlx_events(&config);
	mlx_loop(config.mlx);
	mlx_destroy_window(config.mlx, config.win);
	mlx_destroy_display(config.mlx);
	free(config.mlx);
	return (0);
}