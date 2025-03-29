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
