#pragma once

#include <iostream>

class Vector3D {
private:
    double fx;
    double fy;
    double fz;

public:
    Vector3D(double x, double y, double z)
        : fx(x), fy(y), fz(z) {};

    Vector3D(const Vector3D& other) = default;
    Vector3D(Vector3D&& other) = default;

    Vector3D& operator=(const Vector3D& other) = default;
    Vector3D& operator=(Vector3D&& other) = default;

    Vector3D& by_x(double x) noexcept;
    Vector3D& by_y(double y) noexcept;
    Vector3D& by_z(double z) noexcept;
    
    
    bool operator==(const Vector3D& other) {
        return fx == other.fx && fy == other.fy && fz == other.fz;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vector3D& v);
};




