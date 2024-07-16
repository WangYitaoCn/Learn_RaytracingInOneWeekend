#include <iostream>

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";


    //左上 -> 右下 遍历像素
    for (int j = 0; j < image_height; j++) {
        // add progress indicator
        // 使用它可以使日志记录的代码更加规范和一致，便于维护和移植。
        // std::cout：标准输出流，通常用于向用户显示普通的信息。输出是有缓冲的。
        // std::cerr：标准错误流，通常用于输出错误信息。输出是无缓冲的，即每次输出操作都会立即写出。
        // std::clog：标准日志流，通常用于输出日志信息。输出是有缓冲的。

        std::clog << "\rScanlines remaining: " << image_height - j << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) {

            // r g  跟 像素位置有关
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    std::clog << "\nDone.\n";
}