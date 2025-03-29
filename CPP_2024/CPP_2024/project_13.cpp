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
