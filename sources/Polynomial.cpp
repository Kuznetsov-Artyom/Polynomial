#include "Polynomial.hpp"


///////////////////// METHODS /////////////////////

void Polynomial::unionSimilar()
{
	Node<Monom>* current = mPolynom.begin();

	size_t index = 1;

	for (auto it = mPolynom.begin() + 1; it != mPolynom.end();)
	{
		if (current->value == *it)
		{
			current->value.coef += it->value.coef;

			++it;
			mPolynom.erase(index);
		}
		else
		{
			current = it++;
			++index;
		}
	}
}

void Polynomial::throwExceptionIfEmpty()
{
	if (empty())
		throw std::logic_error{ "polynomial is empty" };
}

std::string Polynomial::updPolStr()
{
	if (empty()) return std::string();

	std::stringstream stream;

	auto itStart = mPolynom.cbegin();
	auto itStop = mPolynom.cend();

	stream << *itStart;

	++itStart;

	for (auto it = itStart; it != itStop; ++it)
	{
		if (it->value.coef > 0.0) stream << " + " << *it;
		else stream << *it;
	}

	mPolStr = stream.str();

	return mPolStr;
}

void Polynomial::addMonom(const Monom& monom)
{
	if (monom.coef == 0.0) return;

	mPolynom.insert_before_if(monom, [](Monom one, Monom two) { return one > two; });

	if (mPolynom.size() == 1)
	{
		updPolStr();
		return;
	}

	unionSimilar();

	mPolynom.remove_nodes_if([](Monom monom) { return monom.coef == 0.0; });

	updPolStr();
}

void Polynomial::delMonom(int degree)
{
	throwExceptionIfEmpty();

	mPolynom.remove_nodes_if([&degree](Monom monom) { return monom.degree == degree; });

	updPolStr();
}




///////////////////// OVERLOAD OPERATORS /////////////////////

Polynomial& Polynomial::operator=(const Polynomial& other)
{
	if (this == &other) return *this;

	mPolynom.clear();
	mPolynom = other.mPolynom;

	return *this;
}

Polynomial Polynomial::operator+(const Polynomial& other) const
{
	if (other.empty()) return *this;

	Polynomial newPolynom;

	auto itStart = mPolynom.cbegin();
	auto itStop = mPolynom.cend();

	for (auto it = itStart; it != itStop;) newPolynom.addMonom(*(it++));

	itStart = other.mPolynom.cbegin();
	itStop = other.mPolynom.cend();

	for (auto it = itStart; it != itStop;) newPolynom.addMonom(*(it++));

	return newPolynom;
}

Polynomial Polynomial::operator-(const Polynomial& other) const
{
	if (other.empty()) return *this;

	return Polynomial(*this + (-other));
}

Polynomial& Polynomial::operator+=(const Polynomial& other)
{
	if (other.empty()) return *this;

	auto itStart = other.mPolynom.cbegin();
	auto itStop = other.mPolynom.cend();

	for (auto it = itStart; it != itStop;) { addMonom(*(it++)); }

	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other)
{
	if (other.empty()) return *this;

	*this += -other;

	return *this;
}

Polynomial& Polynomial::operator+=(const double& value)
{
	if (value == 0.0) return *this;
	
	addMonom(Monom(value));

	return *this;
}

Polynomial& Polynomial::operator-=(const double& value)
{
	*this += -value;

	return *this;
}

Polynomial Polynomial::operator+() const { return *this; }

Polynomial Polynomial::operator-() const
{
	if (empty()) return *this;

	Polynomial newPolynom;

	auto itStart = mPolynom.cbegin();
	auto itStop = mPolynom.cend();

	for (auto it = itStart; it != itStop;) newPolynom.addMonom(-(*(it++)));
	
	return newPolynom;	
}
