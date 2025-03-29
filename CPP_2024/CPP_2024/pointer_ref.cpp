//[포인터]

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
*pb += 2;는* (pb + 0)에 2를 더하는 것이다.

* pb++;는* (pb + 1)이다.
++ * pb는 1 + *(pb + 0)이다.

* (pb)++;는* (pb + 1)과 똑같다.
(*pb)++;는* (pb + 0)에 1을 더하는 이다.

pb ++는 메모리에 데이터 타입의 사이즈 만큼 더해준다.

참고자료: https://www.tcpschool.com/codingmath/priority
*/

//[포인터, 레퍼런스]

#include <iostream>

int main() {
	int a = 50;
	int* p = &a;
	int& r = *p;

	r = 20;

	std::cout << "변수 a는 " << a << std::endl;
	std::cout << "포인터 p는 " << *p << std::endl;
	std::cout << "레퍼런스 r은 " << r << std::endl;

	//var는 value를 갖는다. *var는 변수, val는 상수이다.
	//ptr는 a의 address, value를 갖는다.
	//ref는 포인터 p의 address를 갖는다.
	//ref는 선언과 동시에 초기화를 해주어야 하며 ref는 address만 저장할 수 있다.

	return 0;
}
