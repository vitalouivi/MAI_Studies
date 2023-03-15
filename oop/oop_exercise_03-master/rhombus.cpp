#include "rhombus.h"
#include <cmath>

Rhombus::Rhombus() : A{ 0, 0 }, B{ 0, 0 }, C{ 0, 0 }, D{ 0,0 } {}
Rhombus::Rhombus(std::istream& in) {
	in >> A >> B >> C >> D;
	double a, b, c, d;
	a = sqrt((B.X() - A.X()) * (B.X() - A.X()) + (B.Y() - A.Y()) * (B.Y() - A.Y()));
	b = sqrt((C.X() - B.X()) * (C.X() - B.X()) + (C.Y() - B.Y()) * (C.Y() - B.Y()));
	c = sqrt((C.X() - D.X()) * (C.X() - D.X()) + (C.Y() - D.Y()) * (C.Y() - D.Y()));
	d = sqrt((D.X() - A.X()) * (D.X() - A.X()) + (D.Y() - A.Y()) * (D.Y() - A.Y()));
	if (a != b || a != c || a != d)
		throw std::logic_error("It`s not a rhombus");
}


double Rhombus::area() const {
	double d1 = sqrt((C.X() - A.X()) * (C.X() - A.X()) + (C.Y() - A.Y()) * (C.Y() - A.Y()));;
	double d2 = sqrt((B.X() - D.X()) * (B.X() - D.X()) + (B.Y() - D.Y()) * (B.Y() - D.Y()));;
	return d1 * d2 / 2;
}

Point Rhombus::center() const
{
	return Point{ (A.X() + B.X() + C.X() + D.X()) / 4, (A.Y() + B.Y() + C.Y() + D.Y()) / 4 };
}

std::ostream& Rhombus::print(std::ostream& out) const
{
	out << A << " " << B << " " << C << " " << D;
	return out;
}