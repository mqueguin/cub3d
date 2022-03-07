/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:43:34 by mqueguin          #+#    #+#             */
/*   Updated: 2022/03/07 23:29:02 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include "mlx.h"
# include "../libft/libft.h"

# define PLAYER_SPEED	0.10
# define PLAYER_ROT		0.10
# define KEYCODE_A 		97
# define KEYCODE_S		115
# define KEYCODE_D		100
# define KEYCODE_W		119
# define KEYCODE_UP		65362
# define KEYCODE_DOWN	65364
# define KEYCODE_LEFT	65361
# define KEYCODE_RIGHT	65363
# define KEYCODE_ESCAPE	65307
# define FOV 			60

typedef struct s_info_game
{
	int		fd;
	int		line_index;
	int		x;
	int		y;
	int		characters_start_x_y[2];
	char	character_pos;
	int		win_res[2];
	int		color_f[3];
	int		color_c[3];
	char	parse_char[3];
	char	*path_textures_s;
	char	*path_textures_no;
	char	*path_textures_so;
	char	*path_textures_we;
	char	*path_textures_ea;
	int		b_colors[2];
	int		b_res;
	int		b_texture_no;
	int		b_texture_so;
	int		b_texture_we;
	int		b_texture_ea;
	int		b_texture_s;
	char	**map;
	int		fd_map;
	int		size_map_x_y[2];
	int		b_line_before;
	int		msg_error;
}		t_info_game;

typedef struct	s_player
{
	float		pos_x; //Position x du joueur
	float		pos_y; //Position y du joueur
	float		dir;
	// float		angle; //Angle de rotation du joueur
	// int			b_walk_dir;
	// int			b_angle_dir; // Angle de direction
	// int			b_turn_dir;
}				t_player;

typedef struct  s_data
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct	s_world
{
	void		*mlx;
	void		*win;
	float		dist_to_projection_plane; // distance entre la caméra et l'écran de projection
	int			key_a;
	int			key_d;
	int			key_up;
	int			key_down;
	int			key_left_rot;
	int			key_right_rot;
}				t_world;

typedef struct	s_rays
{
	int			map_x; // coordonée x du carré dans lequel est pos
	int			map_y; // coordonnée y du carré dans lequel est pos
	float		camera_x; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	float		ray_dir_x; //calcul de direction x du rayon
	float		ray_dir_y; //calcul de direction y du rayon
	float		dir_x; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	float		dir_y; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	float		plan_x; //Vecteur du plan x
	float		plan_y; //Vecteur du plan y
	float		side_dist_x; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	float		side_dist_y; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	float		delta_dist_x; //distance que rayon parcours entre chaque point d'intersection vertical
	float		delta_dist_y; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int			step_x; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int			step_y; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int			side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	float		perp_wall_dist; // distance du joueur au mur
	int			line_height; //hauteur de la ligne a dessiner
	int			draw_start; //position de debut ou il faut dessiner
	int			draw_end; //position de fin ou il faut dessiner
}				t_rays;

typedef struct s_textures
{
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_lenght;
	int				endian;
	int				width;
	int				height;
	int				texture_x;
	int				texture_y;
	float			wall_x;
	unsigned int	*tex;
}				t_textures;

typedef struct s_game
{
	t_world		world;
	t_info_game	info_game;
	t_player	player;
	t_data		data;
	t_rays		rays;
	t_textures	north_text;
	t_textures	south_text;
	t_textures	west_text;
	t_textures	east_text;
	t_textures	sprites_text;
}				t_game;

int		ft_check_file(char *path);
int		ft_check_extension(char *path, char *extension);
int		ft_init_parse(t_info_game *info_game, char *path);
void	ft_init_info_game(t_info_game *info_game);
void	ft_init_boolean_settings(t_info_game *info_game);
int		ft_parse_gnl(t_info_game *info_game, char *path);
int		ft_parse_line(t_info_game *info_game, char *line);
int		ft_parse_res(t_info_game *info_game, char *line, int i);
int		ft_isdigit_atoi(char *line, int *i);
int		ft_jump_space(char *line, int i);
int		ft_parse_color(t_info_game *info_game, char *line, int i);
int		ft_parse_f_or_c(t_info_game *info_game, char *line, int i);
int		ft_verif_f_or_c(t_info_game *info_game);
int		ft_check_line(t_info_game *info_game, char *line, int i);
int		ft_parse_identifiant(t_info_game *info_game, char *line, int i);
int		ft_parse_textures(t_info_game *info_game, char *line, int i);
int		ft_check_textures(char *texture_path);
char	*ft_recover_texture(t_info_game *info_game, char *line, int i, int j);
int		ft_verif_settings(t_info_game *info_game);

/** Parse map **/
int		ft_parse_map(t_info_game *info_game, char *line);
int		ft_recover_size_map(t_info_game *info_game, char *line, int i);
int		ft_parse_line_size(char *line, int *x_max, int *y_max);
int		ft_check_line_map(t_info_game *info_game, char *line, int i);
int		ft_alloc_map(t_info_game *info_game);
int		ft_recover_map(t_info_game *info_game, char *path);
int		ft_recover_line(t_info_game *info_game, char *line,
			int start_map, int *y);
int		ft_recover_first_line(t_info_game *info_game, char *line);
int		ft_recover_all_lines(t_info_game *info_game, char *line, int *y);
int		ft_recover_player(t_info_game *info_game, char c, int x, int *y);
int		ft_verif_map(t_info_game *info_game);
int		ft_check_space_map(char **map);
int		ft_replace_space_by_wall(char **map, int x, int y);
int		ft_check_column(char **map);
int		ft_check_up_is_wall(char **map, int x, int y);
int		ft_check_down_is_wall(char **map, int x, int y);

/** Start game **/
int		game_start(t_game *game);

/** Utils **/
void	ft_free_tab2d(char **str);
int		ft_msg_errors(t_info_game *info_game, char *str);
int		ft_error(char *str);
void	ft_check_res_size(t_game *game);
float	ft_degree_to_radian(float degree);

void	ft_init_struct(t_game *game);
int		ft_init_game(t_game *game);

/** mlx utils **/
int		my_mlx_new_image(void *mlx_ptr, t_data *data, int res_x, int res_y);
void	my_mlx_pixel_put(t_game *game, int x, int y, int color);
int		ft_load_textures(t_game *game, t_textures *text, char *path);
int		ft_convert_to_trgb(int t, int r, int g, int b);

/** gestion des évènements **/
void	ft_events_managements(t_game *game);
//int		ft_press_hook(int keycode, t_player *player);

/** Raycasting **/
void	ft_plan_init(t_game *game);
void	ft_player_init_dir(t_game *game);
int		ft_raycasting(t_game *game);
void	ft_size_wall(t_game *game);
void	ft_print_textures(t_game *game, int x, int draw_start, int draw_end);
int		wich_plan(t_game *game);

/** Mouvements et déplacements du joueur **/
void	ft_player_move(t_game *game);

/** Fonctions free **/
void	ft_free_all(t_info_game *info_game);
void	ft_free_exit(t_game *game);

#endif
