#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"
#include "point.h"

class Trapezoid : public Figure {
public:
	Trapezoid();
	Trapezoid(std::istream& in);
	double area() const override;
	Point center() const override;
	std::ostream& print(std::ostream& out) const override;
private:
	Point A;
	Point B;
	Point C;
	Point D;
};


#endif