#ifndef MONOM_HPP
#define MONOM_HPP


#include <ostream>
#include <cmath>


struct Monom
{
	double coef;
	int degree;

	Monom(double cf = 0.0, int deg = 0) : coef{ cf }, degree{ deg } {}

	bool operator == (const Monom& other) { return degree == other.degree; }
	bool operator != (const Monom& other) { return degree != other.degree; }
	bool operator > (const Monom& other) { return degree > other.degree; }
	bool operator < (const Monom& other) { return degree < other.degree; }
	bool operator >= (const Monom& other) { return degree >= other.degree; }
	bool operator <= (const Monom& other) { return degree <= other.degree; }
};


inline std::ostream& operator << (std::ostream& out, const Monom& monom)
{
	int degrX = monom.degree / 100;
	int degrY = monom.degree / 10 % 10;
	int degrZ = monom.degree % 10;

	out << abs(monom.coef) << "x^" << degrX << "y^" << degrY << "z^" << degrZ;

	return out;
}


#endif // MONOM_HPP