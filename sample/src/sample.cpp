#include "logger_lib.hpp"

int main()
{
	//Creating obj of class Logging and specifying the preferred severity level to log messages.
	logger::Logging obj(logger::LEVEL::FATAL);

	//Logging message at trace level.
	obj.trace(std::string("hello"));
	return 0;
}
