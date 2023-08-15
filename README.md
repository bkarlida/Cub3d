# Cub3D 

Bu proje, basit bir 3D oyun motoru yapmayı amaçlar. Bu projede, raycasting tekniği kullanılarak basit bir labirent görüntüsü 3D olarak görüntülenir.

## Proje sahipleri
Eren Erdoğan , Burak Karlıdağ
## Proje Açıklaması

- "cub3D" projesi, raycasting tekniğiyle 3D grafikler oluşturarak bir labirentin görüntüsünü sağlar.
- Labirent haritası bir `.cub` dosyasından okunur. Bu dosya, harita yapısı, renkler ve dokular gibi bilgileri içerir.
- Oyuncu, labirentte ilerlerken duvarları ve engelleri görebilir.
- Proje, C dilinde ve MiniLibX kütüphanesi ile gerçekleştirilir.

## Nasıl Çalışır?

1. **Başlatma:** Projeyi derledikten sonra, `./cub3D map.cub` komutuyla programı başlatabilirsiniz.

2. **Map Dosyası:** Bir `.cub` dosyası vererek harita ve diğer ayarları yapılandırabilirsiniz.

3. **Kontroller:** Oyunu çalıştırdığınızda WASD tuşları ile ilerleyebilir, fareyi hareket ettirerek kamerayı döndürebilirsiniz.

4. **Labirent Görüntüsü:** Labirent duvarları ve yüzeyleri 3D görünümde görüntülenir. Oyuncu etrafta dolaşırken labirenti keşfedebilir.

## Ayağa Kaldırma Adımları

1. Projeyi indirin.

2. İndirdiğiniz kaynak kodları bir dizine çıkarın.

3. Terminale gidin ve projenin ana dizinine gidin:

    ```bash
    cd /path/to/cub3d
    ```

4. Projeyi derlemek için aşağıdaki komutları kullanabilirsiniz:

    ```bash
    make
    ```

    Bu komut, projeyi derleyecek ve "cub3D" adlı bir yürütülebilir dosya oluşturacaktır.

5. Oyunu belirli bir `.cub` harita dosyası ile çalıştırmak için aşağıdaki komutu kullanabilirsiniz:

    ```bash
    ./cub3D [map.cub]
    ```

    `map.cub` yerine oynamak istediğiniz `.cub` dosyasını belirtin.

6. Projeyi temizlemek için aşağıdaki komutu kullanabilirsiniz:

    ```bash
    make clean
    ```

7. Projeyi sıfırlamak için aşağıdaki komutu kullanabilirsiniz:

    ```bash
    make fclean
    ```

Bu adımları izleyerek "cub3D" projesini derleyebilir ve oynayabilirsiniz.
