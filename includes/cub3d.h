#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include "../libft/libft.h"
# include "mlx.h"

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

typedef struct	s_info_game
{
	int 		fd;
	int 		line_index;
	int 		x;
	int 		y;
	int 		characters_start_x_y[2];
	char 		character_pos;
	int 		win_res[2];
	int 		color_f[3];
	int 		color_c[3];
	char 		parse_char[3];
	char 		*path_textures_s;
	char 		*path_textures_no;
	char 		*path_textures_so;
	char 		*path_textures_we;
	char 		*path_textures_ea;
	int 		b_colors[2];
	int 		b_res;
	int 		b_texture_no;
	int 		b_texture_so;
	int 		b_texture_we;
	int 		b_texture_ea;
	int 		b_texture_s;
	char 		**map;
	int 		fd_map;
	int 		size_map_x_y[2];
	int			b_line_before;
	int			msg_error;
}				t_info_game;

typedef struct	s_player
{
	float		pos_x;
	float		pos_y;
	float		dir;
	float		angle;
	int			b_walk_dir;
	int			b_angle_dir;
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
	float		dist_to_projection_plane;
}				t_world;

typedef struct	s_game
{
	t_world		world;
	t_info_game info_game;
	t_player	player;
}				t_game;

int		ft_check_file(char *path);
int		ft_check_extension(char *path, char *extension);
int		ft_init_parse(char *path);
void	ft_init_info_game(t_info_game *info_game);
void	ft_init_boolean_settings(t_info_game *info_game);
int		ft_parse_gnl(t_info_game info_game, char *path);
int		ft_parse_line(t_info_game *info_game, char *line);
int		ft_parse_res(t_info_game *info_game, char *line, int i);
int		ft_isdigit_atoi(char *line, int *i);
int		ft_jump_space(char *line, int i);
int		ft_parse_color(t_info_game *info_game, char *line, int i);
int		ft_parse_f_or_c(t_info_game *info_game, char *line, int i);
int		ft_verif_f_or_c(t_info_game *info_game);
int		ft_check_line(t_info_game *info_game, char *line, int i);
int		ft_parse_identifiant(t_info_game *info_game, char *line, int i);
int		ft_parse_textures(t_info_game *info_game,  char *line, int i);
int		ft_check_textures(char *texture_path);
char	*ft_recover_texture(t_info_game *info_game, char *line, int i);
int		ft_verif_settings(t_info_game *info_game);

/** Parse map **/
int		ft_parse_map(t_info_game *info_game, char *line);
int		ft_recover_size_map(t_info_game *info_game, char *line, int i);
int		ft_parse_line_size(char *line, int *x_max, int *y_max);
int		ft_check_line_map(t_info_game *info_game, char *line, int i);
int		ft_alloc_map(t_info_game *info_game);
int		ft_recover_map(t_info_game *info_game, char *path);
int		ft_recover_line(t_info_game *info_game, char *line, int start_map, int *y);
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
void	ft_free_tab2d(t_info_game *info_game);
int		ft_msg_errors(t_info_game *info_game, char *str);
int		ft_error(char *str);
void	ft_check_res_size(t_game *game);
float	ft_degree_to_radian(float degree);

#endif
