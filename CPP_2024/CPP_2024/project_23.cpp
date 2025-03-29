//은행 계좌 관리 프로그램

#include <iostream>
#include <windows.h> //system("cls"), system("PAUSE") 사용을 위해 include

//고객 정보 class
class Entity {
	//상속을 위해 protected로 멤버 변수 선언
protected:
	int customerId; //고객의 ID
	std::string customerName; //고객의 이름
	unsigned long long customerBalance; //고객의 통장잔고
public:
	//default parameter, 생성자, 멤버 변수 초기화
	Entity(int customerId = 0, std::string customerName = "", unsigned long long customerBalance = 0)
		: customerId(customerId), customerName(customerName), customerBalance(customerBalance) {
	}

	int retCustomerId() { return customerId; } //계좌ID 찾을 때 사용

	void deposiot(unsigned long long balance); //입금
	void withdraw(unsigned long long balance); //출금
	void showAccount(); //고객 정보 출력
};

//입금(현재 잔고에 금액 추가)
void Entity::deposiot(unsigned long long balance) {
	customerBalance += balance;
	std::cout << "입금 완료" << std::endl;
	system("PAUSE");
}

//출금(현재 잔고에서 금액 감소)
void Entity::withdraw(unsigned long long balance) {
	//만약 출금하려는 금액이 계좌에 있는 금액과 같거나 더 많다면 출금 허용
	//그렇지 않다면 잔액부족 메세지 출력
	if (balance <= customerBalance) {
		customerBalance -= balance;
		std::cout << "출금 완료" << std::endl;
		system("PAUSE");
	}
	else {
		std::cout << "출금할 잔액이 부족합니다." << std::endl;
		system("PAUSE");
	}
}

//고객 정보 출력(계좌 ID, 이름, 잔액)
void Entity::showAccount() {
	std::cout << "계좌 ID: " << customerId << std::endl;
	std::cout << "이   름: " << customerName << std::endl;
	std::cout << "잔   액: " << customerBalance << std::endl;
	std::cout << std::endl;
}


//고객 정보 관리 class
class Control : public Entity {
private:
	static int accountNumber; //생성되어 있는 계좌 개수 저장
	Entity* accountArr[10]; //총 10명의 고객 정보를 담을 수 있는 배열
	//상속받은 멤버 변수
	//int customerId (고객의 ID)
	//std::string customerName (고객의 이름)
	//unsigned long long customerBalance (고객의 통장잔고)
public:
	void makeAccount(); //계좌 개설
	void depositMoney(); //입금
	void withdrawMoney(); //출금
	void showAllAccount(); //전체 고객정보 출력

	void noAccount(); //계정 없을 때 출력할 메세지
	void inputDW(std::string choiceDW); //입금, 출금 시 정보 입력받기
	void showInterface(); //인터페이스(Menu) 출력
	int choice(); //메인메뉴 선택지
	void Run(Control& C); //main

	//객체 소멸 시 생성되어 있는 모든 계좌 삭제(메모리 할당 해제)
	~Control() {
		for (int i = 0; i < accountNumber; i++) {
			delete accountArr[i];
		}
	}
};


//계좌 개수 저장하는 변수 초기화(static 변수)
int Control::accountNumber = 0;

//계좌 개설
void Control::makeAccount() {
	//계좌 정보 입력받기
	system("cls");
	std::cout << "[계좌개설]" << std::endl;
	std::cout << "계좌ID: ";
	std::cin >> customerId;
	std::cout << "이  름: ";
	std::cin >> customerName;
	std::cout << "입금액: ";
	std::cin >> customerBalance;

	//생성하려는 ID가 존재하지 않는다면 계좌를 생성하고, 계좌 개수를 저장하는 변수에 +1을 한다
	bool makeFlag = false;
	for (int i = 0; i < accountNumber; i++) {
		if (customerId == accountArr[i]->retCustomerId()) { makeFlag = true; }
	}
	if (makeFlag == true) {
		std::cout << "동일한 ID의 계좌가 이미 생성되어 있습니다. 다른 번호를 사용해주세요!" << std::endl;
		system("PAUSE");
		return;
	}

	accountArr[accountNumber] = new Entity(customerId, customerName, customerBalance);
	accountNumber++;
	std::cout << "계좌개설 성공!" << std::endl;
	system("PAUSE");
}

//입금
void Control::depositMoney() {
	//만약 생성된 계좌가 없다면 계좌 생성할 것
	if (accountNumber == 0) {
		noAccount();
		return;
	}

	//계좌 정보 입력받기
	inputDW("입금");

	//계좌 찾기 및 금액 추가
	//일치하는 계좌 정보가 없다면 메세지 출력
	bool depositFlag = false;
	for (int i = 0; i < accountNumber; i++) {
		if (customerId == accountArr[i]->retCustomerId()) { //Entity::retCustomerId()
			accountArr[i]->deposiot(customerBalance); //Entity::deposiot()
			depositFlag = true;
		}
	}
	if (depositFlag == false) {
		std::cout << "일치하는 계좌ID가 없습니다!" << std::endl;
		system("PAUSE");
	}
}

