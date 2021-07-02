/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfurmane <vfurmane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 10:00:53 by vfurmane          #+#    #+#             */
/*   Updated: 2021/07/02 11:28:32 by vfurmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H

# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"

typedef struct s_config
{
	void		*mlx;
	void		*win;
}				t_config;

void	my_mlx_events(t_config *config);

#endif
