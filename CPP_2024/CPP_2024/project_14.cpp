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

/*
처음 이 과제를 받았을 때는 default parameter가 헷갈려서 print() 함수를 하나 만들고 print(int n = 3)를 만들었다.
하지만 컴파일이 되지 않았고, 컴퓨터는 이 2개를 구분할 수 없을 것 같아서 print()를 없애니 컴파일이 되었다. 
‘매개변수 n이 double 형인 경우 “bye” n번 출력(내림)’도 처음에는 내림의 개념이 무엇인지 잘 몰라서 버림을 하였는데,
내림이라고 쓰신 이유가 있으실 것 같아서 찾아봤더니 내림이란 것이 따로 존재하였다. 따라서 구글에 내림을 검색을 하여 
버림(i < (int)(n / 1))에서 내림(i < floor(n))으로 코드를 수정하였다.
*/