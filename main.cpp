#include <iostream>
#include "Polynomial.hpp"
#include "List.hpp"





int main(int argc, char* argv[])
{
	Polynomial polynom;
	Polynomial polynomTwo;

	polynom.addMonom(Monom(4, 323));
	polynom.addMonom(Monom(-5, 225));
	polynom.addMonom(Monom(-9, 123));
	polynom.addMonom(Monom(25.5, 0));

	polynomTwo.addMonom(Monom(5, 323));
	polynomTwo.addMonom(Monom(-15.5, 0));
	polynomTwo.addMonom(Monom(-123, 494));
	polynomTwo.addMonom(Monom(6, 123));

	const Polynomial polynomThree(polynom);

	std::cout << polynom << '\n' << polynomTwo << '\n' << polynomThree << "\n\n";

	std::cout << "Sum: " << polynom + polynomTwo << '\n';
	std::cout << "Dif: " << polynom - polynomTwo << '\n';

	polynom.clear();

	std::cout << polynom.size() << ' ' << polynomTwo.size() << '\n';

	polynomTwo.delMonom(494);

	std::cout << polynom << '\n' << polynomTwo << "\n\n";
	std::cout << polynom.size() << ' ' << polynomTwo.size() << '\n';

	std::cout << "\n\n";

	std::cout << polynomTwo << '\n';

	polynomTwo -= polynomTwo;

	std::cout << polynomTwo << '\n';

	/*polynom = polynom + 5;
	polynomTwo = 10 + polynomTwo;

	polynom.updPolStr();
	polynomTwo.updPolStr();

	std::cout << polynom << '\n' << polynomTwo << "\n\n";
	std::cout << -polynom << '\n' << -polynomTwo << "\n\n";*/


	List<int> list;

	for (int i = 4; i >= 0; --i)
		list.push_back(i + 1);

	std::cout << list << '\n' << list.size() << "\n\n";

	list.insert_after_if(-1, [](int valueOne, int valueTwo) { return valueOne > valueTwo; });
	std::cout << list.front() << ' ' << list.back();

	std::cout << list << '\n' << list.size() << "\n\n";

	list.remove_nodes_if([](int value) { return value % 2 == 0; });

	std::cout << list << '\n' << list.size() << "\n\n";

	list.erase(2);

	std::cout << list << '\n' << list.size() << "\n\n";

	while (!list.empty())
	{
		std::cout << list << '\n' << list.size() << "\n\n";
		list.erase(0);
	}

	List<int> listTwo;

	for (int i = 0; i < 3; ++i)
		listTwo.push_back(4);

	std::cout << listTwo << '\n' << listTwo.size() << "\n\n";

	listTwo.remove_nodes_if([](int value) { return value % 2 == 0; });

	std::cout << listTwo << '\n' << listTwo.size() << "\n\n";

	if (listTwo.empty()) std::cout << "ListTwo is empty\n";

	std::cout << "\n\n\n";

	List<int> listFree;

	listFree.push_back(5);
	
	std::cout << listFree << '\n';
	std::cout << listFree.front() << ' ' << listFree.back() << "\n\n";

	listFree.insert_after_if(4, [](int one, int two) { return one < two; });

	std::cout << listFree << '\n';
	std::cout << listFree.front() << ' ' << listFree.back() << "\n\n";






	return 0;
}