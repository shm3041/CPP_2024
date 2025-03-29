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

/*
이번 과제를 하며 상속을 거의 처음 써봤는데 개념이 부족해서 정말 어려웠다. 처음에는 Employee,
Manager의 객체를 관리하는 배열을 만드는 방법을 몰라서 클래스를 만들어서 관리하려 했다. 
하지만 상속을 잘못해서 계속 멤버 변수에 값이 안들어가는 상황이 발생하였다. 
계속 해봐도 컴파일 오류가 나서 구글에 검색하여 상속에 관한 개념을 익히고 처음부터 다시 코드를 짰다. 
매니저 클래스는 평사원 클래스를 상속하여 이에 관한 정보가 있으므로 Employee* 자료형으로 
Employee* employees[5];과 같이 배열을 만들어서 배열에 객체를 할당해주면 되는 것이었다. 
또한 calc함수를  Manager 클래스에서 만들어줬음에도 불구하고 연봉 계산을 했을 때 Employee의 calc함수를 사용하여
Manager의 연봉 계산이 제대로 안되는 문제가 발생하였다. 이는 virtual 키워드를 사용하여 손쉽게 해결할 수 있었다.
virtual 키워드를 사용할 때는 override 키워드로 명시를 해주는 것이 논리적 오류를 줄일 수 있어서 사용해주었다. 
이번 과제를 하며 상속이란 개념을 활용하여 만들 수 있는 것이 많아서 상속이 포인터보다 더 어렵다고 생각하였으며, 
상속과 관련된 예제를 많이 풀어보며 상속의 사용법을 많이 익혀야겠다고 느꼈다.
*/