#include "../include/Vector3D.h"

Vector3D& Vector3D::by_x(double x) noexcept {
	fx = x;
	return *this;
}

Vector3D& Vector3D::by_y(double y) noexcept {
	fy = y;
	return *this;
}

Vector3D& Vector3D::by_z(double z) noexcept {
	fz = z;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& v) {
	using namespace std::literals;
	return out << "{"s << v.fx << ", "s << v.fy << ", "s << v.fz << "}"s;
}

