#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"


color ray_color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main() {

    auto aspect_ratio = 16.0 / 9.0;

    // Image
    int image_width = 400;
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = (image_height < 1)? 1 : image_height;



    //Camera
    //相机到视口的距离
    auto focal_length = 1.0;
    //viewport width and height
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width) / image_height);
    auto camera_center = point(0, 0, 0);




    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    // 最终成像的宽度 或者说是视口的宽度
    auto viewport_u = vec3(viewport_width, 0, 0);
    // 反转y轴 使得y轴正方向向下 从而使得y轴正方向与图片的y轴正方向一致
    // 最终成像的高度 或者说是视口的高度
    auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.

    auto pixel_delta_u = viewport_u / image_width;
    auto pixel_delta_v = viewport_v / image_height;

    // Calculate the location of the upper left pixel.
    // 通过相机的位置和视口的宽度和高度 以及像素的宽度和高度 计算出左上角像素的位置
    auto viewport_upper_left = camera_center
                             - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    // 通过左上角像素的位置和像素的宽度和高度 计算出像素的中心位置
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);





    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    //左上 -> 右下 遍历像素
    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << image_height - j << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {
            // pixel position
            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            // ray direction
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\nDone.\n";
}