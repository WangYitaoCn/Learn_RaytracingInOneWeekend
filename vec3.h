//
// Created by YITAO WANG on 2024/07/16.
//

#ifndef VEC3_H
#define VEC3_H



class vec3 {
public:
    // 三个元素
    double e[3];
    // 构造函数
    vec3() : e{0,0,0} {}
    // 构造函数
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // 重载运算符
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    // 只读版本
    double operator[](int i) const { return e[i]; }
    // 读写版本
    double& operator[](int i) { return e[i]; }

};



#endif //VEC3_H
