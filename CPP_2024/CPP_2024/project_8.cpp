//생성자, 소멸자를 이용한 사각형의 너비와 높이를 출력하는 프로그램

#include <iostream>

class Rectangle {
private:
	int width, height;

public:
	Rectangle(); //기본 생성자 
	Rectangle(int width_, int height_); //int형 매개변수가 2개인 생성자
	~Rectangle(); //소멸자 

	void show();
	void set(int width_, int height_);
};

Rectangle::Rectangle() {
	width = 1;
	height = 1;
}

Rectangle::Rectangle(int width_, int height_) {
	width = width_;
	height = height_;
}

Rectangle::~Rectangle() {
	std::cout << "소멸자 호출" << " Width: " << width << " Height: " << height << std::endl;
}

void Rectangle::show() {
	std::cout << "Width: " << width << " Height: " << height << std::endl;
}

void Rectangle::set(int width_, int height_) {
	//width, height가 private로 선언되어 있으니 아래와 같이 값을 삽입 
	width = width_;
	height = height_;
}

int main() {
	Rectangle rect1; //기본 생성자 호출 
	Rectangle rect2(10, 20); //매개변수 2개를 갖고 있는 생성자 호출 
	rect1.show();
	rect1.set(5, 6);
	rect2.show();

	return 0;
}

/*
이번 과제의 주요 내용은 생성자와 소멸자였다. 생성자와 소멸자를 만드는 것은 어렵지 않았다.
하지만 생성자와 함수를 선언하는 부분이 헷갈려서 함수의 자료형을 선언하지 않는 실수를 하였다.
이를 착각하지 않도록 생성자와 함수 사용법을 익히고 생성자와 소멸자의 실행 순서를 공부해야겠다고 느꼈다.
*/