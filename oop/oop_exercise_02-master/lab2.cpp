#include "lab2.h"

namespace lab2 {
	std::string Address::ToLower(std::string s) {
		std::string low = "";

		for (int i = 0; i < (int)s.length(); i++) {
			low += tolower(s[i]);
		}
		return low;
	}

	Address::Address() {
		city = "";
		street = "";
		house = 0;
		flat = 0;
	}

	Address::Address(std::string c, std::string s, int h, int f) {
		city = c;
		street = s;
		house = h;
		flat = f;
	}

	void Address::Read(std::istream& is) {
		is >> city >> street >> house >> flat;
		city = ToLower(city);
		street = ToLower(street);
	}
	void Address::Write(std::ostream& os) const {
		os << city << " " << street << " " << house << " " << flat << "\n";
	}

	std::string Address::City() const {
		return ToLower(city);
	}
	std::string Address::Street() const {
		return ToLower(street);
	}
	int Address::House() const {
		return house;
	}
	int Address::Flat() const {
		return flat;
	}

	bool Address::operator==(const Address& adr) const {
		if ((this->City() == adr.City()) && (this->Street() == adr.Street()) && (this->House() == adr.House()) && (this->Flat() == adr.Flat()))
			return true;
		else
			return false;
	}

	bool Address::operator&(const Address& adr) const {
		if ((this->City() == adr.City()) && (this->Street() == adr.Street()) && abs(this->House() - adr.House()) <= 2)
			return true;
		
		else
			return false;
	}

	void Address::Belong(std::string c, std::string s, const Address& adr) const {
		if (adr.City() == ToLower(c) && adr.Street() == ToLower(s))
			std::cout << "This address belongs" << std::endl;
		else
			std::cout << "This address doesn't belong" << std::endl;
	}

	std::istream& operator>> (std::istream& in, Address& adr) {
		in >> adr.city >> adr.street >> adr.house >> adr.flat;
		return in;
	}
	std::ostream& operator<< (std::ostream& out, const Address& adr) {
		out << adr.city << " " << adr.street << " " << adr.house << " " << adr.flat << "\n";
		return out;
	}

	Address operator""_adr(const char* str, size_t size) {//( city,street,house,flat )
		std::istringstream is(str);
		char tmp;
		std::string c;
		std::string s;
		int h, f;
		is >> tmp >> c >> tmp >> s >> tmp >>h >> tmp >> f ;
		return {c,s,h,f};
	}
}