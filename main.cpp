#include <iostream>
#include "vec3.h"
#include "color.h"
#include "ray.h"


// 检查光线是否与球体相交
bool hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = dot(r.direction(), r.direction());
    auto b = 2.0 * dot(oc, r.direction());
    auto c = dot(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}

color ray_color(const ray& r) {
    if (hit_sphere(point3(0,0,-1), 0.5, r))
        return color(1, 0, 0);
    // liner interpolation of the color　线性插值
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5*(unit_direction.y() + 1.0);
    // blend the white and blue color based on the y coordinate of the ray direction
    //blendvaue = (1-a)*startvalue + a * endvalue
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
}

int main() {
    auto aspect_ratio = 16.0 / 9.0;

    // Image
    constexpr int image_width = 400;
    int image_height = static_cast<int>(image_width / aspect_ratio);
    image_height = image_height < 1? 1 : image_height;



    //Camera
    //相机到视口的距离
    constexpr auto focal_length = 1.0;
    //viewport width and height
    constexpr auto viewport_height = 2.0;
    const auto viewport_width = viewport_height * (static_cast<double>(image_width) / image_height);
    const auto camera_center = point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    // 最终成像的宽度 或者说是视口的宽度
    const auto viewport_u = vec3(viewport_width, 0, 0);
    // 打出来的像素是左上到右下 y 的方向是向下的
    // 3d世界里 y的方向是向上的
    // 反转y轴 使得y轴正方向向下 从而使得y轴正方向与图片的y轴正方向一致
    // 最终成像的高度 或者说是视口的高度
    const auto viewport_v = vec3(0, -viewport_height, 0);

    // Calculate the horizontal and vertical delta vec  tors from pixel to pixel.
    // 计算间距
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
        std::clog << "\rScanlines remaining: " << image_height - j << ' ' <<"\n" << std::flush;
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