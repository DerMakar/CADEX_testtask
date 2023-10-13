#define _USE_MATH_DEFINES 

#include "include/TaskSolver.h"


int main() {
	int random_curves_count = 0;
	std::cout << "Enter positive number of curves to create - ";
	std::cin >> random_curves_count;
	TaskSolver solver(random_curves_count);
	std::cout << "There're " << solver.Size() << " curves created"
		<< std::endl
		<< "Print curves with t = PI/4? (1 - yes, 0 - no) ";
	std::cin >> random_curves_count;
	switch (random_curves_count) {
	case 1:
		solver.Print(M_PI/4);
		break;
	case 0:
		break;
	default:
		std::cout << "Unvalid option. Continuing whithout printing.";
		break;
	}
		std::cout << "and there're " << solver.GetSortedCircles().size() << " 3Dcircle curves in collection"
		<< std::endl
		<< "with " << solver.GetAllCircleRadiis() << " summary radii"
			<< std::endl;
	
}