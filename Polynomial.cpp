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

void Polynomial::addMonom(const Monom& monom)
{
	if (monom.coef == 0.0) return;

	mPolynom.insert_before_if(monom, [](Monom one, Monom two) { return one > two; });

	if (mPolynom.size() == 1) return;

	unionSimilar();

	mPolynom.remove_nodes_if([](Monom monom) { return monom.coef == 0.0; });
}

void Polynomial::delMonom(int degree)
{
	throwExceptionIfEmpty();

	mPolynom.remove_nodes_if([&degree](Monom monom) { return monom.degree == degree; });
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
	Polynomial newPolyom;

	for (auto it = mPolynom.cbegin(); it != mPolynom.cend(); ++it)
		newPolyom.addMonom(*it);

	for (auto it = other.mPolynom.cbegin(); it != other.mPolynom.cend(); ++it)
		newPolyom.addMonom(*it);

	return newPolyom;
}

Polynomial Polynomial::operator-(const Polynomial& other) const
{
	Polynomial newPolyom;

	for (auto it = mPolynom.cbegin(); it != mPolynom.cend(); ++it)
		newPolyom.addMonom(*it);

	for (auto it = other.mPolynom.cbegin(); it != other.mPolynom.cend(); ++it)
	{
		Monom newMonom(*it);
		newMonom.coef = -newMonom.coef;
		newPolyom.addMonom(newMonom);
	}

	return newPolyom;
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

	auto itStart = other.mPolynom.cbegin();
	auto itStop = other.mPolynom.cend();

	for (auto it = itStart; it != itStop;) { addMonom(-(*(it++))); }
}
