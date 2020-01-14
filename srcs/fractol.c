/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:44:41 by syboeuf           #+#    #+#             */
/*   Updated: 2019/11/21 15:13:21 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_color_in_image(t_fractol *f, int px, int py, int i)
{
	int index;

	index = i;
	index = (px + py * WIDTH) * 4;
	f->data[index + 0] = (unsigned char)f->blue_array[i];
	f->data[index + 1] = (unsigned char)f->green_array[i];
	f->data[index + 2] = (unsigned char)f->red_array[i];
	f->data[index + 3] = 0;
}

void	draw_fractal(char *argv, t_fractol *f)
{
	f->img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->data = mlx_get_data_addr(f->img_ptr, &f->bpp, &f->sizeline, &f->endian);
	if (strcmp("julia", argv) == 0)
		julia(f);
	else if (strcmp("mandelbrot", argv) == 0)
	{
		f->panx = -100;
		f->pany = 0;
		f->zoom = 150.0;
		draw_mandelbrot(f);
	}
	else if (strcmp("burningship", argv) == 0)
		draw_burning_ship(f);
	else if (strcmp("sierpinskicarpet", argv) == 0)
		draw_sierpinski_carpet(f);
	else if (strcmp("barnsleyfern", argv) == 0)
		barnsleyfern(f);
	else
	{
		ft_putstr("Fractal: ");
		ft_putstr("julia, mandelbrot, burningship, ");
		ft_putstr("barnsleyfern, sierpinskicarpet !!\n");
		exit(1);
	}
}

int		deal_key(int key, void *params)
{
	t_fractol *f;

	f = (t_fractol *)params;
	if (key == 53)
	{
		mlx_destroy_image(f->mlx_ptr, f->img_ptr);
		exit(1);
	}
	return (0);
}

void	init_fractol(char *argv, t_fractol *f)
{
	f->zoom = 1;
	f->x0 = 0.0;
	f->y0 = 0.0;
	f->name_fractol = argv;
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "fractol");
	mlx_key_hook(f->win_ptr, deal_key, (void*)f);
	mlx_mouse_hook(f->win_ptr, deal_mouse, (void*)f);
	draw_fractal(argv, f);
	mlx_loop(f->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_fractol	f;

	if (argc == 2)
		init_fractol(argv[1], &f);
	else
	{
		ft_putstr("Fractal: ");
		ft_putstr("julia, mandelbrot, burningship, ");
		ft_putstr("barnsleyfern, sierpinskicarpet !!\n");
	}
	return (0);
}
