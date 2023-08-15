/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:36:12 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/15 18:24:08 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void start_mlx(t_cub3d *game){
//     game->mlx = mlx_init();
//     game->img.window = mlx_new_window(game->mlx, 800, 600, "Cub3D");
//     int i = 0;
//     int j = 0;
//     // while(i < 300){
//     //     j = 0;
//     //     while(j < 400)
//     //     {
//     //         mlx_pixel_put(game->mlx, game->img.window, i, j, 0xFF0000); // Kırmızı piksel
//     //         j++;
//     //     }
//     //     i++;  
//     // }
//     img_ptr = mlx_new_image(game->mlx, 800, 600);
//     img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
//                 mlx_xpm_to_image(game->mlx, game->north.path, 64, 64);
//     mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);



//     start_img(game);
// }


void start_img(t_cub3d *game){
    /*
       `mlx_get_data_addr` fonksiyonu, MiniLibX (bir grafik kütüphanesi) içinde bulunan bir fonksiyondur ve bir görüntünün (image) piksel verilerine erişim sağlamak için kullanılır. Bu fonksiyonun parametreleri şu şekildedir:
        1. `image` (void pointer): Bu parametre, işlem yapmak istediğiniz görüntünün işaretçisini (pointer) temsil eder. Görüntü, çoğunlukla bellekte bir görüntü yüzeyini temsil eden bir dizi piksel değeri olarak saklanır.
        2. `bpp` (int pointer): Bu parametre, her pikselin kaç bitlik (bit per pixel) bir renk kanalına sahip olduğunu belirtir. Bu değer, her pikselde kırmızı, yeşil ve mavi renk bileşenlerinin kaçar bit olduğunu gösterir. Fonksiyon bu değeri doldurarak geri döner.
        3. `sizeline` (int pointer): Bu parametre, görüntünün her satırının bellekte kaç bayt yer kapladığını belirtir. Bu, görüntünün bir satırını temsil eden verilerin bellekteki toplam boyutunu ifade eder. Fonksiyon bu değeri doldurarak geri döner.
        4. `endian` (int pointer): Bu parametre, görüntünün bellekte nasıl saklandığını (endianness) belirtir. Büyük-endian (big-endian) veya küçük-endian (little-endian) olabilir. Endianness, baytların bellekte sırasını ifade eder. Fonksiyon bu değeri doldurarak geri döner.
        Bu fonksiyon, görüntü verilerine direkt olarak erişmek için gerekli hesaplamaları yapar ve `image` işaretçisinin gösterdiği bellek bölgesinin üzerinden geçer. Bu parametreler sayesinde, görüntünün piksel verilerini okumak, yazmak veya manipüle etmek için gerekli olan bilgileri elde edebilirsiniz. 
    */
    int bpp;
    int sizeline;
    int endian;

    game->img.image = mlx_new_image(game->mlx, 800, 600);
    game->img.data = mlx_get_data_addr(game->img.image, &bpp, &sizeline, &endian);
    game->img.bpp = bpp;
    game->img.sizeline = sizeline;
    game->img.endian = endian;
}
