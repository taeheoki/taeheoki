#include <iostream>

class A {
 public:
	A(void) {
		std::cout << "Default A creater" << std::endl;
	}

	~A(void) {
		std::cout << "Default A detructor" << std::endl;
	}
};

int main(void) {
	A a;
	A *b = new A;
	return 0;
}