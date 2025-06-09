/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   cub3D.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gasroman <gasroman@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/05/14 17:22:23 by gasroman		  #+#	#+#			 */
/*   Updated: 2025/06/09 18:11:44 by gasroman		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
//# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <stddef.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include "color.h"

# ifndef BONUS
#  define BONUS 1
# endif

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define DARK_GREEN 0x004400
# define GRAY 0xAAAAAA
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define SKY_BLUE 0x87CEEB
# define GRASS_GREEN 0x32CD32
# define WALL_BROWN 0x8B4513
# define WALL_RED 0xFF0000
# define WALL_YELLOW 0xFFFF00
# define MINIMAP_PURPLE 0x800080

# define MAP_WIDTH  12  //ancho 10
# define MAP_HEIGHT 17  //alto 15
# define MINI_MAP_WIDTH 60
# define MINI_MAP_HEIGHT 60
# define SCREEN_WIDTH 800 // 800
# define SCREEN_HEIGHT 800 //600
# define WIN_WIDTH 800  // 540
# define WIN_HEIGHT 600  //420
# define MOVE_SPEED 0.0255//0.0125
# define ROTATE_SPEED 0.015//0.015

# define K_W 119
# define K_S 115
# define K_A 97
# define K_D 100
# define K_LEFT 65361
# define K_RIGHT 65363
# define K_ESC 65307
# define K_SPACE 32

# define FOV 60//60

# define PLAYER_RADIUS 0.2

# define VALID_CHARS "NSEW10 D\n"
# define VALID_FOR_CHECK "NSEW0D"

// --- Minimap Config ---
// --- Minimap Config ---
# define MINIMAP_WIDTH 120   // Fixed width of the minimap (MAP_WIDTH * 8)
# define MINIMAP_HEIGHT 120  // Fixed height of the minimap (MAP_HEIGHT * 8)

// --- Minimap Area Config ---
# define MINIMAP_AREA_OFFSET_X 10 // Offset from the left edge of the window
# define MINIMAP_AREA_OFFSET_Y 10 // Offset from the top edge of the window
# define MINIMAP_AREA_WIDTH 140   // Fixed width of the area
# define MINIMAP_AREA_HEIGHT 170  // Fixed height of the area


# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define MAX_LINE_LENGTH 1024

# define DOOR_INTERACTION_DISTANCE 3.0 //1.5
# define DOOR_INTERACTION_DISTANCE_MAP 1 // Distancia de interacción en el mapa

# define ANSI_COLOR_RED	 "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_BLUE	"\x1b[34m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_RESET   "\x1b[0m"

# define DEBUG 1

typedef struct s_keys {
	int w;
	int s;
	int a;
	int d;
	int left;
	int right;
	int esc;
	int space;
	int space_pressed;
} t_keys;

// Estructura para la información de William (el jugador)
typedef struct s_william {
	double x;	   // Posición X
	double y;	   // Posición Y
	double dir_x;	// Vector dirección X
	double dir_y;	// Vector dirección Y
	double plane_x;  // Plano de la cámara X
	double plane_y;  // Plano de la cámara Y
	double  fov;	// Campo de visión (Field of View)
	double  playerangle; // Ángulo del jugador
	int	 turndirection; // Dirección de giro (izquierda o derecha)
	int release_mouse;
	int mouse_x;
	int last_mouse_x;
}   t_william;

// Estructura para la información de las texturas
typedef struct s_texture {
	void	*img_ptr;	   // Imagen cargada con mlx_xpm_file_to_image
	int	 width;		  // Ancho en píxeles (devuelto por mlx)
	int	 height;		 // Alto en píxeles (devuelto por mlx)
	char	*path;		  // Ruta al archivo .xpm
	int	 *data;		  // Buffer de píxeles (obtenido con mlx_get_data_addr)
	int	 bits_per_pixel; // Profundidad de color (normalmente 32)
	int	 line_length;	// Cantidad de bytes por fila
	int	 endian;		 // Orden de bytes (0: little endian, 1: big endian)
} t_texture;


typedef struct s_img
{
	void	*img;
	void	*img_ptr;
	char	*addr;
	int	 bits_per_pixel;
	int	 line_length;
	int	 endian;
	int	 width;
	int	 height;
	int		size_line;

} t_img;


typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_img		*img;
}					t_mlx;


typedef struct s_mouse_bonus
{
	t_william		*william;
	t_mlx			*mlx;
	//t_map_info		*map_info;
	t_texture		*wall;
	//t_img_data		*mini_map;
	t_texture		*shoot_target;
	t_texture		**weapon;
	t_texture		**digit;
	t_texture		*amo;
	int				mouse_pos;

}					t_mouse_bonus;

typedef struct s_minimap
{
	int map_x;
	int map_y;
	int screen_x;
	int screen_y;
	int player_map_x;
	int player_map_y;
	int minimap_cells_x;
	int minimap_cells_y;
	int offset_x;
	int offset_y;
	int cell_size;
	int start_x;
	int start_y;
	int william_center_x;
	int william_center_y;
	int radius;
	int			pixel_x;
	int			pixel_y;
	int			color;
	char		cell;
	int			i;
	int			j;
	double		fov_half;
} t_minimap;

typedef struct s_wall_info
{
	char wall_type;
	int side;
	double raydir_x;
	double raydir_y;
}t_wall_info;

typedef struct s_render
{
	int total_pixels;
	double fov_length;
	t_wall_info wall_info;
	double camera_x;
	double raydir_x;
	double raydir_y;
	int map_x;
	int map_y;
	double deltadist_x;
	double deltadist_y;
	double sidedist_x;
	double sidedist_y;
	int step_x;
	int step_y;
	int hit;
	int side;
	double perpwalldist;
	int lineheight;
	int drawstart;
	int drawend;
	double wall_x;
	int tex_x;
	t_texture *tex;
	int y;
	int d;
	int tex_y;
	int color;
	int x;
	int minimap_area_width;
	int minimap_area_height;
	int minimap_offset_x;
	int minimap_offset_y;
	double minimap_scale_x;
	double minimap_scale_y;
	double minimap_scale;
} t_render;

typedef struct s_rhand
{
	int x;
	int y;
	t_texture current_hand;
	int *data;
	int width;
	int height;
	int line_len;
	unsigned char alpha;
	int color;
	int draw_x;
	int draw_y;
} t_rhand;

// Estructura principal del juego
typedef struct s_game {
	void	*mlx_ptr;	   // Puntero a la instancia de MiniLibX
	void	*win_ptr;	   // Puntero a la ventana
	void	*img_ptr;	   // Puntero a la imagen a renderizar (general, para la escena principal)
	int	 *img_data;	  // Datos de la imagen
	char	*addr;
	t_img   *img_ground; // Puntero a la imagen del fondo
	t_william william;	 // Información de William (el jugador)
	int		 floor_color;	// Color del suelo
	int		 ceiling_color;  // Color del techo
	char		**map;		 // Puntero al mapa
	void	*minimap_img_ptr; // Puntero a la imagen del minimapa (añadido)
	int	 *minimap_img_data;
	int	 minimap_bpp;
	int	 minimap_line_length;
	int	 minimap_endian;
	int	 bits_per_pixel; // Bits per pixel
	int	 line_length;	// Tamaño de la línea en bytes
	int	 endian;		 // Endianness de la imagen
	t_texture   *textures; // Array de texturas
	void *hands_img_ptr[2];		// Arreglo para las dos imágenes de las manos
	int *hands_data[2];			// Arreglo para los datos de las manos (pixeles)
	int hands_width;			   // Ancho de las imágenes de las manos
	int hands_height;			  // Alto de las imágenes de las manos
	int hands_bits_per_pixel;	  // Bits por píxel de las imágenes de las manos
	int hands_line_length;		// Longitud de la línea de las imágenes de las manos
	int hands_endian;			 // Endian de las imágenes de las manos
	int current_hand_frame;	   // Frame actual de la animación (0 o 1)
	int hand_animation_timer;	 // Temporizador para cambiar el fotograma
	int hands_x;				  // Posición X de las manos
	int hands_y;				  // Posición Y de las manos
	t_keys keys;
	double last_mouse_x;
	double mouse_sensitivity;
	int mouse_in_border;
	int last_turn_direction;
	t_mouse_bonus *mouse_data;
	void *doors_img_ptr[2];		// Arreglo para las dos imágenes de las manos
	int *doors_data[2];			// Arreglo para los datos de las manos (pixeles)
	int doors_width;			   // Ancho de las imágenes de las manos
	int doors_height;			  // Alto de las imágenes de las manos
	int doors_bits_per_pixel;	  // Bits por píxel de las imágenes de las manos
	int doors_line_length;		// Longitud de la línea de las imágenes de las manos
	int doors_endian;			 // Endian de las imágenes de las manos
	int current_door_frame;	   // Frame actual de la animación (0 o 1)
	int door_animation_timer;	 // Temporizador para cambiar el fotograma
	int doors_x;				  // Posición X de las manos
	int doors_y;	 
	int door_open; 
	t_texture *hands;	 
	t_texture   *hud; 
	t_texture   *door_texture;		// Arreglo para las dos imágenes de las manos  
	int hud_x;				  // Posición X de las manos
	int hud_y;				  // Posición Y de las manos   
	bool	hud_message;
	bool	hud_message2;
	struct timeval hud_timer;  
	t_minimap minimap; // Estructura para el minimapa 
	t_texture   gameover;
	char	**worldmap;
	t_data *data;
	char **map2;
}   t_game;


typedef struct s_cone
{
	double	angle;
	double	dir_x;
	double	dir_y;
	int		player_x;
	int		player_y;
	int		i;
	int		x;
	int		y;
}   t_cone;

typedef struct s_coneaux
{   double		step;
	double		length;
	double		i;
	int			current_map_x;
	int			current_map_y;
}   t_coneaux;

typedef struct s_bounds
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_bounds;

typedef struct s_player_map_state
{
	int		old_x;
	int		old_y;
	char	old_cell;
	int							new_x;
	int							new_y;
	char						player_char;
}	t_player_map_state;

// --- Funciones ---
//int init_game(t_game *game);
int load_textures(t_game *game);
int render(t_game *game);
int update(t_game *game);
int handle_input(int keycode, t_game *game);
int game_loop(t_game *game);
//int clean_exit(t_game *game, char *msg);
void draw_minimap(t_game *game);
void my_mlx_pixel_put(t_game *game, int x, int y, int color);
void drawbackground(t_game *game);
int load_hands_images(t_game *game);
void	remove_black_background(t_game *game);


//draw.c
void	draw_background(t_game *game);
void my_mlx_pixel_put(t_game *game, int x, int y, int color);

//int.c
int		init_game(t_game *game);
int	init_mlx(t_game *game);
int	init_images(t_game *game);
int	init_minimap(t_game *game);
int	init_map(t_game *game);
int	init_player(t_game *game);
int	init_textures_and_hands(t_game *game);

//utils.c
char	*ft_strchr(const char *s, int c);
void print_player_position(t_game *game);

//load.c
int	load_hands_images(t_game *game);
int load_textures(t_game *game);
int	load_door_images(t_game *game);
int	load_gameover(t_game *game);

//minimap.c
void draw_minimap(t_game *game);

//mouse.c
//int	handle_mouse(int x, int y, t_mouse_bonus *data);
int handle_mouse(int x, int y, void *param);
int	mouse_press(int key, int x, int y, t_mouse_bonus *data);
int	mouse_release(int key, int x, int y, t_mouse_bonus *data);
void center_mouse(t_game *game);


int load_textures_hud(t_game *game);


//mini_william.c
void	draw_cone_line_centered(t_game *game, double angle_offset, int center_x, int center_y);
void	draw_cone_line(t_game *game, double angle_offset, int center_x, int center_y);
void	ini_minimap(t_game *game);
void	calculate_minimap_coords(t_minimap *mini);
void	set_minimap_cell_color(t_game *game, t_minimap *mini);

//move.c
bool is_player_moving(t_game *game);
bool is_valid_move(t_game *game, double new_x, double new_y);

//render_aux.c
t_texture *get_texture_for_wall(t_game *game, t_wall_info wall_info);
void init_render_vars(t_game *game, t_render *render);
void calculate_ray_vars(t_game *game, t_render *render);
void perform_ray_casting(t_game *game, t_render *render);
void calculate_wall_properties(t_game *game, t_render *render);

//render_aux_v2.c
void draw_texture_on_wall(t_game *game, t_render *render);
void init_minimap_vars(t_render *render, t_game *game);
void render_walls(t_game *game, t_render *render);
void clear_minimap_area(t_game *game, t_render *render);
void draw_scaled_minimap(t_game *game, t_render *render);

//render_aux_v3.c
void render_minimap(t_game *game, t_render *render);
void init_ray_direction(t_game *game, t_render *render);

//render.c
int render(t_game *game);
void render_hands(t_game *game);
int update_and_render(t_game *game);

//frees.c
//int clean_exit(t_game *game, char *msg);
int clean_exit(void *param, char *msg);

//render_hud.c
void render_hud(t_game *game);
void render_m1(t_game *game);
void render_m2(t_game *game);
void render_m3(t_game *game);
void	render_m4(t_game *game);

//key.c
int key_press(int keycode, t_game *game);
int key_release(int keycode, t_game *game);


//update.c
void update_player(t_game *game);
void update_hands_animation(t_game *game);


void convert_od_to_1_while(char map[MAP_HEIGHT][MAP_WIDTH + 1]);

void initialize_all_structures_while(t_game *game);

void	init_render_str(t_render *render);

//void convert_od_to_1(char map[MAP_HEIGHT][MAP_WIDTH + 1]);

void init_game3(t_game *game);
void initialize_game_struct(t_game *game);

//init_game_2.c
void init_main_pointers(t_game *game);
void init_minimap_data(t_game *game);
void init_img_render_data(t_game *game);
void init_hands_data(t_game *game);

//inti_render.c
void init_render_str(t_render *render);

//key_release.c
int key_release(int keycode, t_game *game);

//move_william.c
void move_player(t_game *game);

//update_hands.c
void update_hands_animation(t_game *game);
void	update_player_state(t_player_map_state *state, t_game *game);


void	allocate_worldmap(t_game *game);
void	traspase_worldmap2_to_worldmap(t_game *game, char worldmap2[MAP_HEIGHT][MAP_WIDTH +1]);
void	assign_hardcoded_worldmap(t_game *game);
int		init_worldmap(t_game *game);

void	toggle_magic_wall(t_game *game, int x, int y);

typedef struct s_data
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
	char	**map;
}	t_data;

int		parser_data(int fd, t_data *data);
int		data_sorter(char **split, int *stored, t_data *data);
char	**process_line(char *line);
char	**ft_split_set(char const *s, char c1, char c2);
void	free_split(char **arr);
void	free_data(t_data *data);
int		split_size(char **split);
int		store_texture(char **split, t_data *data);
int		texture_format(char *filename);
int		data_format(char *filename);
int		value_checks(char **color);
int		store_color(char **split, t_data *data);
int		is_texture(char **split);
int		is_color(char **split);
char	**ft_double_realloc(char **ptr, size_t new_size);
int		count_map(t_data *data, char *line);
int		parser_map(t_data *data);
int		line_checker(t_data *data);
int		is_surrounded(t_data *data, int i, int j);
int		player_count(char c);

void print_worldmap_debug(t_game *game);

int validate_map_is_closed(t_game *game);

void flood_fill_recursive(char **map_copy, int y, int x, t_data *data, int *is_leaking);
void cleanup_core_resources(t_game *game);

void free_char_array(char **array);

#endif