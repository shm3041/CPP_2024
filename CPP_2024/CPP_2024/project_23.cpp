//���� ���� ���� ���α׷�

#include <iostream>
#include <windows.h> //system("cls"), system("PAUSE") ����� ���� include

//�� ���� class
class Entity {
	//����� ���� protected�� ��� ���� ����
protected:
	int customerId; //���� ID
	std::string customerName; //���� �̸�
	unsigned long long customerBalance; //���� �����ܰ�
public:
	//default parameter, ������, ��� ���� �ʱ�ȭ
	Entity(int customerId = 0, std::string customerName = "", unsigned long long customerBalance = 0)
		: customerId(customerId), customerName(customerName), customerBalance(customerBalance) {
	}

	int retCustomerId() { return customerId; } //����ID ã�� �� ���

	void deposiot(unsigned long long balance); //�Ա�
	void withdraw(unsigned long long balance); //���
	void showAccount(); //�� ���� ���
};

//�Ա�(���� �ܰ� �ݾ� �߰�)
void Entity::deposiot(unsigned long long balance) {
	customerBalance += balance;
	std::cout << "�Ա� �Ϸ�" << std::endl;
	system("PAUSE");
}

//���(���� �ܰ��� �ݾ� ����)
void Entity::withdraw(unsigned long long balance) {
	//���� ����Ϸ��� �ݾ��� ���¿� �ִ� �ݾװ� ���ų� �� ���ٸ� ��� ���
	//�׷��� �ʴٸ� �ܾ׺��� �޼��� ���
	if (balance <= customerBalance) {
		customerBalance -= balance;
		std::cout << "��� �Ϸ�" << std::endl;
		system("PAUSE");
	}
	else {
		std::cout << "����� �ܾ��� �����մϴ�." << std::endl;
		system("PAUSE");
	}
}

//�� ���� ���(���� ID, �̸�, �ܾ�)
void Entity::showAccount() {
	std::cout << "���� ID: " << customerId << std::endl;
	std::cout << "��   ��: " << customerName << std::endl;
	std::cout << "��   ��: " << customerBalance << std::endl;
	std::cout << std::endl;
}


//�� ���� ���� class
class Control : public Entity {
private:
	static int accountNumber; //�����Ǿ� �ִ� ���� ���� ����
	Entity* accountArr[10]; //�� 10���� �� ������ ���� �� �ִ� �迭
	//��ӹ��� ��� ����
	//int customerId (���� ID)
	//std::string customerName (���� �̸�)
	//unsigned long long customerBalance (���� �����ܰ�)
public:
	void makeAccount(); //���� ����
	void depositMoney(); //�Ա�
	void withdrawMoney(); //���
	void showAllAccount(); //��ü ������ ���

	void noAccount(); //���� ���� �� ����� �޼���
	void inputDW(std::string choiceDW); //�Ա�, ��� �� ���� �Է¹ޱ�
	void showInterface(); //�������̽�(Menu) ���
	int choice(); //���θ޴� ������
	void Run(Control& C); //main

	//��ü �Ҹ� �� �����Ǿ� �ִ� ��� ���� ����(�޸� �Ҵ� ����)
	~Control() {
		for (int i = 0; i < accountNumber; i++) {
			delete accountArr[i];
		}
	}
};


//���� ���� �����ϴ� ���� �ʱ�ȭ(static ����)
int Control::accountNumber = 0;

//���� ����
void Control::makeAccount() {
	//���� ���� �Է¹ޱ�
	system("cls");
	std::cout << "[���°���]" << std::endl;
	std::cout << "����ID: ";
	std::cin >> customerId;
	std::cout << "��  ��: ";
	std::cin >> customerName;
	std::cout << "�Աݾ�: ";
	std::cin >> customerBalance;

	//�����Ϸ��� ID�� �������� �ʴ´ٸ� ���¸� �����ϰ�, ���� ������ �����ϴ� ������ +1�� �Ѵ�
	bool makeFlag = false;
	for (int i = 0; i < accountNumber; i++) {
		if (customerId == accountArr[i]->retCustomerId()) { makeFlag = true; }
	}
	if (makeFlag == true) {
		std::cout << "������ ID�� ���°� �̹� �����Ǿ� �ֽ��ϴ�. �ٸ� ��ȣ�� ������ּ���!" << std::endl;
		system("PAUSE");
		return;
	}

	accountArr[accountNumber] = new Entity(customerId, customerName, customerBalance);
	accountNumber++;
	std::cout << "���°��� ����!" << std::endl;
	system("PAUSE");
}

//�Ա�
void Control::depositMoney() {
	//���� ������ ���°� ���ٸ� ���� ������ ��
	if (accountNumber == 0) {
		noAccount();
		return;
	}

	//���� ���� �Է¹ޱ�
	inputDW("�Ա�");

	//���� ã�� �� �ݾ� �߰�
	//��ġ�ϴ� ���� ������ ���ٸ� �޼��� ���
	bool depositFlag = false;
	for (int i = 0; i < accountNumber; i++) {
		if (customerId == accountArr[i]->retCustomerId()) { //Entity::retCustomerId()
			accountArr[i]->deposiot(customerBalance); //Entity::deposiot()
			depositFlag = true;
		}
	}
	if (depositFlag == false) {
		std::cout << "��ġ�ϴ� ����ID�� �����ϴ�!" << std::endl;
		system("PAUSE");
	}
}

