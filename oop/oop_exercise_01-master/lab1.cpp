#include "lab1.h"

namespace lab1 {
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

	void Address::CompAdr(const Address& adr1, const Address& adr2) const {
		if ((adr1.City() == adr2.City()) && (adr1.Street() == adr2.Street()) && (adr1.House() == adr2.House()) && (adr1.Flat() == adr2.Flat()))
			std::cout << "Address1 is similar to address2" << std::endl;
		else
			std::cout << "Address1 is not similar to address2" << std::endl;
	}
	void Address::IsNear(const Address& adr1, const Address& adr2) const {
		if ((adr1.City() == adr2.City()) && (adr1.Street() == adr2.Street()) && abs(adr1.House() - adr2.House()) <= 2)
			std::cout << "Address1 is near address2" << std::endl;
		else
			std::cout << "Address1 is not near address2" << std::endl;
	}
	void Address::Belong(std::string c, std::string s, const Address& adr) const {
		if (adr.City() == ToLower(c) && adr.Street() == ToLower(s))
			std::cout << "This address belongs" << std::endl;
		else
			std::cout << "This address doesn't belong" << std::endl;
	}

}