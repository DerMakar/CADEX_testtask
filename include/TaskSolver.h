#pragma once

#include <algorithm>
#include <numeric>
#include <execution>
#include <functional>
#include <random>
#include <iostream>
#include <vector>
#include "3Dcurves.h"

class TaskSolver {
public:
	TaskSolver() = default;
	
	TaskSolver(int i) {
		MakeRandom(i);
	}

	void Print(double t) const;

	std::vector<std::shared_ptr<Circle>> GetSortedCircles() const;

	double GetAllCircleRadiis() const;

	size_t Size() const;
private:
	std::vector<std::shared_ptr<Curve>> curves_;

	void MakeRandom(int r);
};