//���
void Control::withdrawMoney() {
	//���� ������ ���°� ���ٸ� ���� ������ ��
	if (accountNumber == 0) {
		noAccount();
		return;
	}

	//���� ���� �Է¹ޱ�
	inputDW("���");

	//���� ã�� �� �ݾ� ����
	//��ġ�ϴ� ���� ������ ���ٸ� �޼��� ���
	bool withdrawFlag = false;
	for (int i = 0; i < accountNumber; i++) {
		if (customerId == accountArr[i]->retCustomerId()) {
			accountArr[i]->withdraw(customerBalance); //Entity::withdraw()
			withdrawFlag = true;
		}
	}
	if (withdrawFlag == false) {
		std::cout << "��ġ�ϴ� ����ID�� �����ϴ�!" << std::endl;
		system("PAUSE");
	}
}

//��ü ������ ���
void Control::showAllAccount() {
	//���� ������ ���°� ���ٸ� ���� ������ ��
	if (accountNumber == 0) {
		noAccount();
		return;
	}

	//��� ���� ���� ǥ��
	system("cls");
	std::cout << "[��� ���� ���� ǥ��]" << std::endl;
	for (int i = 0; i < accountNumber; i++) {
		accountArr[i]->showAccount(); //Entity::showAccount()
	}
	system("PAUSE");
}

//���� ���� �� �޼��� ���
void Control::noAccount() {
	system("cls");
	std::cout << "������ ���°� �����ϴ�." << std::endl;
	std::cout << "���� ���� �� �ٽ� �õ����ּ���" << std::endl;
	system("PAUSE");
}

//�Ա�, ��� �� ���� ���� �Է¹ޱ�
void Control::inputDW(std::string choiceDW) {
	system("cls");
	std::cout << "[ " << choiceDW << " ]" << std::endl;
	std::cout << "����ID: ";
	std::cin >> customerId;
	std::cout << choiceDW << "��: ";
	std::cin >> customerBalance;
}

//�������̽�(Menu)���
void Control::showInterface() {
	system("cls");
	std::cout << "-----Menu-----" << std::endl;
	std::cout << "1. ���°���" << std::endl; //Control::makeAccount()
	std::cout << "2. ��    ��" << std::endl; //Control::depositMoney()���� Entity::deposit() �ҷ��ͼ� ���¿� �ִ� �� ����
	std::cout << "3. ��    ��" << std::endl; //Control::withdrawMoney()���� Entity::withdraw() �ҷ��ͼ� ���¿� �ִ� �� ����
	std::cout << "4. �������� ��ü ���" << std::endl; //Control::showAllAccount()���� Entity::showAccount() �ҷ��ͼ� ���� ���� ���
	std::cout << "5. ���α׷� ����" << std::endl;
}

//���θ޴� ������
int Control::choice() {
	int input;
	std::cout << "����: ";
	std::cin >> input;
	return input;
}

//main
void Control::Run(Control& C) {
	C.showInterface(); //�������̽� ǥ��
	//choice�Լ����� �������� �޾ƿ�
	while (true) {
		switch (C.choice()) {
		case 1: //���� ����
			C.makeAccount();
			C.showInterface();
			break;
		case 2: //�Ա�
			C.depositMoney();
			C.showInterface();
			break;
		case 3: //���
			C.withdrawMoney();
			C.showInterface();
			break;
		case 4: //��ü ������ ���
			C.showAllAccount();
			C.showInterface();
			break;
		case 5: //���α׷� ����
			system("cls");
			std::cout << "���α׷��� �����մϴ�." << std::endl;
			return;
		default: //�߸��� ������ �Է� �� ���
			C.showInterface();
			std::cout << "1 ~ 5 �� �ϳ��� �������ּ���." << std::endl;
		}
	}
}

int main() {
	//��Ʈ�� ��ü ���� �� ����
	Control C;
	C.Run(C);

	return 0;
}

/*
�̹� ������ �ϸ� Ư�� �Լ��� ���� �� �� �Լ��� ��� ������ ���� ������ ���� ����� �����ߴ�.
���� �� Control::withdrawMoney �Լ����� �ݾ��� ����ϴ� �κи� �־�� ����,
����� �ݾ��� �Է¹޴� �κе� �־ �Ǵ��� �� �𸣰ھ ���� �ð� ����ߴ�.
�ᱹ Control::withdrawMoney�Լ������� ���¿��� �ݾ��� ����ϴ� �κи� �ְ� �Ǿ���.
�̷��� �ڵ带 ¥�� ���� ���߿� �ڵ带 ���� �� ���� ���� �� ���ұ� �����̴�.
�ּ��� �ִ� �͵� ���� �ڵ带 ���� �� �ִ��� �������� ������ �����ϸ� �־���.
�̹� �ڵ带 �ۼ��ϸ� �ڵ��� Ȯ�强�� ������, ����ó�� �κ��� �����ϸ� �ۼ��ߴµ� 
�׳� ��ɸ� ���������� ����ǰ� ¥�� �� ���� ��� ��������� ���� �ð��� �ɷȴ�.
�Ƹ� ���� �ǹ����� ���ϰ� �ִ� ����Ե鵵 �̷��� �κ��� �����ϸ� �ڵ带 �ۼ����� �ٵ� 
���� ����ϴٴ� ������ ������� ������ �ڵ带 �ۼ��� �� Ȯ�强, ������, ����ó�� �κ��� �׻� �����ϸ�
�ۼ��ؾ߰ڴٰ� �����ϰ� �Ǿ���. ���� ������ ��������.
*/