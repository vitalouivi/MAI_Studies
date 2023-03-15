#ifndef D_LAB2_H_
#define D_LAB2_H_ 1

#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>

namespace lab2 {
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

		bool operator==(const Address& adr) const;
		bool operator&(const Address& adr) const;

		void Belong(std::string c, std::string s, const Address& adr) const;

		friend std::istream& operator>> (std::istream& in, Address& adr);
		friend std::ostream& operator<< (std::ostream& out, const Address& adr);
	};
	Address operator""_adr(const char* str, size_t size);
}

#endif 