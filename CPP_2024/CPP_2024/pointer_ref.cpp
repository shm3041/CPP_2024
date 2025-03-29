//[������]

#include <iostream>

int main() {
	int ary[5] = { 1, 2, 3, 10, 15 };
	int* pa = ary;
	int* pb = ary + 2;

	std::cout << *pb << std::endl;


	*pb += 2;
	std::cout << *pb << std::endl;

	*pb++;
	std::cout << *pb << std::endl;
	++*pb;
	std::cout << *pb << std::endl;

	*(pb)++;
	std::cout << *pb << std::endl;
	(*pb)++;
	std::cout << *pb << std::endl;

	pb++;
	std::cout << *pb << std::endl;

	return 0;
}
/*
*pb += 2;��* (pb + 0)�� 2�� ���ϴ� ���̴�.

* pb++;��* (pb + 1)�̴�.
++ * pb�� 1 + *(pb + 0)�̴�.

* (pb)++;��* (pb + 1)�� �Ȱ���.
(*pb)++;��* (pb + 0)�� 1�� ���ϴ� �̴�.

pb ++�� �޸𸮿� ������ Ÿ���� ������ ��ŭ �����ش�.

�����ڷ�: https://www.tcpschool.com/codingmath/priority
*/

//[������, ���۷���]

#include <iostream>

int main() {
	int a = 50;
	int* p = &a;
	int& r = *p;

	r = 20;

	std::cout << "���� a�� " << a << std::endl;
	std::cout << "������ p�� " << *p << std::endl;
	std::cout << "���۷��� r�� " << r << std::endl;

	//var�� value�� ���´�. *var�� ����, val�� ����̴�.
	//ptr�� a�� address, value�� ���´�.
	//ref�� ������ p�� address�� ���´�.
	//ref�� ����� ���ÿ� �ʱ�ȭ�� ���־�� �ϸ� ref�� address�� ������ �� �ִ�.

	return 0;
}
