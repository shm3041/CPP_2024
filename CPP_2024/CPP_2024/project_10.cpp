//타이어 개수, 주행거리 입력받아서 주행 후 타이어 내구도 출력, 내구도 0인 타이어 교체, 교체 후 타이어 내구도를 출력하는 프로그램

#include <iostream>
#include <string> //std::string을 사용하기 위해 
#include <ctime> //srand(time(NULL)) 사용을 위해

int tire_size = 0; //타이어 개수 입력받기 위한 변수

//랜덤 내구도를 위한 함수
int rand_tire_durability(int tire_size) {
	return rand() % 10 + 5;
}

//타이어 클래스
class Tire {
private:
	std::string tire_name; //타이어 이름
	int position; //타이어 위치
	int durability; //타이어 내구도

public:
	void set_name(std::string tire_name) { this->tire_name = tire_name; } //타이어 이름 설정
	void set_position(int position) { this->position = position; } //타이어 위치 설정
	void set_durability() { this->durability = rand_tire_durability(tire_size); } //타이어 내구도 설정

	void sub_durability() { this->durability -= 1; } //타이어 내구도 감소

	int ret_tire_value() { return this->durability; } //타이어 내구도 리턴

	void show_name() { std::cout << "이름: '" << this->tire_name << "' "; } //타이어 이름 출력
	void show_position() { std::cout << "위치: '" << this->position << "' "; } //타이어 위치 출력
	void show_durability() {
		if (this->durability <= 0) std::cout << "내구도가 다 되었습니다."; //타이어 내구도가 0보다 작거나 같을 시 출력
		else std::cout << "내구도: '" << this->durability << "' "; //타이어 내구도가 0보다 크면 내구도 출력
	}
};

class Car {
private:
	std::string car_name; //자동차 이름 
	Tire* T; //타이어 객체 포인터 선언
	int run_metter; //주행거리
	int re_tire_count; //타이어 교체 내역 카운트

public:
	Car(std::string car_name) //기본 생성자(자동차 이름)
		: car_name(car_name) {
	}
	~Car() { delete[] T; } //소멸자(객체 배열 메모리 할당 해제)

	void set_tire() { //타이어 생성, 값 세팅
		T = new Tire[tire_size]; //tire_size만큼 메모리 공간 할당

		//타이어 값 설정(이름, 위치, 내구도)
		for (int i = 0; i < tire_size; i++) {
			T[i].set_name("한국 타이어");
			T[i].set_position(i + 1);
			T[i].set_durability();
		}
	}

	void get_tire() { //타이어 정보 출력(타이어 이름, 위치, 내구도)
		std::cout << "<타이어 정보>" << std::endl;
		for (int i = 0; i < tire_size; i++) {
			T[i].show_name(), T[i].show_position(), T[i].show_durability();
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	void re_tire(int position) { //타이어 교체(내구도 재설정)
		this->T[position].set_durability();
	}

	int run(int run_metter, int i) { //주행
		i++;
		std::cout << "현재 " << i << "km 입니다." << std::endl;
		this->run_metter = i; //총 주행거리에 현재 주행거리 추가

		for (int k = 0; k < tire_size; k++) {
			T[k].sub_durability();
		}

		if (run_metter > i) return run(run_metter, i); //만약 현재 주행거리가 총 주행거리보다 작다면 run함수 실행 (재귀함수)
		else return 0; //만약 현재 주행거리가 총 주행거리보다 같거나 크다면 재귀함수 종료
	}

	void show() { //차 이름, 타이어 개수, 주행거리 출력
		std::cout << std::endl;
		std::cout << "<자동차 정보>" << std::endl;
		std::cout << "차 이름: " << car_name << std::endl;
		std::cout << "타이어 개수: " << tire_size << "개" << std::endl;
		std::cout << "주행 거리: " << run_metter << "km" << std::endl;
		std::cout << std::endl;
	}

	void after_run() { //주행 후 자동차 점검하는 함수

		//주행 후 타이어 위치, 내구도 출력
		std::cout << "<주행 후 내구도>" << std::endl;
		for (int i = 0; i < tire_size; i++) {
			T[i].show_position();
			T[i].show_durability();
			std::cout << std::endl;
		}
		std::cout << std::endl;


		//타이어 내구도가 0 이하라면 교체 내역 +1
		re_tire_count = 0;
		for (int i = 0; i < tire_size; i++) {
			if (T[i].ret_tire_value() <= 0)
				re_tire_count++; //만약 타이어 내구도가 0 이하라면 count++
		}

		//타이어 교체
		for (int i = 0; i < tire_size; i++) {
			if (T[i].ret_tire_value() <= 0)
				re_tire(i); //만약 타이어 내구도가 0 이하라면 타이어를 교체
		}

		//교체 후 타이어 위치, 내구도 출력
		if (re_tire_count != 0) { //만약 타이어 교체 내역이 있다면 실행
			std::cout << "<교체 후 내구도>" << std::endl;
			for (int i = 0; i < tire_size; i++) {
				T[i].show_position();
				T[i].show_durability();
				std::cout << std::endl;
			}
		}
		else std::cout << "교체할 타이어가 없습니다." << std::endl; //타이어 교체 내역이 없다면 실행
		//std::cout << re_tire_count;

		std::cout << std::endl;
	}
};

int main() {
	srand(time(NULL)); // 랜덤 값을 위한 선언

	//타이어 개수 입력
	std::cout << "추가할 타이어 개수: ";
	std::cin >> tire_size;

	//자동차 생성 (타이어 설정, 출력)
	Car C("자동차");
	C.set_tire(); //설정
	C.get_tire(); //출력

	C.show(); //차 이름, 타이어 개수, 주행거리 출력

	int run_metter;
	std::cout << "주행 거리 입력: ";
	std::cin >> run_metter;
	C.run(run_metter, 0); //매개변수로 주행거리, 현재 주행 횟수 받기

	std::cout << std::endl << "--------- 모든 주행을 마쳤습니다 ---------";
	C.show(); //차 이름, 타이어 개수, 주행거리 출력
	C.after_run(); //주행 후 타이어 내구도 출력, 내구도 0인 타이어 교체, 교체 후 타이어 내구도 출력

	return 0;
}
