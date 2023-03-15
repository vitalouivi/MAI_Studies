#include "trapezoid.h"
#include <cmath>

Trapezoid::Trapezoid() : A{ 0, 0 }, B{ 0, 0 }, C{ 0, 0 }, D{ 0,0 } {}

Trapezoid::Trapezoid(std::istream& in) {
	in >> A >> B >> C >> D;
	double b = sqrt((C.X() - B.X()) * (C.X() - B.X()) + (C.Y() - B.Y()) * (C.Y() - B.Y()));
	double d = sqrt((D.X() - A.X()) * (D.X() - A.X()) + (D.Y() - A.Y()) * (D.Y() - A.Y()));
	if ((C.Y() - B.Y()) / (C.X() - B.X()) != (D.Y() - A.Y()) / (D.X() - A.X()))
		throw std::logic_error("It`s not a trapezoid");
}


double Trapezoid::area() const {
	return 0.5 * std::abs(A.X() * B.Y() + B.X() * C.Y() + C.X() * D.Y() + D.X() * A.Y() - B.X() * A.Y() - C.X() * B.Y() - D.X() * C.Y() - A.X() * D.Y());
}

Point Trapezoid::center() const
{
	return Point{ (A.X() + B.X() + C.X() + D.X()) / 4, (A.Y() + B.Y() + C.Y() + D.Y()) / 4 };
}

std::ostream& Trapezoid::print(std::ostream& out) const
{
	out << A << " " << B << " " << C << " " << D;
	return out;
}