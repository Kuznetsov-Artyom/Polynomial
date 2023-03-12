#include <iostream>
#include "Polynomial.hpp"






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

	polynom.updPolStr();
	polynomTwo.updPolStr();

	std::cout << polynom << '\n' << polynomTwo << "\n\n";

	std::cout << "Sum: " << polynom + polynomTwo << '\n';
	std::cout << "Dif: " << polynom - polynomTwo << '\n';

	std::cout << polynom.size() << ' ' << polynomTwo.size() << '\n';

	polynomTwo.delMonom(494);

	polynomTwo.updPolStr();

	std::cout << polynom << '\n' << polynomTwo << "\n\n";
	std::cout << polynom.size() << ' ' << polynomTwo.size() << '\n';


	/*List<int> list;

	for (int i = 4; i >= 0; --i)
		list.push_back(i + 1);

	std::cout << list << '\n' << list.size() << "\n\n";

	list.insert_after_if(3, [](int valueOne, int valueTwo) { return valueOne > valueTwo; });

	std::cout << list << '\n' << list.size() << "\n\n";

	list.remove_nodes_if([](int value) { return value % 2 == 0; });

	std::cout << list << '\n' << list.size() << "\n\n";

	list.erase(2);

	std::cout << list << '\n' << list.size() << "\n\n";*/

	



	return 0;
}