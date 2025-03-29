//����� ������ employees �迭�� �����ϰ�, �� ����� �̸��� ������ ����ϴ� ���α׷�(����� �̿���)
//Employee�� ����, Manager�� �Ŵ���

#include <iostream>

class Employee { //����
protected:
	std::string name; //�̸�
	int salary; //����
public:
	Employee() {} //�⺻ ������
	Employee(std::string name, int salary) : name(name), salary(salary) {} //�̸�, ���� �������̵�

	int virtual calc() const { return salary * 12; } //���� ��� (�Ŵ����� calc�� ����ϱ� ���� virtual Ű���� ���)
	void print() { std::cout << name << "�� ����: " << calc() << std::endl; } //<�̸�>�� <����> ���
};

class Manager : public Employee { //�Ŵ��� (���� ���)
private:
	int bonus; //���ʽ�
public:
	Manager() {} //�⺻ ������
	Manager(std::string name, int salary, int bonus) : Employee(name, salary), bonus(bonus) {} //�̸�, ����, ���ʽ� �������̵�
	int calc() const override { return salary * 12 + bonus; } //���� + ���ʽ� ���
};

int main() {
	Employee* employees[5]; //��� �迭 ����(�Ŵ����� Employee�� ��ӹް� �ֱ� ������ Employee ����)
	employees[0] = new Employee("����1", 10000); //����1 �޸� �Ҵ�
	employees[1] = new Employee("����2", 20000); //����2 �޸� �Ҵ�
	employees[2] = new Employee("����3", 30000); //����3 �޸� �Ҵ�
	employees[3] = new Employee("����4", 40000); //����4 �޸� �Ҵ�
	employees[4] = new Manager("�Ŵ���", 10000, 500000); //�Ŵ��� �޸� �Ҵ�

	for (int i = 0; i < 5; i++) { employees[i]->print(); } //�� ������ �̸�, ���� ���

	for (int i = 0; i < 5; i++) { delete employees[i]; } //�� ����� �޸� �Ҵ� ����

	return 0;
}

/*
�̹� ������ �ϸ� ����� ���� ó�� ��ôµ� ������ �����ؼ� ���� �������. ó������ Employee,
Manager�� ��ü�� �����ϴ� �迭�� ����� ����� ���� Ŭ������ ���� �����Ϸ� �ߴ�. 
������ ����� �߸��ؼ� ��� ��� ������ ���� �ȵ��� ��Ȳ�� �߻��Ͽ���. 
��� �غ��� ������ ������ ���� ���ۿ� �˻��Ͽ� ��ӿ� ���� ������ ������ ó������ �ٽ� �ڵ带 ®��. 
�Ŵ��� Ŭ������ ���� Ŭ������ ����Ͽ� �̿� ���� ������ �����Ƿ� Employee* �ڷ������� 
Employee* employees[5];�� ���� �迭�� ���� �迭�� ��ü�� �Ҵ����ָ� �Ǵ� ���̾���. 
���� calc�Լ���  Manager Ŭ�������� ������������� �ұ��ϰ� ���� ����� ���� �� Employee�� calc�Լ��� ����Ͽ�
Manager�� ���� ����� ����� �ȵǴ� ������ �߻��Ͽ���. �̴� virtual Ű���带 ����Ͽ� �ս��� �ذ��� �� �־���.
virtual Ű���带 ����� ���� override Ű����� ��ø� ���ִ� ���� ���� ������ ���� �� �־ ������־���. 
�̹� ������ �ϸ� ����̶� ������ Ȱ���Ͽ� ���� �� �ִ� ���� ���Ƽ� ����� �����ͺ��� �� ��ƴٰ� �����Ͽ�����, 
��Ӱ� ���õ� ������ ���� Ǯ��� ����� ������ ���� �����߰ڴٰ� ������.
*/