#include "cub3d.h"

int main(int ac, char **av){
    t_cub3d *game;

    if(ac == 2){
        game = malloc(sizeof(t_cub3d));
        start_cub3d(game);
        start_map(game, av[1]);
        //start_mlx(game);
        /*
            mlx_hook(vals.img.win, 2, 0, key_press, &vals);
            Bu satır, kullanıcının klavyeden tuşa bastığında tetiklenecek bir olayı (event) tanımlar. vals.img.win pencerenin kimliğini belirtir. Burada 2, klavye tuşuna basılma olayını temsil eder. key_press işlevi, kullanıcının klavyeden bir tuşa bastığında çağrılacak işlevi temsil eder. &vals ise işlevin parametresi olarak iletilir.
            mlx_hook(vals.img.win, 3, 0, key_release, &vals);
            Bu satır, kullanıcının klavyeden tuşu bıraktığında tetiklenecek bir olayı tanımlar. Benzer şekilde, key_release işlevi, klavyeden tuş bırakma olayı için çağrılacak işlevi temsil eder.
            mlx_hook(vals.img.win, 17, 1L << 2, red_x_close, &vals);
            Bu satır, pencerenin kapatılma olayını tanımlar. 17, pencerenin kapatılma olayını temsil eder ve red_x_close işlevi, pencerenin kapatılması olayı için çağrılacak işlevi temsil eder.
            mlx_loop_hook(vals.mlx, &ft_loop, &vals);
            Bu satır, bir döngü işleminin sürekli olarak çalışmasını sağlar. Burada vals.mlx MiniLibX bağlamını temsil eder ve ft_loop işlevi, döngü içinde sürekli olarak çağrılacak işlevi temsil eder.
            mlx_hook(vals.img.win, 2, 0, key_press, &vals);
            mlx_hook(vals.img.win, 3, 0, key_release, &vals);
            mlx_hook(vals.img.win, 17, 1L << 2, red_x_close, &vals);
            mlx_loop_hook(vals.mlx, &ft_loop, &vals);
        */
        //mlx_loop(game->mlx);
    }
    else{
        ultimate_print("number of erroneous parameters", 'r', game);
        exit(1);
    }
}

void start_cub3d(t_cub3d *game){
    game->mlx = NULL;
    game->map = NULL;
    game->c_map = NULL;
    game->x_map = NULL;
    game->north.path = NULL;
    game->south.path = NULL;
    game->east.path = NULL;
    game->west.path = NULL;
    game->north.use = 0;
    game->south.use = 0;
    game->east.use = 0;
    game->west.use = 0;
    game->floor.use = 0;
    game->sky.use = 0;
}
void map_write(t_cub3d *game){
    printf("%d %d %d\n", game->floor.r, game->floor.g, game->floor.b);
    printf("%d %d %d\n", game->sky.r, game->sky.g, game->sky.b);
    printf("%s\n", game->north.path);
    printf("%s\n", game->south.path);
    printf("%s\n", game->west.path);
    printf("%s\n", game->east.path);
}
