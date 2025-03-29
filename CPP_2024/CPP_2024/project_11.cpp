//정수 2개를 입력받고, 레퍼런스와 포인터를 이용하여 더 큰 값을 출력하고 a, b가 동일한지 출력하는 프로그램

#include <iostream>

bool bigger(int a, int b, int& big) { //변수 a, b 및 레퍼런스 big 받기
	//만약 a가 더 크다면 big값을 a로 변경 후 false 리턴
	if (a > b) {
		big = a;
		return false;
	}
	//만약 b가 더 크다면 big값을 b로 변경 후 false 리턴
	else if (a < b) {
		big = b;
		return false;
	}
	//만약 값이 같다면 big값을 a로 변경 후 true 리턴
	else {
		big = a;
		return true;
	}
}

bool bigger(int a, int b, int* big) { //변수 a, b 및 big 주소 받기
	//만약 a가 더 크다면 big값을 a로 변경 후 false 리턴
	if (a > b) {
		*big = a;
		return false;
	}
	//만약 b가 더 크다면 big값을 b로 변경 후 false 리턴
	else if (a < b) {
		*big = b;
		return false;
	}
	//만약 값이 같다면 big값을 a로 변경 후 true 리턴
	else {
		*big = a;
		return true;
	}
}

int main() {
	int a, b; //사용자에게 입력받은 값 저장
	int big; //a, b 중 더 큰 값 저장
	int flag; //값이 동일하면 true 다르다면 false

	std::cin >> a >> b; //a, b값 입력받기

	std::cout << "<레퍼런스>" << std::endl;
	flag = bigger(a, b, big); //bigger에서 값이 다를 경우 false(0), 같을 경우 true(1)을 리턴받는다.
	std::cout << big << std::endl; //bigger에서 레퍼런스로 변경한 big 출력

	std::cout << "<포인터>" << std::endl;
	flag = bigger(a, b, &big); //bigger에서 값이 다를 경우 false(0), 같을 경우 true(1)을 리턴받는다.
	std::cout << big << std::endl; //bigger에서 포인터로 변경한 big 출력

	if (flag == false) std::cout << "다르다" << std::endl; //만약 a, b가 다를 경우
	else std::cout << "같다" << std::endl; //만약 a, b가 같을 경우

	return 0;
}

/*
레퍼런스의 사용법과 포인터의 사용법, 오버로딩의 사용법, bool자료형을 이해하고 있는지 
확인할 수 있는 좋은 과제였습니다. 특히 bool자료형은 평소에 사용할 일이 많이 없어서 
사용할 때 헷갈렸는데 이번 과제로 헷갈리는 부분을 바로잡고 갈 수 있어서 좋았습니다.
*/