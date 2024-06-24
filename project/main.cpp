#include <iostream>
#include "Runner.h"
int main()
{
	try {
		run();
	}
	catch (std::runtime_error& exc)
	{
		std::cout << "Invalid argument" << std::endl;
	}
	catch (std::exception& exc)
	{
		std::cout << exc.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Invalid argument" << std::endl;
	}
	return 0;
}