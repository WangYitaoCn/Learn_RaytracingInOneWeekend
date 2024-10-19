//
// Created by YITAO WANG on 2024/07/17.
//

#ifndef COLOR_H
#define COLOR_H
#include "vec3.h"
#include <iostream>

using color = vec3; // RGB color

void write_color(std::ostream &out, color pixel_color);

#endif //COLOR_H
