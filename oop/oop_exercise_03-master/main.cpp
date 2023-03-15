#include <iostream>
#include "figure.h"
#include "rhombus.h"
#include "trapezoid.h"
#include "rectangle.h"
#include <vector>
#include <string>

//                                   2
//enter for trapezoid 2 3  rhombus 1   3   rectangle 2 3
//                    1 4            4               1 4

void read_figt(std::vector<Figure *>& fig)
{
	int figt;
	Figure *f = nullptr;

	std::cout << "Fig types: 1 - trapezoid; 2 - rhombus; 3 - rectangle\n";
	std::cin >> figt;
	switch (figt) {
	case 1:
		try {
			f = new Trapezoid(std::cin);
		}
		catch (std::logic_error& err) {
			std::cout << err.what() << std::endl;
			break;
		}
	
		break;
	case 2:
		try {
			f = new Rhombus(std::cin);
		}
		catch (std::logic_error& err) {
			std::cout << err.what() << std::endl;
			break;
		}
		
		break;
	case 3:
		try {
			f = new Rectangle(std::cin);
		}
		catch (std::logic_error& err) {
			std::cout << err.what() << std::endl;
			break;
		}
		
		break;
	default:
		std::cout << "Wrong. Try 1 - trapezoid, 2 - rhombus or 3 - rectangle\n";
	}
	fig.push_back(dynamic_cast<Figure*>(f));
}


int main() {
	unsigned int index;
	double Tarea = 0;
	std::string operation;
	std::vector<Figure*> fig;
	std::cout << "Operations: add / delete / out / quit\n";

	while (std::cin >> operation) {
		if (operation == "add") {
			read_figt(fig);
		}
		else if (operation == "delete") {
			std::cin >> index;
			delete fig[index];
			for (; index < fig.size() - 1; ++index) {
				fig[index] = fig[index + 1];
			}
			fig.pop_back();
		}
		else if (operation == "out") {
			Tarea = 0;
			for (unsigned int i = 0; i < fig.size(); i++) {
				std::cout << i << ":\n";
				std::cout << "Area: " << fig[i]->area() << std::endl;
				std::cout << "Center: " << fig[i]->center() << std::endl;
				std::cout << "Coordinates: ";
				fig[i]->print(std::cout);
				std::cout << std::endl;
				Tarea += fig[i]->area();
			}
			std::cout << "Total area: " << Tarea << std::endl;
		}
		else if (operation == "quit") {
			for (unsigned int i = 0; i < fig.size(); ++i) {
				delete fig[i];
			}
			return 0;
		}
		else {
			std::cout << "Wrong. Operations: add / delete / out / quit\n";
		}
	}
}