#include <iostream>
#include <cmath>
#include <string>
#include <cctype>
#include "lab2.h"

int main() {
	using namespace lab2;
	std::string city, street;
	int house = 0, flat = 0;
	std::cout << "Enter address 1: ";
	adress adr1(city, street, house, flat);
	adress::read(std::cin, adr1);
	std::cout << "First adress: ";
	adress::write(std::cout, adr1);
	city = "";
	street = "";
	house = 0;
	flat = 0;
	std::cout << "Enter address 2: ";
	adress adr2(city, street, house, flat);
	adress::read(std::cin, adr2);
	std::cout << "Second adress: ";
	adress::write(std::cout, adr2);
	if (adr1&adr2)
		std::cout << "First adress is near second" << std::endl;
	else
		std::cout << "First adress isn't near second" << std::endl;

	std::cout << "Enter city: ";
	std::cin >> city;
	std::cout << "Enter street: ";
	std::cin >> street;
	if (adr1.Belong(city, street))
		std::cout << "First adress belongs" << std::endl;
	else
		std::cout << "First adress doesn't belong" << std::endl;
	if (adr2.Belong(city, street))
		std::cout << "Second adress belongs" << std::endl;
	else
		std::cout << "Second adress doesn't belong" << std::endl;
	//	 	 adress adr3 = "Spb Len 10 15"_adr;
}