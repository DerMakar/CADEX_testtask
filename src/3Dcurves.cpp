#include "../include/3Dcurves.h"

using namespace std::literals;

void RadiiError::Write() const {
	std::cerr << "radii "s << radii << " is negative!"s << std::endl;
}

bool operator==(const Point& lhs, const Point& rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

bool operator!=(const Point& lhs, const Point& rhs) {
	return !(lhs == rhs);
}

//Circle
Circle::Circle(double radii){
	try {
		SetRadii(radii);
	}
	catch (const RadiiError& err) {
		err.Write();
	}
}

double Circle::GetRadii() const {
	return radii_;
}

Vector3D Circle::GetPoint(double t) const {
	return Vector3D(std::cos(t) * GetRadii(), std::sin(t) * GetRadii(),
		0.);
}

Vector3D Circle::GetFirstDeriv(double t) const {
	return Vector3D(-std::sin(t) * GetRadii(), std::cos(t) * GetRadii(),
		0.);
}

double Circle::SetRadii(double radii) {
	if (radii <= 0) throw RadiiError(radii);
	radii_ = radii;
	return radii_;
}

std::string_view Circle::GetName() const {
	return "Circle"sv;
}

//Ellipse
Ellipse::Ellipse(double radii_x, double radii_y){
	try {
		SetRadii(radii_x, radii_y);
	}
	catch (const RadiiError& err) {
		err.Write();
	}
}

double Ellipse::GetRadiiX() const {
	return radii_x_;
}

double Ellipse::GetRadiiY() const {
	return radii_y_;
}

Vector3D Ellipse::GetPoint(double t) const {
	return Vector3D(std::cos(t) * GetRadiiX(), std::sin(t) * GetRadiiY(),
		0.);
}

Vector3D Ellipse::GetFirstDeriv(double t) const {
	return Vector3D(-std::sin(t) * GetRadiiX(), std::cos(t) * GetRadiiY(),
		0.);
}

std::string_view Ellipse::GetName() const {
	return "Ellipse"sv;
}

std::pair<double, double> Ellipse::SetRadii(double radii_x, double radii_y) {
	if (radii_x <= 0 || radii_y <= 0) throw RadiiError(radii_x);
	radii_x_ = radii_x;
	radii_y_ = radii_y;
	return { radii_x , radii_y };
}

// Helix
Helix::Helix(double radii, double step)
	: step_(step) {
	try {
		SetRadii(radii);
	}
	catch (const RadiiError& err) {
		err.Write();
	}
}

int Helix::GetStep() const {
	return step_;
}

double Helix::GetRadii() const {
	return radii_;
}

double Helix::SetRadii(double radii) {
	if (radii <= 0) throw RadiiError(radii);
	radii_ = radii;
	return radii_;
}

Vector3D Helix::GetPoint(double t) const {
	Vector3D v (std::cos(t) * GetRadii(), std::sin(t) * GetRadii(),
		0.);
	v.by_z(step_ * (t / (M_PI * 2.)));
	return v;
}

Vector3D Helix::GetFirstDeriv(double t) const {
	Vector3D v (-std::sin(t) * GetRadii(), std::cos(t) * GetRadii(),
		0.);
	v.by_z(step_ / (M_PI * 2.));
	return v;
}

std::string_view Helix::GetName() const {
	return "Helix"sv;
}
