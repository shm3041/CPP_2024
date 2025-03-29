//���ø��� �̿��Ͽ� ȸ����� �˹ٻ��� ������ ����ϴ� ���α׷�

#include <iostream>

template <class T1, class T2> //��, �̸��� ���� T1, ���� �ڷ����� ���� T2 ���ø� ����
class SalaryEmployee { //ȸ���
private:
	T1 firstName; //��
	char initial; //�̴ϼ�
	T1 lastName; //�̸�
	T2 salary; //����
public:
	//��, �̴ϼ�, �̸�, ���� �ʱ�ȭ�ϴ� ������ / �Ű������� ���� T1, T2�� �ڷ����� �ٲ�
	SalaryEmployee<T1, T2>(T1 firstName = T1(), char initial = '\0', T1 lastName = T1(), T2 salary = T2())
		: firstName(firstName), initial(initial), lastName(lastName), salary(salary) {
	}
	void print() const { //ȸ��� ���� ���
		std::cout << firstName << lastName << initial << "�� ������ " << salary << "����" << std::endl;
	}
};

template <class T1, class T2> //��, �̸��� ���� T1, �ñ�, �ð��� ���� T2 ���ø� ����
class HourlyEmployee { //�˹ٻ�
private:
	T1 firstName; //��
	char initial; //�̴ϼ�
	T1 lastName; //�̸�
	T2 urgent, time; //�ñ�, �ð�
public:
	//��, �̴ϼ�, �̸�, �ñ�, �ð� �ʱ�ȭ�ϴ� ������ / �Ű������� ���� T1, T2�� �ڷ����� �ٲ�
	HourlyEmployee<T1, T2>(T1 firstName = T1(), char initial = '\0', T1 lastName = T1(), T2 urgent = T2(), T2 time = T2())
		: firstName(firstName), initial(initial), lastName(lastName), urgent(urgent), time(time) {
	}
	int calc() const { return urgent * time; } //�޿� ���
	void print() const { //�˹ٻ� ���� ���
		std::cout << firstName << lastName << initial << "�� �Ϸ� �޿��� " << calc() << "����" << std::endl;
	}
};

int main() {
	//ȸ��� ��ü ����
	SalaryEmployee<std::string, double> S1("ȸ", 'A', "���", 50.5); //string, double ���ø� ���ڸ� ���� ��ü ����
	SalaryEmployee<int, double> S2(1, 'B', 1, 100.5); //int, double ���ø� ���ڸ� ���� ��ü ����
	SalaryEmployee<char, int> S3('A', 'C', 'A', 100); //char, int ���ø� ���ڸ� ���� ��ü ����
	//ȸ��� ���� ���
	S1.print();
	S2.print();
	S3.print();

	//�˹ٻ� ��ü ����
	HourlyEmployee<std::string, double> H1("��", 'D', "�ٻ�", 1.1, 8); //string, double ���ø� ���ڸ� ���� ��ü ����
	HourlyEmployee<int, double> H2(1, 'E', 1, 2.1, 8); //int, double ���ø� ���ڸ� ���� ��ü ����
	HourlyEmployee<char, int> H3('A', 'F', 'A', 2, 8); //char, int ���ø� ���ڸ� ���� ��ü ����
	//�˹ٻ� ���� ���
	H1.print();
	H2.print();
	H3.print();

	return 0;
}

/*
�� �� �ڵ�� Employee Ŭ�������� ��, �̴ϼ�, �̸��� ��ӹ޾Ƽ� 
�̸� HourlyEmployee, SalaryEmployee Ŭ�������� ����Ͽ����ϴ�. 
��ü�� ������ ��ĳ������ �Ͽ� Employee* �ڷ������� ���� �迭���� �Ͽ��µ�, 
�̹� ���������� ���ø��� ����� �̼��Ͽ� ���� ���Ͽ����ϴ�.
��, default parameter�� ������ �� ���ø��� � ���·� �ʱ�ȭ ����� �ϴ��� ���� ������ ��ž����ϴ�.
���� ���ø��� ����Ͽ��� �� �⺻ �����ڸ� ����Ͽ� ��ü�� �����ϰ� �ʹٸ� 
SalaryEmployee<std::string, double> S0;�� ���� T1, T2�� �ڷ����� ��������� �մϴ�. 
�̹� ������ ���Ͽ� ���ø��� ������ �˰ԵǾ� �����Ͽ����ϴ�.
*/