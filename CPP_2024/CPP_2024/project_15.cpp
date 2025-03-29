//카메라를 대여하는 프로그램(만약 이미 카메라를 사용 중이라면 대여할 수 없음)
//객체가 이미 생성되어 있는지 확인 후 객체를 생성하는 프로그램

#include <iostream>

class Camera { //카메라 클래스
private:
	Camera() {} //기본 생성자
	static Camera* instance; //객체 저장
public:
	static Camera* getInstance(); //객체 생성
	static void delInstance(); //객체 삭제
	void capture() { std::cout << "Let's take a picture!!" << std::endl; }
};

Camera* Camera::instance = nullptr; //포인터 초기화
//객체가 유무 확인 후 객체를 생성, 객체가 이미 존재한다면 생성된 객체의 주소를 가르키게 함
Camera* Camera::getInstance() {
	if (!instance) { //생성된 객체가 없다면 실행
		instance = new Camera(); //객체 생성
		std::cout << "카메라를 성공적으로 대여하였습니다." << std::endl;
	}
	else std::cout << "이미 카메라를 사용 중입니다!" << std::endl;

	return instance; //객체 리턴
}
void Camera::delInstance() {
	if (instance) { //생성된 객체가 있다면 실행
		delete instance; //객체 메모리 할당 해제
		instance = nullptr; //instance 메모리 0으로 설정
		std::cout << "카메라 사용 해지" << std::endl;
	}
}

int main() {
	std::cout << "s1 카메라 대여" << std::endl;
	Camera* s1 = Camera::getInstance();
	std::cout << "s2 카메라 대여" << std::endl;
	Camera* s2 = Camera::getInstance();
	std::cout << "s3 카메라 대여" << std::endl;
	Camera* s3 = Camera::getInstance();
	s1->capture();

	Camera::delInstance(); //객체 메모리 할당 해제


	return 0;
}

/*
기존에는 포인터의 초기화 시 *ptr = 0 or *ptr = NULL과 같이 했었습니다. 
하지만 이렇게 할 경우 모호한 상황이 많아서 사용하기 애매했습니다. 
이 때문에 구글에 찾아보니 nullptr란 것이 있어서 사용했을 시 가독성이 더 좋아지며 
NULL은 0을 nullptr은 포인터를 뜻하여 이를 사용하게 되었습니다. 
이번 과제를 통하여 Singleton Pattern을 다루는 법을 알게 되어 좋았습니다.
*/