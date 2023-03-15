#ifndef D_LAB1_H_
#define D_LAB1_H_ 1

#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <iostream>

namespace lab1 {
	class Address
	{
	private:
		std::string city;
		std::string street;
		int house;
		int flat;

	public:
		static std::string ToLower(std::string);

		Address();
		Address(std::string c, std::string s, int h, int f);

		void Read(std::istream& is);
		void Write(std::ostream& os) const;

		std::string City() const;
		std::string Street() const;
		int House() const;
		int Flat() const;

		void CompAdr(const Address& adr1, const Address& adr2) const;
		void IsNear(const Address& adr1, const Address& adr2) const;
		void Belong(std::string c, std::string s, const Address& adr) const;
	};
}

#endif 