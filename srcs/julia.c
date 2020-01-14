/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:15:49 by syboeuf           #+#    #+#             */
/*   Updated: 2019/11/19 13:51:55 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_julia(t_fractol *f)
{
	int	iteration;
	int	px;
	int	py;

	px = -1;
	while (++px < WIDTH)
	{
		py = -1;
		while (++py < HEIGHT)
		{
			f->panx = (f->xmin + px * f->xdelta) / f->zoom;
			f->pany = (f->ymin + py * f->ydelta) / f->zoom;
			iteration = -1;
			while (f->panx * f->panx + f->pany * f->pany < 4
				&& ++iteration < f->max_iteration)
			{
				f->xtemp = f->panx * f->panx - f->pany * f->pany + f->x0;
				f->pany = 2 * f->panx * f->pany + f->y0;
				f->panx = f->xtemp;
			}
			put_color_in_image(f, px, py,
				(iteration == f->max_iteration) ? 0 : iteration);
		}
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}

void	zoom_julia(t_fractol *f, int zoomin)
{
	if (zoomin == 1)
		f->zoom *= 2;
	else
		f->zoom /= 2;
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->data = mlx_get_data_addr(f->img_ptr, &f->bpp, &f->sizeline, &f->endian);
	draw_julia(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
}

void	calculate_palette_julia_2(t_fractol *f, int combo, int step, int x)
{
	int b;
	int g;
	int r;

	r = 0;
	g = 0;
	b = 255;
	if (combo % 2 == 0)
		b = step * 6;
	else
		b = 256 - step * 6;
	if (combo == 1 || combo == 5)
		g = step * 6;
	else if (combo == 3)
		g = 256 - step * 6;
	if (combo == 3)
		r = step * 6;
	else if (combo == 100)
		r = 256 - step * 6;
	f->red_array[x] = r;
	f->green_array[x] = g;
	f->blue_array[x] = b;
}

void	calculate_palette_julia(t_fractol *f)
{
	int x;
	int combo;
	int step;

	x = 0;
	combo = -1;
	while (++combo < 6)
	{
		step = -1;
		while (++step < 42)
		{
			calculate_palette_julia_2(f, combo, step, x);
			x++;
		}
	}
}

void	julia(t_fractol *f)
{
	f->x0 = -0.835;
	f->y0 = -0.2321;
	f->xmin = -1.6;
	f->xmax = 1.6;
	f->ymin = -1.15;
	f->ymax = 1.15;
	f->xdelta = (f->xmax - f->xmin) / WIDTH;
	f->ydelta = (f->ymax - f->ymin) / HEIGHT;
	f->max_iteration = 256;
	f->zoom = 1.0;
	calculate_palette_julia(f);
	draw_julia(f);
	mlx_hook(f->win_ptr, 6, (1L << 6), deal_move, (void*)f);
}
