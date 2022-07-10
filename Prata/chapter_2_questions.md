1.	Functions
2.	Replace itself with content of "iostream" file
3.	Brings std namespace to the current scope & allows to use it's members without explicit specifier std::
4.	std::cout << "Hello, world\n";
5.	int cheeses;
6.	cheeses = 32;
7.	std::cin >> cheeses;
8.	std::cout << "We have " << cheeses << " varieties of cheese\n";
9.	int froop(double t); the "froop" funtion takes 1 argument of type double named "t" and returns a value of integer type.
	void rattle(int n); the "rattle" fuction takes 1 argument of type int named "n" and has no return value.
	int prune(void); the "prune" fuction takes no argumens and returns a value of integer type.
10.	return is not used in functions that do not have a return type (void functions). Return also may be ommited in the main() funtion.
11.	The problem is that the cout object was not brought to the current scope.
	Check if "#include <iostream>" is in place.
	Then specify the namespace like "std::cout" or "using namespace std".
