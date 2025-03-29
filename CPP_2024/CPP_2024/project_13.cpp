//객체의 정보를 얕은 복사로 복사하는 프로그램

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> //strcpy 사용하기 위해 선언
class Book {
private:
	char* title; //제목
	int price; //가격
public:
	Book(const char* title, int price) { //제목, 가격 받아오기
		this->title = new char[strlen(title) + 1]; //title 메모리 공간 할당
		strcpy(this->title, title); //타이틀 설정
		this->price = price; //가격 설정
	}
	Book(const Book& B) { //복사 생성자
		title = B.title; //얕은 복사 (cpp의 title과 같은 주소 가리킴)
		this->price = B.price; //가격 설정
	}
	~Book() { //소멸자
		std::cout << "소멸자 호출" << std::endl;
		if (this->title) delete[] this->title; //title에 문자가 있다면 객체가 소멸할때 new로 할당한 메모리 해지
	}

	void set(const char* title, int price) { //타이틀, 가격 변경하는 함수
		this->title = new char[strlen(title) + 1]; //문자열 저장할 공간 할당
		strcpy(this->title, title); //타이틀 설정
		this->price = price; //가격 설정
	}
	void show() {
		std::cout << title << ' ' << price << "won" << std::endl;
	}
};
int main() {
	Book cpp("C++", 10000); //cpp 객체 생성 및 초기화
	Book java = cpp; //cpp 복사 생성자(얕은 복사)
	java.set("Java", 12000); //자바 객체의 title, price 설정
	cpp.show(); //title, price 출력
	java.show(); //title, price 출력

	return 0;
}

/*
이번 과제를 하며 얕은 복사, 깊은 복사를 할 때 메모리에서 어떤 동작이 일어나는지 알게 되었다. 
얕은 복사는 어떠한 메모리 주소를 공유해서 같이 쓰는 것이라면 깊은 복사는 복사, 붙여넣기 라는 개념이다. 
따라서 얕은 복사는 A의 메모리 공간 할당이 해지된다면 B도 해당 메모리 공간에 접근할 수 없게 된다. 
개인적으로 궁금한 것이 있어서 여러 실험을 하였는데 strcpy(A, B)함수의 경우에는 문자열만 A 공간으로 복사하며
A = B는 얕은 복사가 된다. 하지만 std::string으로 문자열을 만든다면 A = B실행 시 깊은 복사가 실행된다는 것을 
알게 되었다.
*/