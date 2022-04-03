/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 22:14:49 by seb               #+#    #+#             */
/*   Updated: 2022/04/03 14:44:31 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 800.
# define HEIGHT 800.
# define SCALE 2.
# define MAX_ITERATION 100
# define MAX_STEPS 1000

enum e_zoom_dir {
	ZOOM_IN,
	ZOOM_OUT,
	ZOOM_RESET
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
	KEY_RETURN = 36,
	KEY_B = 11,
	KEY_J = 38,
	KEY_M = 46,
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
typedef struct s_args {
	t_render_func	render_func;
	t_complex		c;
}	t_args;
struct s_state {
	int				steps;
	double			zoom;
	int				redraw;
	t_complex		offset;
	t_complex		factor;
	t_img			*img;
	t_render_func	render_func;
	t_complex		c;
	void			*mlx;
	void			*win;
	int				frame;
	double			freq;
};

int			quit(t_state *state);

void		render_mandelbrot_set(t_state *state);
void		render_julia_set(t_state *state);
void		render_newton_set(t_state *state);

void		put_pixel(t_img *data, t_coord coord, unsigned int color);
t_img		*new_image(void *mlx);

t_complex	coord_to_cplx(t_coord coord, t_state *state);

t_args		parse_args(int argv, char **argc);
void		display_params(void);

int			mouse_handler(int button, int x, int y, void *param);
int			key_handler(int keycode, void *param);
int			loop_handler(void *param);

t_state		init_state(t_args *args);
void		destroy_state(t_state *state);

unsigned int	i_to_color(int nb, double n, t_state * state);
unsigned int HSVtoARGB(unsigned char hue, unsigned char sat, unsigned char val);

void		zoom(enum e_zoom_dir dir, t_state *state);
double		zoom_interpolation(int steps);

#endif
