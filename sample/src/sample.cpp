#include "logger_lib.hpp"
#include <exception>
#include <iostream>

//Creating obj of class Logging and specifying the preferred severity level to log messages.
logger::Logging obj(logger::LEVEL::FATAL);

//Log messages with minimum information.
void test_func_1()
{
	obj.trace("helloworld ");
}

//Logs messages with all the information.
void test_func_2()
{

	obj.trace("ok !!", FLAG_ON());
}
int main(int argc,char**argv)
{
	std::cout << "test func 1\n";

	test_func_1();

	std::cout << "test func 2\n";
	test_func_2();

	obj.trace("ok");

	try {
		throw std::exception("exception");
	}
	catch (std::exception& ex)
	{
		std::cout << "\n try and catch block"<<std::endl;
		obj.trace(ex.what(),FLAG_ON());
	
	}
	return 0;
}



















