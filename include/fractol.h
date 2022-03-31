/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:14:49 by seb               #+#    #+#             */
/*   Updated: 2022/03/31 11:26:09 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define NULL (void *)0

// TODO: remove
#define max(a,b) (((a) (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITERATION 50

enum e_event {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum e_mouse_button {
	LEFT_BUTTON = 1,
	RIGHT_BUTTON = 2,
	MIDDLE_BUTTON = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5
};

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_complex {
	double	r;
	double	i;
}				t_complex;

typedef struct s_coord {
	int		x;
	int		y;
}				t_coord;

typedef struct s_state t_state;

typedef void	(*t_render_func)(t_state *, t_img *);
struct s_state {
	void			*mlx;
	void			*win;
	t_img			*img;
	double			zoom;
	t_coord			center;
	t_render_func	f;

};

void	mandelbrot_set_to_img(t_state *state, t_img *img);
void	argand_diagram_to_img(t_state *state, t_img *img);

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_img	*generate_new_image(void *mlx);
void	update_img(t_state *state, t_render_func f);

t_complex	coord_to_cplx(t_coord coord, t_state *state);
t_coord		cplx_to_coord(t_complex cplx, t_state *state);

int	mouse_button_hook(int button, int x, int y, void *param);
int	mouse_move_hook(int x, int y, void *param);
int	render_next_frame_hook(void *param);

t_state	init_state(t_render_func f);

#endif
