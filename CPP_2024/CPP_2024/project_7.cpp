//계좌정보를 객체로 만들어 입금, 출금, 고객정보 출력, 잔액조회 기능을 구현하는 프로그램

#include <iostream>
class Bank {
public:
	const char* name;
	unsigned long long int id;
	unsigned long long int balance;

	void deposit(unsigned long long int balance_);
	void withdraw(unsigned long long int balance_);
	void show();
	void inquiry();
};


void Bank::deposit(unsigned long long int balance_) {
	std::cout << "금액을 " << balance_ << "만큼 입금합니다." << std::endl;
	balance += balance_;
}

void Bank::withdraw(unsigned long long int balance_) {
	std::cout << "금액을 " << balance_ << "만큼 출금합니다." << std::endl;
	//통장 잔고보다 같거나 작은 금액만 출금이 가능하도록 설정
	if (balance >= balance_) balance -= balance_;
	else std::cout << "잔액이 부족합니다!" << std::endl;
}

void Bank::show() {
	std::cout << "이름: " << name << std::endl;
	std::cout << "계좌번호: " << id << std::endl;
}

void Bank::inquiry() {
	std::cout << "잔액: " << balance << std::endl;
}

int main() {
	Bank B; //객체 선언
	//이름, 계좌번호, 통장잔액 입력
	B.name = "hanmok";
	B.id = 18446744073709551615;
	B.balance = 500000;

	//이름, 계좌번호, 통장잔액 출력
	B.show();
	B.inquiry();

	//입금, 통장잔고 출력
	B.deposit(50000); //입금할 금액을 매개변수로 전달
	B.inquiry();

	//출금, 통장잔고 출력
	B.withdraw(5000000); //출금할 금액을 매개변수로 전달
	B.inquiry();

	return 0;
}

/*
Bank 클래스에 있는 name에 “hanmok”이라는 문자열을 넣으려 했으나 방법을 몰라서 한참 헤매었다.
문자열을 name에 넣는 방법은 여러 가지가 있었지만, 나는 name을 const char* 형식으로 선언하여 문제를 해결하였다.
처음에는 strcpy를 사용했으나 바꾼 이유는 다른 헤더파일을 불러오자니 속도가 느려질 것 같았기 때문이며
여러 테스트를 해보았을 때 문제가 발견되지 않았기 때문이다. 평소에 구조체만 사용하여 코드를 짰기 때문에
클래스를 이용하여 코드를 짜는 것이 헷갈렸다. 이를 보완하기 위하여 구글링을 통해 클래스를 다루는 방법을 공부해야겠다.
*/