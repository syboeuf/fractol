/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:55:54 by syboeuf           #+#    #+#             */
/*   Updated: 2019/11/19 13:49:43 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom_burningship(t_fractol *f, int x, int y, int zoomin)
{
	int i;
	int j;

	i = x;
	j = y;
	if (zoomin == 1)
		f->zoom *= 2;
	else
		f->zoom /= 2;
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->data = mlx_get_data_addr(f->img_ptr, &f->bpp, &f->sizeline, &f->endian);
	draw_burning_ship(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}

void	put_burning_in_image(t_fractol *f, int px, int py, int i)
{
	int index;

	index = i;
	index = (px + py * WIDTH) * 4;
	f->data[index + 0] = (unsigned char)25 + i * 30;
	f->data[index + 1] = (unsigned char)25 + i * 10;
	f->data[index + 2] = (unsigned char)85 - i * 5;
	f->data[index + 3] = 0;
}

void	draw_burning_ship_2(t_fractol *f, float j, float i, int max_iterations)
{
	int iteration;

	f->x0 = -1.80 + (float)j * (-1.7 + 1.80) / WIDTH / f->zoom;
	f->y0 = -0.08 + (float)i * (0.01 + 0.08) / HEIGHT / f->zoom;
	f->xmin = 0.0;
	f->ymin = 0.0;
	iteration = 0;
	while ((f->xmin * f->xmin + f->ymin * f->ymin < 4)
		&& (iteration < max_iterations))
	{
		f->xmax = f->xmin * f->xmin - f->ymin * f->ymin + f->x0;
		f->ymax = 2 * fabsf(f->xmin * f->ymin) + f->y0;
		f->xmin = f->xmax;
		f->ymin = f->ymax;
		iteration++;
	}
	put_burning_in_image(f, j, i, iteration);
}

void	draw_burning_ship(t_fractol *f)
{
	int	max_iterations;
	int	i;
	int	j;

	max_iterations = 100;
	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			draw_burning_ship_2(f, j, i, max_iterations);
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}
