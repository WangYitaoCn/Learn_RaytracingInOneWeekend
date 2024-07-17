//
// Created by YITAO WANG on 2024/07/17.
//

#ifndef RAY_H
#define RAY_H
#include "vec3.h"


class ray {
    public:
        // 构造函数
        ray() {}
        // 构造函数
        ray(const point& origin, const vec3& direction)
            : orig(origin), dir(direction)
        {}

        // 获取射线的原点
        point origin() const  { return orig; }
        // 获取射线的方向
        vec3 direction() const { return dir; }

        // 计算射线上的点
        point at(double t) const {
            return orig + t*dir;
        }
    private:
        point orig;
        vec3 dir;

};



#endif //RAY_H
