/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:14:49 by seb               #+#    #+#             */
/*   Updated: 2022/04/01 17:44:20 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800.
# define HEIGHT 800.
# define SCALE 2.
# define MAX_ITERATION 200

enum e_zoom_dir {
	ZOOM_IN,
	ZOOM_OUT
};
enum e_events {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};
enum e_mouse_buttons {
	LEFT_BUTTON = 1,
	RIGHT_BUTTON = 2,
	MIDDLE_BUTTON = 3,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5
};
enum e_keys {
	KEY_MINUS = 27,
	KEY_PLUS = 24,
	KEY_B = 98,
	KEY_J = 106,
	KEY_M = 109,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_UP = 126,
	KEY_RIGHT = 124,
	KEY_DOWN = 125,
};

typedef struct s_img {
	char	*addr;
	int		bpp;
	int		endian;
	int		line_length;
	void	*img;
}	t_img;
typedef struct s_complex {
	double	r;
	double	i;
}	t_complex;
typedef struct s_coord {
	int		x;
	int		y;
}	t_coord;
typedef struct s_state	t_state;
typedef void			(*t_render_func)(t_state *);
struct s_state {
	double			zoom;
	int				step;
	int				redraw;
	t_complex		offset;
	t_img			*img;
	t_render_func	render_func;
	void			*mlx;
	void			*win;
};

int			quit(t_state *state);

void		render_mandelbrot_set(t_state *state);

void		display_argand_diagram(t_state *state);
void		display_debug_info(t_state *state);

void		draw_rectangle(t_img *img, t_coord start, t_coord end, int color);
void		put_pixel(t_img *data, t_coord coord, int color);
t_img		*new_image(void *mlx);

t_complex	coord_to_cplx(t_coord coord, t_state *state);
t_coord		cplx_to_coord(t_complex cplx, t_state *state);

int			mouse_handler(int button, int x, int y, void *param);
int			key_handler(int keycode, void *param);
int			loop_handler(void *param);

t_state		init_state(t_render_func f);
void		destroy_state(t_state *state);

int			i_to_color(int nb);

void		zoom(enum e_zoom_dir dir, t_state *state);

#endif
