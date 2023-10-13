#include "../include/TaskSolver.h"

size_t TaskSolver::Size() const {
	return curves_.size();
}

void TaskSolver::Print(double t) const {
	using namespace std::literals;
	for (const auto& curve : curves_) {
		std::cout << curve->GetName()
			<< " point: "s << curve->GetPoint(t)
			<< "; FirstDerivative: "s << curve->GetFirstDeriv(t)
			<< std::endl;
	}
}

std::vector<std::shared_ptr <Circle>> TaskSolver::GetSortedCircles() const {
	std::vector<std::shared_ptr <Circle>> circles;
	circles.reserve(curves_.size());
	for (const auto& curve : curves_) {
		std::shared_ptr <Circle> c = std::dynamic_pointer_cast<Circle>(curve);
		if (c) circles.emplace_back(c);
	}
	sort(std::execution::par, circles.begin(), circles.end(), [](const auto& lhs, const auto& rhs) {return lhs->GetRadii() < rhs->GetRadii(); });
	return circles;
}

double TaskSolver::GetAllCircleRadiis() const {
	std::vector<std::shared_ptr<Circle>> circles = GetSortedCircles();
	double radiis = std::transform_reduce(std::execution::par, circles.begin(), circles.end(), 0., std::plus<>{}, [](const auto& c) {return c->GetRadii(); });
	return radiis;
}

void TaskSolver::MakeRandom(int r) {
	std::mt19937 gen(std::random_device{}());

	std::uniform_real_distribution<double> point(0., 100.);
	std::uniform_real_distribution<double> dist(0.1, 42.);
	std::uniform_int_distribution<std::uint16_t> curve(1, 3);

	curves_.reserve(r);

	auto generator = [&](auto&& f)->std::shared_ptr<Curve> {
		switch (f()) {
		case 1:
			return std::make_shared<Circle>(dist(gen));
		case 2:
			return std::make_shared <Ellipse> (dist(gen), dist(gen));
		default:
			return std::make_shared <Helix>(dist(gen), dist(gen));
		}
	};

	std::generate_n(std::back_inserter(curves_),r,
		std::bind(generator, [&]() { return curve(gen); }));
}