#include "lab2.h"

int main() {
	using namespace lab2;
	std::string city1, street1;

	Address adr1;
	Address adr2;
	Address adr3;
	adr3 = "( Moscow , st1 , 5 , 15 )"_adr;
	std::cout << "Third adress: ";
	adr3.Write(std::cout);
	std::cout << "Enter address 1: ";
	adr1.Read(std::cin);

	std::cout << "First adress: ";
	adr1.Write(std::cout);
	std::cout << "Enter address 2: ";
	adr2.Read(std::cin);

	std::cout << "Second adress: ";
	adr2.Write(std::cout);


	if(adr1 == adr2)
		std::cout << "Address1 is similar to address2" << std::endl;
	else
		std::cout << "Address1 is not similar to address2" << std::endl;
	if(adr1&adr2)
		std::cout << "Address1 is near address2" << std::endl;
	else
		std::cout << "Address1 is not near address2" << std::endl;

	
	std::cout << "Enter city: ";
	std::cin >> city1;
	std::cout << "Enter street: ";
	std::cin >> street1;
	adr1.Belong(city1, street1, adr1);
	adr2.Belong(city1, street1, adr2);
}


//лаб2 бул
//лаб3 один указатель, пушбэк трай кетч в конце