//default parameter, �����ε�

#include <iostream>
#include <cmath> //����(floor)�� ����ϱ� ���� �ҷ���

void print(int n = 3) { //default parameter ���(�Ű����� ���� ���� ��� n = 3, �Ű������� ���� ��� n = �Ű�����
	for (int i = 0; i < n; i++) { //n�� Hello ���
		std::cout << "Hello" << std::endl;
	}
}

void print(double n) { //double�ڷ��� �����ε�
	for (double i = -5; i < floor(n); i++) { //floor�Լ��� �Ű����� n�� ���� ����
		std::cout << "Bye" << std::endl;
	}
}

void print(char n) { //char�ڷ��� �����ε�
	//�ƽ�Ű�ڵ� 97�� a�̸� 98�� b, 99�� c�� ���� a-z���� 1�� �����Ѵ�. ���� -96�� �ϸ� a�� �޾ƿ� �� world�� 1ȸ, b�� �޾ƿ� �� world�� 2ȸ ��µȴ�.
	for (int i = 0; i < n - 96; i++) {
		std::cout << "world" << std::endl;
	}
}

int main() {
	print(); //print(int n = 3) - �Ű������� �����Ƿ� n = 3�� ��
	print(2); //print(int n = 2) - �Ű������� �����Ƿ� n = 2�� ��
	print(-3.8); //print(double n) - double�ڷ��� �����ε�
	print('a'); //print(char n) - char�ڷ��� �����ε�

	return 0;
}

/*
ó�� �� ������ �޾��� ���� default parameter�� �򰥷��� print() �Լ��� �ϳ� ����� print(int n = 3)�� �������.
������ �������� ���� �ʾҰ�, ��ǻ�ʹ� �� 2���� ������ �� ���� �� ���Ƽ� print()�� ���ִ� �������� �Ǿ���. 
���Ű����� n�� double ���� ��� ��bye�� n�� ���(����)���� ó������ ������ ������ �������� �� ���� ������ �Ͽ��µ�,
�����̶�� ���� ������ ������ �� ���Ƽ� ã�ƺô��� �����̶� ���� ���� �����Ͽ���. ���� ���ۿ� ������ �˻��� �Ͽ� 
����(i < (int)(n / 1))���� ����(i < floor(n))���� �ڵ带 �����Ͽ���.
*/