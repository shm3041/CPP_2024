//ȸ���, �˹ٻ��� ����, �ñ� ��� ���α׷�

#include <iostream>
class Employee { //�߻� Ŭ����
protected:
	std::string firstName; //��
	char initial; //�̴ϼ�
	std::string lastName; //�̸�

public:
	Employee() {} //�⺻ ������
	Employee(std::string firstName, char initial, std::string lastName) //��, �̴ϼ�, �̸� �����ε�
		: firstName(firstName), initial(initial), lastName(lastName) {
	} //��� ���� �ʱ�ȭ
	virtual void print() const = 0; //�߻� Ŭ���� �Լ�
	virtual ~Employee() {} //�Ҹ���(������)
};

class SalaryEmployee : public Employee {//�������� ����, Employee ���
private:
	int salary; //����
public:
	SalaryEmployee() {} //�⺻ ������
	//Employee�� ��, �̴ϼ�, �̸� �ʱ�ȭ, Salary�� ���� ���� �ʱ�ȭ
	SalaryEmployee(std::string firstName, char initial, std::string lastName, int salary)
		: Employee(firstName, initial, lastName), salary(salary) {
	}
	void print() const override { //���� ���(�������̵�)
		std::cout << firstName << lastName << initial << "�� ������ " << salary << "����" << std::endl;
	}
	~SalaryEmployee() override {} //�Ҹ���(�������̵�)
};

class HourlyEmployee : public Employee { //�ñ�, Employee ���
private:
	int urgent, time; //�ñ�, �ð�
public:
	HourlyEmployee() {} //�⺻ ������
	//Employee�� ��, �̴ϼ�, �̸� �ʱ�ȭ, Hourly�� �ñ�, �ð� ���� �ʱ�ȭ
	HourlyEmployee(std::string firstName, char initial, std::string lastName, int urgent, int time)
		: Employee(firstName, initial, lastName), urgent(urgent), time(time) {
	}
	//�ñ� ���
	int calc() const { return urgent * time; }
	void print() const override { //�Ϸ� �޿� ���(�������̵�)
		std::cout << firstName << lastName << initial << "�� �Ϸ� �޿��� " << calc() << "����" << std::endl;
	}
	~HourlyEmployee() override {} //�Ҹ���(�������̵�)
};

int main() {
	Employee* E[6]; //Employee* �ڷ������� ��ü ����(��ĳ����)

	E[0] = new SalaryEmployee("����", 'A', "����", 100); //��ü �޸� �Ҵ�
	E[1] = new SalaryEmployee("����", 'B', "����", 200); //��ü �޸� �Ҵ�
	E[2] = new SalaryEmployee("����", 'C', "����", 300); //��ü �޸� �Ҵ�
	E[3] = new HourlyEmployee("��", 'D', "�ٻ�", 1, 8); //��ü �޸� �Ҵ�
	E[4] = new HourlyEmployee("��", 'E', "�ٻ�", 2, 8); //��ü �޸� �Ҵ�
	E[5] = new HourlyEmployee("��", 'F', "�ٻ�", 3, 8); //��ü �޸� �Ҵ�

	for (int i = 0; i < 6; i++) { E[i]->print(); } //��ü ���� ���(��, �̸�, �̴ϼ�, �޿�(����)

	for (int i = 0; i < 6; i++) { delete E[i]; } //��ü �޸� �Ҵ� ����

	return 0;
}

/*
�̹� ������ �ϸ� �Ҹ��ڿ� virtual Ű���带 ����� �� �ִٴ� �Ͱ� ��ĳ������ �Ͽ� �����͸� ������ ��� 
�̰� �Ҹ�� �� Employee Ŭ������ �Ҹ��ڸ� ȣ���ϰ�, HourlyEmployee, SalaryEmployee Ŭ������ �Ҹ��ڴ� 
ȣ������ �ʴ´ٴ� ���� �˰� �Ǿ����ϴ�. ���� �̸� �ذ��ϱ� ���Ͽ� virtual Ű���带 �Ҹ��ڿ� ����Ͽ� 
�������Ŀ��� ���������� ������־����ϴ�.
�߻� Ŭ������ �̹� ������ ���� ���� �Ǿ� �������� ��� �ϴ��� �˰� �Ǿ����ϴ�.
*/