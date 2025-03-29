//직사각형, 직육면체의 정보 출력하기(virtual, override 사용)

#include <iostream>

class Rectangle { //직사각형
protected: //상속할 것이기 때문에 protected로 선언
	int height, width; //세로, 가로 길이
public:
	Rectangle() : height(0), width(0) {} //기본 생성자
	Rectangle(int height, int width) : height(height), width(width) {} //세로, 가로 길이 생성자 오버로딩
	~Rectangle() {} //소멸자

	int area_calc() { return height * width; } //넓이 계산
	int perimeter_calc() { return (height + width) * 2; } //둘레 계산
	//직사각형의 정보 출력(세로, 가로, 둘레, 넓이)
	//Cuboid에서는 Cuboid에서 만든 print함수를 사용해야 돼서 virtual 키워드 사용
	void virtual print() {
		std::cout << "직사각형의 세로: " << height << std::endl;
		std::cout << "직사각형의 가로: " << width << std::endl;
		std::cout << "직사각형의 둘레: " << perimeter_calc() << std::endl;
		std::cout << "직사각형의 넓이: " << area_calc() << std::endl;
		std::cout << std::endl;
	}
};

class Cuboid : public Rectangle { //직육면체
private:
	int high; //높이 (세로, 가로 길이는 Rectangle에서 상속받음)
public:
	Cuboid() : Rectangle(0, 0), high(0) {} //기본 생성자
	//세로, 가로, 높이 생성자 오버로딩
	//Rectangle에서 상속받은 세로, 가로 길이, Cuboid의 높이 변수 초기화
	Cuboid(int height, int width, int high) : Rectangle(height, width), high(high) {}
	~Cuboid() {} //소멸자

	int s_area_calc() { return 2 * ((width * height) + (width * high) + (height * high)); } //겉넓이 계산
	int volume_calc() { return height * width * high; } //부피 계산
	void print() override { //Rectangle의 print함수가 아닌 Cuboid의 print함수를 사용한다고 override 키워드로 명시
		std::cout << "직육면체의 세로 : " << height << std::endl;
		std::cout << "직육면체의 가로: " << width << std::endl;
		std::cout << "직육면체의 높이: " << high << std::endl;
		std::cout << "직육면체의 겉넓이: " << s_area_calc() << std::endl;
		std::cout << "직육면체의 부피: " << volume_calc() << std::endl;
		std::cout << std::endl;
	}
};

int main() {

	Rectangle* diagram[6]; //Rectangle*자료형으로 직사각형과 직육면체를 저장할 배열 생성

	diagram[0] = new Rectangle(1, 2); //객체 메모리 할당
	diagram[1] = new Rectangle(2, 3); //객체 메모리 할당
	diagram[2] = new Rectangle(3, 4); //객체 메모리 할당
	diagram[3] = new Cuboid(1, 2, 3); //객체 메모리 할당
	diagram[4] = new Cuboid(3, 4, 5); //객체 메모리 할당
	diagram[5] = new Cuboid(5, 6, 7); //객체 메모리 할당


	for (int i = 0; i < 6; i++) { diagram[i]->print(); } //도형 정보 출력

	for (int i = 0; i < 6; i++) { delete diagram[i]; } //diagram[i]에 있는 객체의 메모리 할당 해제

	return 0;
}

/*
이번 과제를 하며 저번 과제에서 배운 virtual과 override, 상속에 관한 개념을 모두 사용할 수 있어서 좋았다.
처음 상속에 관한 과제를 할 때는 왜 문제를 해결하지 못했는지 의문이 들 정도로 할만했다. 
하지만 상속을 잘못 사용하여 생기는 오류를 더욱 조심하면서 코딩해야겠다고 느꼈다. 
만약 실수를 한다고 하여도 어느 부분에서 무엇이 잘못 되었는지 눈치채고 이를 해결하기는 어려울 것 같기 때문이다.
*/