//������ �����ε��� �̿��� �迭�� ����, ����, equal, ����������, ���Կ����� ����

#include <iostream>
#include <time.h> //rand(), srand()

class op {
private:
	int* n; //�迭
	int size; //�迭�� ������
public:
	//������(default parameter) �����ε�
	op(int size = 0) : size(size) {
		n = new int[size]; //size��ŭ ���� �޸� �Ҵ�
		for (int i = 0; i < size; i++) { n[i] = 0; } //�迭�� ���� �ʱ�ȭ
	}

	void insert(); //�迭�� ���� ����
	void show(); //�迭�� ���� ���

	op operator+ (const op& x); //�迭�� ����
	op operator- (const op& x); //�迭�� ����
	bool operator== (const op& x); //�迭�� equal
	op& operator++ (); //����������(����)
	op& operator=(const op& x); // ���� ������
	~op() { delete[] n; } //��ü �Ҹ� �� �迭 n �޸� �Ҵ� ����
};

//�迭�� ���� ����
void op::insert() {
	//�迭�� ������ ��(1 ~ 10)�� ����
	for (int i = 0; i < size; i++) {
		n[i] = rand() % 10 + 1;
	}
}

//�迭�� ���� ���
void op::show() {
	for (int i = 0; i < size; i++) {
		std::cout << n[i] << " ";
	}
	std::cout << std::endl;
}

//�迭 A�� �迭 B�� �ִ� ������ ����
op op::operator+ (const op& x) {
	op tmp(size);
	for (int i = 0; i < size; i++) {
		tmp.n[i] = n[i] + x.n[i];
	}
	return tmp;
}

//�迭 A�� �迭 B�� �ִ� ������ ����
op op::operator- (const op& x) {
	op tmp(size);
	for (int i = 0; i < size; i++) {
		tmp.n[i] = n[i] - x.n[i];
	}
	return tmp;
}

//�迭 A�� �迭 B�� ���Ұ� �������� Ȯ���ϴ� ������
bool op::operator== (const op& x) {
	//���� �ϳ��� �ٸ� ���Ұ� �ִٸ� false ����
	//���� ��� ���Ұ� ���ٸ� true ����
	for (int i = 0; i < size; i++) {
		if (n[i] != x.n[i]) return false;
	}
	return true;
}

//�迭�� �ִ� ���ҿ� ���� ���������� ���
op& op::operator++() {
	for (int i = 0; i < size; i++) {
		n[i]++;
	}
	return *this;
}

//���� ���� �����ڸ� ������ ���� ���¿��� C = A + B or C = A - B�� �Ѵٸ� C�� �ӽ� ��ü tmp��
//�޸� �ּҸ� ����Ű�� �Ǿ����(���� ����)
//���Ŀ� tmp�� �Ҹ��ڰ� ȣ��Ǿ n�� �޸� �Ҵ� ������ �ع����ٸ�
//��ü C�� tmp�� ��� ���� n�� �޸� �ּҸ� ����Ű�� �ֱ� ������ ������ �߻���.
//���� ���� �����ڸ� ����� �־ �� ������ �ذ���.(���� ����)
op& op::operator=(const op& x) {
	//size�� ��� ��ü�� �����ϴ� �迭 n�� �ִ� ���Ҹ� this->n���� �Ű���
	for (int i = 0; i < size; i++) {
		n[i] = x.n[i];
	}
	return *this;
}

int main() {
	srand(time(NULL)); //���� ������ ���� ���

	//�迭�� ũ�� �Է¹ޱ�
	int size;
	std::cout << "��ü�� ũ�⸦ �Է��ϼ���: ";
	std::cin >> size;

	//��ü ����
	op A(size);
	op B(size);
	op C(size);

	//��ü A, B�� insert�Լ� ����
	A.insert();
	B.insert();

	//�迭A, B�� ���� ���
	std::cout << "<�迭 A�� ����>" << std::endl;
	A.show();
	std::cout << "<�迭 B�� ����>" << std::endl;
	B.show();

	//��ü A, B +������ �����ε� �� ����� ���
	std::cout << "(�迭 A) ���ϱ� (�迭 B)" << std::endl;
	C = A + B;
	C.show();

	//��ü A, B -������ �����ε� �� ����� ���
	std::cout << "(�迭 A) ���� (�迭 B)" << std::endl;
	C = A - B;
	C.show();

	//�迭 A, B�� ���Ұ� �������� Ȯ�� �� ����� ���
	std::cout << "(�迭 A)�� (�迭 B)�� ��ġ ���� Ȯ��" << std::endl;
	if (A == B) std::cout << "��ġ" << std::endl;
	else std::cout << "����ġ" << std::endl;

	//�迭 A, B�� ���� ���������� ���� �� ����� ���
	std::cout << "<�迭 A�� ����������>" << std::endl;
	C = ++A;
	C.show();
	std::cout << "<�迭 B�� ����������>" << std::endl;
	C = ++B;
	C.show();

	return 0;
}
