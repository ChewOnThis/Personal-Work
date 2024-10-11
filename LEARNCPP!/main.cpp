#ifndef HEADERGUARD
#define HEADERGUARD	 

#include <iostream>
#include "functions.cpp"
#include "head.h"
#define PENIS_MODULE "Blipblarg22223"
#define PRINT_JOE

#endif
int a{};
int b{};
int add(int a, int b);
void Double(int x);
bool factOrCap(int x);
int getValue();
int getInteger();
void fuck();

int main()
{
	std::cout << "1. Old shit\n\n 2. New shit\n\n";
	std::cout << "pick a mode to test: ";
	int p;
	std::cin >> p;
		int x, y;

		switch (p) {
		case 1:
			
			Double(factOrCap(getValue()));

			std::cout << add(a, b);
			x = getInteger();
			y = getInteger();

			std::cout << x << " + " << y << " is " << x + y << '\n';

			break;

		case 2:
			std::cout << PENIS_MODULE "\n";
			fuck();
#ifdef PRINT_JOE
			std::cout << "\n\nJoe\n"; // will be compiled since PRINT_JOE is defined
#endif

#ifdef PRINT_BOB
			std::cout << "Bob\n"; // will be excluded since PRINT_BOB is not defined
#endif

#ifndef PRINT_BOB
			std::cout << "Bob\n";//will compile as ifndef is opposite of ifdef 
#endif// (#if defined(PRINT_BOB)) (#if !defined(PRINT_BOB)) also works

			std::cout << "Joe\n";

#if 0 // Don't compile anything starting here
			std::cout << "Bob\n";
			std::cout << "Steve\n";
#endif // until this point

			break;
		}




		

		return 0;
}







#include <iostream>

/*
int add(int x, int y); // function declaration includes return type, name, parameters, and semicolon.  No function body!
Now, here’s our original program that didn’t compile, using a function declaration as a forward declaration for function add :

#include <iostream>

int add(int x, int y); // forward declaration of add() (using a function declaration)

int main()
{
	std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n'; // this works because we forward declared add() above
	return 0;
}

int add(int x, int y) // even though the body of add() isn't defined until here
{
	return x + y;
}

int add(int x, int y); // tells the compiler about a function named "add" that takes two int parameters and returns an int.  No body!
int x;                 // tells the compiler about an integer variable named x


int add(int, int); // Prototype

int main() {
	int result = add(5, 3);
	return 0;
}

int add(int a, int b) { // Definition
	return a + b;
}

*/





























