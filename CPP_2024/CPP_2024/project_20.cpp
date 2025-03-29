//템플릿을 이용하여 회사원과 알바생의 정보를 출력하는 프로그램

#include <iostream>

template <class T1, class T2> //성, 이름을 받을 T1, 월급 자료형을 받을 T2 템플릿 선언
class SalaryEmployee { //회사원
private:
	T1 firstName; //성
	char initial; //이니셜
	T1 lastName; //이름
	T2 salary; //월급
public:
	//성, 이니셜, 이름, 월급 초기화하는 생성자 / 매개변수에 따라 T1, T2의 자료형이 바뀜
	SalaryEmployee<T1, T2>(T1 firstName = T1(), char initial = '\0', T1 lastName = T1(), T2 salary = T2())
		: firstName(firstName), initial(initial), lastName(lastName), salary(salary) {
	}
	void print() const { //회사원 정보 출력
		std::cout << firstName << lastName << initial << "의 월급은 " << salary << "만원" << std::endl;
	}
};

template <class T1, class T2> //성, 이름을 받을 T1, 시급, 시간을 받을 T2 템플릿 선언
class HourlyEmployee { //알바생
private:
	T1 firstName; //성
	char initial; //이니셜
	T1 lastName; //이름
	T2 urgent, time; //시급, 시간
public:
	//성, 이니셜, 이름, 시급, 시간 초기화하는 생성자 / 매개변수에 따라 T1, T2의 자료형이 바뀜
	HourlyEmployee<T1, T2>(T1 firstName = T1(), char initial = '\0', T1 lastName = T1(), T2 urgent = T2(), T2 time = T2())
		: firstName(firstName), initial(initial), lastName(lastName), urgent(urgent), time(time) {
	}
	int calc() const { return urgent * time; } //급여 계산
	void print() const { //알바생 정보 출력
		std::cout << firstName << lastName << initial << "의 하루 급여는 " << calc() << "만원" << std::endl;
	}
};

int main() {
	//회사원 객체 생성
	SalaryEmployee<std::string, double> S1("회", 'A', "사원", 50.5); //string, double 템플릿 인자를 갖는 객체 생성
	SalaryEmployee<int, double> S2(1, 'B', 1, 100.5); //int, double 템플릿 인자를 갖는 객체 생성
	SalaryEmployee<char, int> S3('A', 'C', 'A', 100); //char, int 템플릿 인자를 갖는 객체 생성
	//회사원 정보 출력
	S1.print();
	S2.print();
	S3.print();

	//알바생 객체 생성
	HourlyEmployee<std::string, double> H1("알", 'D', "바생", 1.1, 8); //string, double 템플릿 인자를 갖는 객체 생성
	HourlyEmployee<int, double> H2(1, 'E', 1, 2.1, 8); //int, double 템플릿 인자를 갖는 객체 생성
	HourlyEmployee<char, int> H3('A', 'F', 'A', 2, 8); //char, int 템플릿 인자를 갖는 객체 생성
	//알바생 정보 출력
	H1.print();
	H2.print();
	H3.print();

	return 0;
}
