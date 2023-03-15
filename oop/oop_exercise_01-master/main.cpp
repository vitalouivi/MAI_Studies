#include "lab1.h"

int main() {
	using namespace lab1;
	std::string city1, street1;

	Address adr1;
	Address adr2;
	std::cout << "Enter address 1: ";
	adr1.Read(std::cin);
	
	std::cout << "First adress: ";
	adr1.Write(std::cout);
	std::cout << "Enter address 2: ";
	adr2.Read(std::cin);
	
	std::cout << "Second adress: ";
	adr2.Write(std::cout);

	adr1.CompAdr(adr1, adr2);
	adr1.IsNear(adr1, adr2);

	std::cout << "Enter city: ";
	std::cin >> city1;
	std::cout << "Enter street: ";
	std::cin >> street1;
	adr1.Belong(city1, street1, adr1);
	adr2.Belong(city1, street1, adr2);
}