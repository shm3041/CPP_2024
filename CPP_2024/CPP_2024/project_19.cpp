//회사원, 알바생의 월급, 시급 계산 프로그램

#include <iostream>
class Employee { //추상 클래스
protected:
	std::string firstName; //성
	char initial; //이니셜
	std::string lastName; //이름

public:
	Employee() {} //기본 생성자
	Employee(std::string firstName, char initial, std::string lastName) //성, 이니셜, 이름 오버로딩
		: firstName(firstName), initial(initial), lastName(lastName) {
	} //멤버 변수 초기화
	virtual void print() const = 0; //추상 클래스 함수
	virtual ~Employee() {} //소멸자(실형식)
};

class SalaryEmployee : public Employee {//고정적인 월급, Employee 상속
private:
	int salary; //월급
public:
	SalaryEmployee() {} //기본 생성자
	//Employee의 성, 이니셜, 이름 초기화, Salary의 월급 변수 초기화
	SalaryEmployee(std::string firstName, char initial, std::string lastName, int salary)
		: Employee(firstName, initial, lastName), salary(salary) {
	}
	void print() const override { //월급 출력(오버라이딩)
		std::cout << firstName << lastName << initial << "의 월급은 " << salary << "만원" << std::endl;
	}
	~SalaryEmployee() override {} //소멸자(오버라이딩)
};

class HourlyEmployee : public Employee { //시급, Employee 상속
private:
	int urgent, time; //시급, 시간
public:
	HourlyEmployee() {} //기본 생성자
	//Employee의 성, 이니셜, 이름 초기화, Hourly의 시급, 시간 변수 초기화
	HourlyEmployee(std::string firstName, char initial, std::string lastName, int urgent, int time)
		: Employee(firstName, initial, lastName), urgent(urgent), time(time) {
	}
	//시급 계산
	int calc() const { return urgent * time; }
	void print() const override { //하루 급여 출력(오버라이딩)
		std::cout << firstName << lastName << initial << "의 하루 급여는 " << calc() << "만원" << std::endl;
	}
	~HourlyEmployee() override {} //소멸자(오버라이딩)
};

int main() {
	Employee* E[6]; //Employee* 자료형으로 객체 관리(업캐스팅)

	E[0] = new SalaryEmployee("월급", 'A', "쟁이", 100); //객체 메모리 할당
	E[1] = new SalaryEmployee("월급", 'B', "쟁이", 200); //객체 메모리 할당
	E[2] = new SalaryEmployee("월급", 'C', "쟁이", 300); //객체 메모리 할당
	E[3] = new HourlyEmployee("알", 'D', "바생", 1, 8); //객체 메모리 할당
	E[4] = new HourlyEmployee("알", 'E', "바생", 2, 8); //객체 메모리 할당
	E[5] = new HourlyEmployee("알", 'F', "바생", 3, 8); //객체 메모리 할당

	for (int i = 0; i < 6; i++) { E[i]->print(); } //객체 정보 출력(성, 이름, 이니셜, 급여(월급)

	for (int i = 0; i < 6; i++) { delete E[i]; } //객체 메모리 할당 해제

	return 0;
}

/*
이번 과제를 하며 소멸자에 virtual 키워드를 사용할 수 있다는 것과 업캐스팅을 하여 데이터를 관리할 경우 
이가 소멸될 때 Employee 클래스의 소멸자만 호출하고, HourlyEmployee, SalaryEmployee 클래스의 소멸자는 
호출하지 않는다는 것을 알게 되었습니다. 따라서 이를 해결하기 위하여 virtual 키워드를 소멸자에 사용하여 
참조형식에서 실형식으로 만들어주었습니다.
추상 클래스도 이번 수업을 통해 배우게 되어 디자인을 어떻게 하는지 알게 되었습니다.
*/