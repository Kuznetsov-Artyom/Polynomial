#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP


#include "Monom.hpp"
#include "List.hpp"
#include <string>
#include <sstream>
#include <ostream>


class Polynomial
{
private:
	List<Monom> mPolynom;
	std::string mPolStr;

private:
	void unionSimilar();
	void throwExceptionIfEmpty();

public:
	Polynomial() : mPolynom{}, mPolStr{} {}
	Polynomial(const Polynomial& other) : mPolynom{ other.mPolynom }, mPolStr{} { updPolStr(); }


	void addMonom(const Monom& monom);
	void delMonom(int degree);


	std::string updPolStr();
	std::string polynomStr() const { return mPolStr; }


	size_t size() const noexcept(noexcept(mPolynom.size())) { return mPolynom.size(); }
	bool empty() const noexcept(noexcept(mPolynom.empty())) { return mPolynom.empty(); }





	Polynomial& operator = (const Polynomial& other);
	Polynomial operator + (const Polynomial& other) const;
	Polynomial operator - (const Polynomial& other) const;
	Polynomial& operator += (const Polynomial& other);
	Polynomial& operator -= (const Polynomial& other);

	friend inline std::ostream& operator << (std::ostream& out, const Polynomial& polynom);
};


inline std::ostream& operator << (std::ostream& out, const Polynomial& polynom)
{
	if (polynom.empty()) return out;

	return out << polynom.polynomStr();
}


#endif // POLYNOMIAL_HPP
