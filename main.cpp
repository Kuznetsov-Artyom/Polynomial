#include <iostream>
#include "List.hpp"
#include <vector>
#include <algorithm>
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



std::ostream& operator << (std::ostream& out, const Monom& monom)
{
	int degrX = monom.degree / 100;
	int degrY = monom.degree / 10 % 10;
	int degrZ = monom.degree % 10;

	out << abs(monom.coef) << "x^" << degrX << "y^" << degrY << "z^" << degrZ;

	return out;
}




class Polynomial
{
private:
	List<Monom> mPolynom;

private:
	void unionSimilar()
	{
		Node<Monom>* current = mPolynom.begin();

		for (auto it = mPolynom.begin() + 1; it != mPolynom.end();)
		{
			if (current->value == *it)
			{
				current->next = it->next;
				current->value.coef += it->value.coef;

				Node<Monom>* delNode = it++;
				delete delNode;

				mPolynom.setSize(mPolynom.size() - 1);
			}
			else current = it++;
		}
	}

public:
	Polynomial() {}
	Polynomial(const Polynomial& other) : mPolynom{ other.mPolynom } {}


	void addMonom(Monom monom)
	{
		if (monom.coef == 0.0) return;

		mPolynom.insert_before_if(monom, [](Monom one, Monom two) { return one > two; });

		if (mPolynom.size() == 1) return;

		unionSimilar();
		
		mPolynom.remove_nodes_if([](Monom monom) { return monom.coef == 0.0; });

	}



	size_t size() const noexcept(noexcept(mPolynom.size())) { return mPolynom.size(); }
	bool empty() const noexcept(noexcept(mPolynom.empty())) { return mPolynom.empty(); }


	Polynomial& operator = (const Polynomial& other)
	{
		mPolynom.clear();
		mPolynom = other.mPolynom;
	}
	Polynomial operator + (const Polynomial & other)
	{
		Polynomial newPolyom;

		for (auto it = mPolynom.begin(); it != mPolynom.end(); ++it)
			newPolyom.addMonom(*it);

		for (auto it = other.mPolynom.cbegin(); it != other.mPolynom.cend(); ++it)
			newPolyom.addMonom(*it);

		return newPolyom;
	}
	Polynomial operator - (const Polynomial& other)
	{
		Polynomial newPolyom;

		for (auto it = mPolynom.begin(); it != mPolynom.end(); ++it)
			newPolyom.addMonom(*it);

		for (auto it = other.mPolynom.cbegin(); it != other.mPolynom.cend(); ++it)
		{
			Monom newMonom(*it);
			newMonom.coef = -newMonom.coef;
			newPolyom.addMonom(newMonom);
		}

		return newPolyom;
	}

	friend std::ostream& operator << (std::ostream& out, const Polynomial& polynom);
};


std::ostream& operator << (std::ostream& out, const Polynomial& polynom)
{
	if (polynom.empty()) return out;	

	auto itStart = polynom.mPolynom.cbegin();
	auto itStop = polynom.mPolynom.cend();

	if (itStart->value.coef > 0.0)
		out << *itStart;
	else out << "- " << *itStart;

	++itStart;

	for (auto it = itStart; it != itStop; ++it)
	{
		if (it->value.coef > 0.0)
			out << " + " << *it;
		else out << " - " << *it;
	}

	return out;
}










int main(int argc, char* argv[])
{
	Polynomial polynom;
	Polynomial polynomTwo;

	polynom.addMonom(Monom(4, 323));
	polynom.addMonom(Monom(-5, 225));
	polynom.addMonom(Monom(-9, 123));

	polynomTwo.addMonom(Monom(5, 323));
	polynomTwo.addMonom(Monom(5, 225));
	polynomTwo.addMonom(Monom(-123, 494));
	polynomTwo.addMonom(Monom(6, 123));

	std::cout << polynom << '\n' << polynomTwo << "\n\n";

	std::cout << "Sum: " << polynom + polynomTwo << '\n';
	std::cout << "Dif: " << polynom - polynomTwo << '\n';


	/*List<int> list;

	for (int i = 4; i >= 0; --i)
		list.push_back(i + 1);

	std::cout << list << '\n' << list.size() << "\n\n";

	list.insert_after_if(3, [](int valueOne, int valueTwo) { return valueOne > valueTwo; });

	std::cout << list << '\n' << list.size() << "\n\n";

	list.remove_nodes_if([](int value) { return value % 2 == 0; });

	std::cout << list << '\n' << list.size() << "\n\n";*/



	return 0;
}