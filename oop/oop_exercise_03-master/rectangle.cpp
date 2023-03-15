#include "rectangle.h"
#include <cmath>

Rectangle::Rectangle() : A{ 0, 0 }, B{ 0, 0 }, C{ 0,0 }, D{ 0,0 } {}

Rectangle::Rectangle(std::istream& in) {
	in >> A >> B >> C >> D;
	double a, b, c, d, d1, d2, ABC, BCD, CDA, DAB;
	a = sqrt((B.X() - A.X()) * (B.X() - A.X()) + (B.Y() - A.Y()) * (B.Y() - A.Y()));
	b = sqrt((C.X() - B.X()) * (C.X() - B.X()) + (C.Y() - B.Y()) * (C.Y() - B.Y()));
	c = sqrt((C.X() - D.X()) * (C.X() - D.X()) + (C.Y() - D.Y()) * (C.Y() - D.Y()));
	d = sqrt((D.X() - A.X()) * (D.X() - A.X()) + (D.Y() - A.Y()) * (D.Y() - A.Y()));
	d1 = sqrt((B.X() - D.X()) * (B.X() - D.X()) + (B.Y() - D.Y()) * (B.Y() - D.Y()));
	d2 = sqrt((C.X() - A.X()) * (C.X() - A.X()) + (C.Y() - A.Y()) * (C.Y() - A.Y()));
	ABC = (a * a + b * b - d2 * d2) / 2 * a * b;
	BCD = (b * b + c * c - d1 * d1) / 2 * b * c;
	CDA = (d * d + c * c - d2 * d2) / 2 * d * c;
	DAB = (a * a + d * d - d1 * d1) / 2 * a * d;
	if (ABC != BCD || ABC != CDA || ABC != DAB)
		throw std::logic_error("It`s not a rectangle");
}

double Rectangle::area() const {
	double a = sqrt((B.X() - A.X()) * (B.X() - A.X()) + (B.Y() - A.Y()) * (B.Y() - A.Y()));
	double b = sqrt((C.X() - B.X()) * (C.X() - B.X()) + (C.Y() - B.Y()) * (C.Y() - B.Y()));;
	return a * b;
}

Point Rectangle::center() const {
	return Point{ (A.X() + B.X() + C.X() + D.X()) / 4, (A.Y() + B.Y() + C.Y() + D.Y()) / 4 };
}

std::ostream& Rectangle::print(std::ostream& out) const {
	out << A << " " << B << " " << C << " " << D;
	return out;
}