//default parameter, 오버로딩

#include <iostream>
#include <cmath> //내림(floor)을 사용하기 위해 불러옴

void print(int n = 3) { //default parameter 사용(매개변수 값이 없을 경우 n = 3, 매개변수가 있을 경우 n = 매개변수
	for (int i = 0; i < n; i++) { //n번 Hello 출력
		std::cout << "Hello" << std::endl;
	}
}

void print(double n) { //double자료형 오버로딩
	for (double i = -5; i < floor(n); i++) { //floor함수로 매개변수 n을 내림 해줌
		std::cout << "Bye" << std::endl;
	}
}

void print(char n) { //char자료형 오버로딩
	//아스키코드 97은 a이며 98은 b, 99는 c와 같이 a-z까지 1씩 증가한다. 따라서 -96을 하면 a를 받아올 때 world가 1회, b를 받아올 때 world가 2회 출력된다.
	for (int i = 0; i < n - 96; i++) {
		std::cout << "world" << std::endl;
	}
}

int main() {
	print(); //print(int n = 3) - 매개변수가 없으므로 n = 3이 됨
	print(2); //print(int n = 2) - 매개변수가 있으므로 n = 2가 됨
	print(-3.8); //print(double n) - double자료형 오버로딩
	print('a'); //print(char n) - char자료형 오버로딩

	return 0;
}
