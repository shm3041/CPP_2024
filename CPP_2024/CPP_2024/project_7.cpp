//���������� ��ü�� ����� �Ա�, ���, ������ ���, �ܾ���ȸ ����� �����ϴ� ���α׷�

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
	std::cout << "�ݾ��� " << balance_ << "��ŭ �Ա��մϴ�." << std::endl;
	balance += balance_;
}

void Bank::withdraw(unsigned long long int balance_) {
	std::cout << "�ݾ��� " << balance_ << "��ŭ ����մϴ�." << std::endl;
	//���� �ܰ��� ���ų� ���� �ݾ׸� ����� �����ϵ��� ����
	if (balance >= balance_) balance -= balance_;
	else std::cout << "�ܾ��� �����մϴ�!" << std::endl;
}

void Bank::show() {
	std::cout << "�̸�: " << name << std::endl;
	std::cout << "���¹�ȣ: " << id << std::endl;
}

void Bank::inquiry() {
	std::cout << "�ܾ�: " << balance << std::endl;
}

int main() {
	Bank B; //��ü ����
	//�̸�, ���¹�ȣ, �����ܾ� �Է�
	B.name = "hanmok";
	B.id = 18446744073709551615;
	B.balance = 500000;

	//�̸�, ���¹�ȣ, �����ܾ� ���
	B.show();
	B.inquiry();

	//�Ա�, �����ܰ� ���
	B.deposit(50000); //�Ա��� �ݾ��� �Ű������� ����
	B.inquiry();

	//���, �����ܰ� ���
	B.withdraw(5000000); //����� �ݾ��� �Ű������� ����
	B.inquiry();

	return 0;
}
