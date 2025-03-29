//���� 2���� �Է¹ް�, ���۷����� �����͸� �̿��Ͽ� �� ū ���� ����ϰ� a, b�� �������� ����ϴ� ���α׷�

#include <iostream>

bool bigger(int a, int b, int& big) { //���� a, b �� ���۷��� big �ޱ�
	//���� a�� �� ũ�ٸ� big���� a�� ���� �� false ����
	if (a > b) {
		big = a;
		return false;
	}
	//���� b�� �� ũ�ٸ� big���� b�� ���� �� false ����
	else if (a < b) {
		big = b;
		return false;
	}
	//���� ���� ���ٸ� big���� a�� ���� �� true ����
	else {
		big = a;
		return true;
	}
}

bool bigger(int a, int b, int* big) { //���� a, b �� big �ּ� �ޱ�
	//���� a�� �� ũ�ٸ� big���� a�� ���� �� false ����
	if (a > b) {
		*big = a;
		return false;
	}
	//���� b�� �� ũ�ٸ� big���� b�� ���� �� false ����
	else if (a < b) {
		*big = b;
		return false;
	}
	//���� ���� ���ٸ� big���� a�� ���� �� true ����
	else {
		*big = a;
		return true;
	}
}

int main() {
	int a, b; //����ڿ��� �Է¹��� �� ����
	int big; //a, b �� �� ū �� ����
	int flag; //���� �����ϸ� true �ٸ��ٸ� false

	std::cin >> a >> b; //a, b�� �Է¹ޱ�

	std::cout << "<���۷���>" << std::endl;
	flag = bigger(a, b, big); //bigger���� ���� �ٸ� ��� false(0), ���� ��� true(1)�� ���Ϲ޴´�.
	std::cout << big << std::endl; //bigger���� ���۷����� ������ big ���

	std::cout << "<������>" << std::endl;
	flag = bigger(a, b, &big); //bigger���� ���� �ٸ� ��� false(0), ���� ��� true(1)�� ���Ϲ޴´�.
	std::cout << big << std::endl; //bigger���� �����ͷ� ������ big ���

	if (flag == false) std::cout << "�ٸ���" << std::endl; //���� a, b�� �ٸ� ���
	else std::cout << "����" << std::endl; //���� a, b�� ���� ���

	return 0;
}

/*
���۷����� ������ �������� ����, �����ε��� ����, bool�ڷ����� �����ϰ� �ִ��� 
Ȯ���� �� �ִ� ���� ���������ϴ�. Ư�� bool�ڷ����� ��ҿ� ����� ���� ���� ��� 
����� �� �򰥷ȴµ� �̹� ������ �򰥸��� �κ��� �ٷ���� �� �� �־ ���ҽ��ϴ�.
*/