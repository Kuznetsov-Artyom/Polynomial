#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP


#include "Monom.hpp"
#include "List.hpp"
#include <string>
#include <sstream>


class Polynomial
{
private:
	List<Monom> mPolynom;
	std::string mPolStr;

private:
	void unionSimilar();
	void throwExceptionIfEmpty();
	std::string updPolStr();

public:
	Polynomial() : mPolynom{}, mPolStr{} {}
	Polynomial(const Polynomial& other) : mPolynom{ other.mPolynom }, mPolStr{} { updPolStr(); }


	void addMonom(const Monom& monom);
	void delMonom(int degree);

	std::string polynomStr() const noexcept { return mPolStr; }

	double calculateAtPoint(int x, int y, int z)
	{
		// TODO: Переделать моном и реализовать вычисление в точке

		return double();
	}


	size_t size() const noexcept(noexcept(mPolynom.size())) { return mPolynom.size(); }
	bool empty() const noexcept(noexcept(mPolynom.empty())) { return mPolynom.empty(); }
	void clear() { mPolynom.clear(); }





	Polynomial& operator = (const Polynomial& other);

	Polynomial operator + (const Polynomial& other) const;
	Polynomial operator - (const Polynomial& other) const;

	Polynomial& operator += (const Polynomial& other);
	Polynomial& operator -= (const Polynomial& other);
	Polynomial& operator += (const double& value);
	Polynomial& operator -= (const double& value);

	Polynomial operator + () const;
	Polynomial operator - () const;

	friend inline Polynomial operator + (const Polynomial& polynom, const double& value);
	friend inline Polynomial operator - (const Polynomial& polynom, const double& value);
	friend inline Polynomial operator + (const double& value, const Polynomial& polynom);
	friend inline Polynomial operator - (const double& value, const Polynomial& polynom);

	friend inline std::ostream& operator << (std::ostream& out, const Polynomial& polynom);
};


inline Polynomial operator + (const Polynomial& polynom, const double& value)
{
	if (value == 0.0) return polynom;

	Polynomial newPolynom;

	auto itStart = polynom.mPolynom.cbegin();
	auto itStop = polynom.mPolynom.cend();

	for (auto it = itStart; it != itStop;) newPolynom.addMonom(*(it++));
	newPolynom.addMonom(Monom(value));

	return newPolynom;
}

inline Polynomial operator-(const Polynomial& polynom, const double& value)
{
	return polynom + (-value);
}

inline Polynomial operator+(const double& value, const Polynomial& polynom)
{
	return polynom + value;
}

inline Polynomial operator-(const double& value, const Polynomial& polynom)
{
	return value + (-polynom);
}

inline std::ostream& operator << (std::ostream& out, const Polynomial& polynom)
{
	if (polynom.empty()) return out;

	return out << polynom.polynomStr();
}


#endif // POLYNOMIAL_HPP
