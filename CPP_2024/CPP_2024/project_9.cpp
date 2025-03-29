//자동차	클래스와 타이어 클래스를 만들고, 타이어 4개를 자동차에 장착하는 프로그램

#include <iostream>

class Tire {
private:
	std::string tire_name;
	int position;

public:
	void set_name(std::string tire_name_) { tire_name = tire_name_; } //타이어 이름 설정
	void set_position(int position_) { position = position_; } //타이어 위치 설정
	void show_name() { std::cout << "종류: '" << tire_name << "' "; } //타이어 이름 출력
	void show_position() { std::cout << "위치: '" << position << "'"; } //타이어 위치 출력
};

class Car {
private:
	std::string car_name; //자동차 이름
	Tire* T = new Tire[4]; //타이어 4개 생성

public:
	Car(std::string car_name) : car_name(car_name) {} //car_name 이름 설정
	~Car() { delete[] T; } //타이어 동적 메모리 할당 해제
	//타이어 이름과 위치 설정
	void add_tire() {
		T[0].set_name("일호");
		T[1].set_name("이호");
		T[2].set_name("삼호");
		T[3].set_name("사호");

		for (int i = 0; i < 4; i++)
			T[i].set_position(i + 1);
	}
	//자동차 이름, 타이어 종류, 위치 출력
	void show() {
		std::cout << "자동차 이름: " << car_name << std::endl << std::endl << "<타이어 종류, 위치> " << std::endl;
		for (int i = 0; i < 4; i++) {
			T[i].show_name();
			T[i].show_position();
			std::cout << std::endl;
		}
	}
};

int main() {
	Car C("자동차"); //자동차 이름 설정, 객체 생성
	C.add_tire(); //타이어 추가
	C.show(); //자동차 이름, 타이어 종류, 위치 보여주기
	return 0;
}