//출금
void Control::withdrawMoney() {
	//만약 생성된 계좌가 없다면 계좌 생성할 것
	if (accountNumber == 0) {
		noAccount();
		return;
	}

	//계좌 정보 입력받기
	inputDW("출금");

	//계좌 찾기 및 금액 감소
	//일치하는 계좌 정보가 없다면 메세지 출력
	bool withdrawFlag = false;
	for (int i = 0; i < accountNumber; i++) {
		if (customerId == accountArr[i]->retCustomerId()) {
			accountArr[i]->withdraw(customerBalance); //Entity::withdraw()
			withdrawFlag = true;
		}
	}
	if (withdrawFlag == false) {
		std::cout << "일치하는 계좌ID가 없습니다!" << std::endl;
		system("PAUSE");
	}
}

//전체 고객정보 출력
void Control::showAllAccount() {
	//만약 생성된 계좌가 없다면 계좌 생성할 것
	if (accountNumber == 0) {
		noAccount();
		return;
	}

	//모든 계좌 정보 표시
	system("cls");
	std::cout << "[모든 계좌 정보 표시]" << std::endl;
	for (int i = 0; i < accountNumber; i++) {
		accountArr[i]->showAccount(); //Entity::showAccount()
	}
	system("PAUSE");
}

//계좌 없을 시 메세지 출력
void Control::noAccount() {
	system("cls");
	std::cout << "생성된 계좌가 없습니다." << std::endl;
	std::cout << "계좌 생성 후 다시 시도해주세요" << std::endl;
	system("PAUSE");
}

//입금, 출금 시 계좌 정보 입력받기
void Control::inputDW(std::string choiceDW) {
	system("cls");
	std::cout << "[ " << choiceDW << " ]" << std::endl;
	std::cout << "계좌ID: ";
	std::cin >> customerId;
	std::cout << choiceDW << "액: ";
	std::cin >> customerBalance;
}

//인터페이스(Menu)출력
void Control::showInterface() {
	system("cls");
	std::cout << "-----Menu-----" << std::endl;
	std::cout << "1. 계좌개설" << std::endl; //Control::makeAccount()
	std::cout << "2. 입    금" << std::endl; //Control::depositMoney()에서 Entity::deposit() 불러와서 계좌에 있는 돈 증가
	std::cout << "3. 출    금" << std::endl; //Control::withdrawMoney()에서 Entity::withdraw() 불러와서 계좌에 있는 돈 감소
	std::cout << "4. 계좌정보 전체 출력" << std::endl; //Control::showAllAccount()에서 Entity::showAccount() 불러와서 계좌 정보 출력
	std::cout << "5. 프로그램 종료" << std::endl;
}

//메인메뉴 선택지
int Control::choice() {
	int input;
	std::cout << "선택: ";
	std::cin >> input;
	return input;
}

//main
void Control::Run(Control& C) {
	C.showInterface(); //인터페이스 표시
	//choice함수에서 선택지를 받아옴
	while (true) {
		switch (C.choice()) {
		case 1: //계좌 생성
			C.makeAccount();
			C.showInterface();
			break;
		case 2: //입금
			C.depositMoney();
			C.showInterface();
			break;
		case 3: //출금
			C.withdrawMoney();
			C.showInterface();
			break;
		case 4: //전체 고객정보 출력
			C.showAllAccount();
			C.showInterface();
			break;
		case 5: //프로그램 종료
			system("cls");
			std::cout << "프로그램을 종료합니다." << std::endl;
			return;
		default: //잘못된 선택지 입력 시 출력
			C.showInterface();
			std::cout << "1 ~ 5 중 하나를 선택해주세요." << std::endl;
		}
	}
}

int main() {
	//컨트롤 객체 생성 및 실행
	Control C;
	C.Run(C);

	return 0;
}

/*
이번 과제를 하며 특정 함수를 만들 때 그 함수에 어떠한 내용이 들어가야 할지에 관해 고민을 오래했다.
예를 들어서 Control::withdrawMoney 함수에서 금액을 출금하는 부분만 넣어야 할지,
출금할 금액을 입력받는 부분도 넣어도 되는지 잘 모르겠어서 오랜 시간 고민했다.
결국 Control::withdrawMoney함수에서는 계좌에서 금액을 출금하는 부분만 넣게 되었다.
이렇게 코드를 짜는 것이 나중에 코드를 봤을 때 보기 편할 것 같았기 때문이다.
주석을 넣는 것도 추후 코드를 읽을 때 최대한 불편함이 없도록 생각하며 넣었다.
이번 코드를 작성하며 코드의 확장성과 가독성, 예외처리 부분을 생각하며 작성했는데 
그냥 기능만 정상적으로 수행되게 짜는 것 보다 배는 어려웠으며 많은 시간이 걸렸다.
아마 현재 실무에서 일하고 있는 선배님들도 이러한 부분을 생각하며 코드를 작성했을 텐데 
정말 대단하다는 생각이 들었으며 앞으로 코드를 작성할 때 확장성, 가독성, 예외처리 부분을 항상 생각하며
작성해야겠다고 생각하게 되었다. 정말 유익한 과제였다.
*/