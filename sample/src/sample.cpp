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

Logs messages with all the information.
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
	return 0;
}




















//void hello()
//{
//
//	obj.trace(std::string("hello"));
//	std::cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
//	std::cout << "function name  :" << __FUNCTION__ << std::endl;
//	std::cout << "\n======FILESYSTEM ==========================\n" << std::endl;
//	namespace fs = std::filesystem;
//
//	fs::path p = fs::current_path();
//
//	std::cout << "The current path " << p << " decomposes into:\n"
//		<< "root name " << p.root_name() << '\n'
//		<< "root directory " << p.root_directory() << '\n'
//		<< "relative path " << p.relative_path() << '\n'
//		<< "filename " << p.filename() << '\n';
//	std::cout << "\n =============Method 3==================\n";
//	LPSTR pBuf = new char(500);
//	int len = 500;
//	//		int bytes = GetModuleFileName(NULL, pBuf, len);
//			//return bytes ? bytes : -1;
//		//	std::cout << bytes;
//			//std::cout << pBuf;
//
//	std::cout << "\n =============Method 4==================\n";
//	std::cout << "fIEL NAME " << __FILE__ << std::endl;
//	std::cout << "FUNCTION NAME " << __FUNCTION__ << std::endl;
//	std::cout << "line  " << __LINE__ << std::endl;
//}