//사원의 정보를 employees 배열에 저장하고, 각 사원의 이름과 연봉을 출력하는 프로그램(상속을 이용함)
//Employee는 평사원, Manager은 매니저

#include <iostream>

class Employee { //평사원
protected:
	std::string name; //이름
	int salary; //월급
public:
	Employee() {} //기본 생성자
	Employee(std::string name, int salary) : name(name), salary(salary) {} //이름, 월급 오버라이딩

	int virtual calc() const { return salary * 12; } //연봉 계산 (매니저의 calc를 사용하기 위해 virtual 키워드 사용)
	void print() { std::cout << name << "의 연봉: " << calc() << std::endl; } //<이름>의 <연봉> 출력
};

class Manager : public Employee { //매니저 (평사원 상속)
private:
	int bonus; //보너스
public:
	Manager() {} //기본 생성자
	Manager(std::string name, int salary, int bonus) : Employee(name, salary), bonus(bonus) {} //이름, 월급, 보너스 오버라이딩
	int calc() const override { return salary * 12 + bonus; } //연봉 + 보너스 계산
};

int main() {
	Employee* employees[5]; //사원 배열 생성(매니저도 Employee를 상속받고 있기 때문에 Employee 생성)
	employees[0] = new Employee("직원1", 10000); //평사원1 메모리 할당
	employees[1] = new Employee("직원2", 20000); //평사원2 메모리 할당
	employees[2] = new Employee("직원3", 30000); //평사원3 메모리 할당
	employees[3] = new Employee("직원4", 40000); //평사원4 메모리 할당
	employees[4] = new Manager("매니저", 10000, 500000); //매니저 메모리 할당

	for (int i = 0; i < 5; i++) { employees[i]->print(); } //각 직원의 이름, 연봉 출력

	for (int i = 0; i < 5; i++) { delete employees[i]; } //각 사원의 메모리 할당 해제

	return 0;
}
