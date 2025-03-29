#include <iostream>

class op {
private:
	int a;
	int b;
public:
	op(int a = 0, int b = 0) : a(a), b(b) {}
	op operator+(const op& op2) {
		op tmp;
		tmp.a = this->a + op2.a;
		tmp.b = this->b + op2.b;
		return tmp;
	}
	op operator-(const op& op2) {
		op tmp;
		tmp.a = this->a - op2.a;
		tmp.b = this->b - op2.b;
		return tmp;
	}
	op operator++(int x) {
		op tmp = *this;
		a++;
		b++;
		return tmp;
	}
	op& operator++() {
		++a;
		++b;
		return *this;
	}
	bool operator==(const op& op2) {
		if (this->a == op2.a && this->b == op2.b) return true;
		else return false;
	}
	op& operator=(const op& op2) {
		this->a = op2.a;
		this->b = op2.b;
		return *this;
	}
	void print() {
		std::cout << "a의 값은: " << a << " b의 값은: " << b << std::endl;
	}
};
int main() {
	op O1(1, 2);
	op O2(2, 3);
	op O3;

	O3 = O1 + O2;
	O3.print();

	O3 = O1 - O2;
	O3.print();

	O1++;
	O1.print();
	O2++;
	O2.print();

	++O1;
	O1.print();
	++O2;
	O2.print();

	O1++;
	if (O1 == O2) std::cout << "일치\n";
	else std::cout << "불일치\n";

	return 0;
}
