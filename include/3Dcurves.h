#pragma once
#define _USE_MATH_DEFINES 

#include <vector>
#include <iostream>
#include <utility>
#include <cmath>
#include "Vector3D.h"

class CurveError : public std::exception {
public:
	virtual void Write() const = 0;
};

class RadiiError : public CurveError {
public:
	RadiiError(double r) : radii(r){}
	void Write() const override;
private:
	double radii;
};

struct Point {
	Point() = default;
	Point(double x, double y, double z)
		: x(x)
		, y(y)
		, z(z) {
	}
	double x = 0;
	double y = 0;
	double z = 0;
};

bool operator==(const Point& lhs, const Point& rhs);

bool operator!=(const Point& lhs, const Point& rhs);

class Curve {
public:
	virtual Vector3D GetPoint(double t) const = 0;
	virtual Vector3D GetFirstDeriv(double t) const = 0;
	virtual std::string_view GetName() const = 0;
	virtual ~Curve() = default;
};

class Circle final : public Curve {
public:
	Circle() = default;
	Circle(double radii);
	Circle(const Circle& other) = default;
	Circle(Circle&& other) = default;

	Circle& operator =(const Circle& other) = delete;
	Circle& operator =(Circle&& other) = delete;
	
	double GetRadii() const;

	Vector3D GetPoint(double t) const override;

	Vector3D GetFirstDeriv(double t) const override;

	std::string_view GetName() const override;
	
private:
	double radii_ = 1;
	
	double SetRadii(double radii);
};

class Ellipse final : public Curve {
public:
	Ellipse() = default;
	Ellipse(double radii_x, double radii_y);
	Ellipse(const Ellipse& other) = default;
	Ellipse(Ellipse&& other) = default;

	Ellipse& operator=(const Ellipse& other) = delete;
	Ellipse& operator=(Ellipse&& other) = delete;

	double GetRadiiX() const;

	double GetRadiiY() const;

	Vector3D GetPoint(double t) const override;

	Vector3D GetFirstDeriv(double t) const override;

	std::string_view GetName() const override;

private:
	double radii_x_ = 1;
	double radii_y_ = 2;

	std::pair<double, double> SetRadii(double radii_x, double radii_y);
};

class Helix final : public Curve {
public:
	Helix() = default;
	Helix(double radii, double step);
	Helix(const Helix& other) = default;
	Helix(Helix&& other) = default;

	Helix& operator= (const Helix& other) = delete;
	Helix& operator= (Helix&& other) = delete;

	double GetRadii() const;

	int GetStep() const;

	Vector3D GetPoint(double t) const override;

	Vector3D GetFirstDeriv(double t) const override;

	std::string_view GetName() const override;

private:
	double radii_ = 1;
	double step_ = 1;

	double SetRadii(double radii);
};
