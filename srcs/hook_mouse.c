/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:49:24 by syboeuf           #+#    #+#             */
/*   Updated: 2019/11/19 13:51:05 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		deal_move(int x, int y, void *params)
{
	t_fractol *f;

	f = (t_fractol *)params;
	f->x0 = ((x - WIDTH) / 2.0) / (WIDTH / 4);
	f->y0 = ((y - HEIGHT) / 2.0) / (HEIGHT / 4);
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->data = mlx_get_data_addr(f->img_ptr, &f->bpp, &f->sizeline, &f->endian);
	draw_julia(f);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img_ptr, 0, 0);
	return (0);
}

void	zoom(t_fractol *f, int x, int y)
{
	if (strcmp(f->name_fractol, "mandelbrot") == 0)
		zoom_mandelbrot(f, x, y, 1);
	else if (strcmp(f->name_fractol, "julia") == 0)
		zoom_julia(f, 1);
	else if (strcmp(f->name_fractol, "burningship") == 0)
		zoom_burningship(f, x, y, 1);
	else if (strcmp(f->name_fractol, "sierpinskicarpet") == 0)
		change_iteration(f, 1);
	else if (strcmp(f->name_fractol, "barnsleyfern") == 0)
		zoom_barnsleyfern(f, x, y, 1);
}

void	dezoom(t_fractol *f, int x, int y)
{
	if (strcmp(f->name_fractol, "mandelbrot") == 0)
		zoom_mandelbrot(f, x, y, -1);
	else if (strcmp(f->name_fractol, "julia") == 0)
		zoom_julia(f, -1);
	else if (strcmp(f->name_fractol, "burningship") == 0)
		zoom_burningship(f, x, y, -1);
	else if (strcmp(f->name_fractol, "sierpinskicarpet") == 0)
		change_iteration(f, -1);
	else if (strcmp(f->name_fractol, "barnsleyfern") == 0)
		zoom_barnsleyfern(f, x, y, -1);
}

int		deal_mouse(int button, int x, int y, void *params)
{
	t_fractol		*f;
	int				i;

	i = x;
	i = y;
	f = (t_fractol *)params;
	if (button == 1 || button == 5)
		zoom(f, x, y);
	else if (button == 2 || button == 4)
		dezoom(f, x, y);
	return (0);
}
