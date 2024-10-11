#include <iostream>

int getValue()
{
	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;


	return x;
}

void Double(int x)
{
	std::cout << x << " Multiplied by two is: " << x * 2 << '\n';
}

int add(int a, int b)
{
	std::cout << "Enter a number: \n ";

	std::cin >> a;
	std::cout << "Enter another number: \n";
	std::cin >> b;
	std::cout << a << " + " << b << " = ";
	return a + b;
}
bool factOrCap(int x) {

	if (x > 100) {
		std::cout << "\nfuck its over 100\n";
		return true;

	}
	else if (x < 101) {
		std::cout << "\nshit its under 100\n";
		return false;

	}
}

int getInteger()
{
	std::cout << "\nEnter an integer: \n";
	int x{};
	std::cin >> x;
	return x;
}

void fuck() {
	using namespace std;
	cout << "fucklk";
	cout << "fukkaaaaa";
}
