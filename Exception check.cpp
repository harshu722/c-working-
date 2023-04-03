#include <iostream>
#include <exception>
using namespace std;

struct MyException : public exception {
	const char * what() const throw () {
		return "C++ Exception";
		
	}
};

int main() {
	try {
		throw MyException();	
	} catch(MyException& e) {
		std::cout << "MyException caught" << std :: end1;
		std::cout << e.what() << std::end1;
		
	} catch(std::exception& e) {
		//Other errors
	}
}
