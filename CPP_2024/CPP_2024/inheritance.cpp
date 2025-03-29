#include <iostream>

class CTest {
public:
	CTest() { std::cout << "CTest()" << std::endl; }
	void Testfunc() { std::cout << "CTest::TestFunc()" << std::endl; }
};

class CTestEx : public CTest {
public:
	CTestEx() { std::cout << "CTestEx()" << std::endl; }
	void Testfunc() { std::cout << "CTestEx::TestFunc()" << std::endl; }
};

int main() {
	CTestEx a;
	CTest& b = a;
	a.Testfunc();
	b.Testfunc();

	return 0;
}

//프로그램 동작 순서: CTestEx 클래스로 a 객체 생성
//CTestEx는 CTest를 상속받고 있음으로 CTest의 기본 생성자 호출
//CTest클래스로 a객체를 참조
//a객체의 Testfunc함수 -> CTestEX::TestFunc()출력
//b객체의 Testfunc함수 -> CTest클래스이므로 CTest::TestFunc() 출력
//이것을 참조형식이라 하며 virtual 키워드를 사용하여 override한 것을 실형식이라 한다.
