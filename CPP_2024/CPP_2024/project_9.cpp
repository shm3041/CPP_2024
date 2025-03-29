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

/*
이번 수업 전까지는 C언어로 코딩하는 방식을 그대로 가져와서 C++에서 코딩하여도 별 문제가 없는 줄 알았다.
하지만 이번 과제를 하며 클래스를 사용하여 프로그래밍을 하니 내가 얼마나 객체지향 언어의 장점을 못 살리고 있었는지
실감 되었다. 위 코드는 Car 클래스에서 타이어 이름을 T[0], T[1], T[2]와 같이 지정하여 수동으로 넣고 있으나
원래 생각은 참고코드 처럼 코딩하려 했다. 만약 tire_name 문자열이 public였다면 다른 방법을 시도할 수 있었지만
그렇게 하게 된다면 객체 지향 프로그래밍의 의미가 사라진다고 생각하여 private으로 놔두고 할 수 있는 방법을 계속 찾아봤다.
하지만 결국 클래스에 대한 개념 부족으로 하지 못하였다. 이번 과제를 통해 내가 부족한 것을 확실히 깨달았고 다음에
또 이와 같은 문제가 발생한다면 해결할 수 있도록 객체를 매개변수로 받는 방법, new와 포인터가 어떻게 동작하는지를
더욱 공부해야겠다고 느꼈다.
*/