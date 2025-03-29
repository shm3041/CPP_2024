//�л� ������ ����ü�� �Է¹ް�, ��, ��, ��, ��� �� �ϳ��� �����Ͽ� ������������ �����Ͽ� ����ϴ� ���α׷�

#include <iostream>
#include <cstdlib> //qsort �Լ� ����� ���� �ҷ��� 
#include <cstring> //strcmp �Լ� ����� ���� �ҷ��� 
#define SIZE 3
char choice[30]; //��, ��, ��, ��� ������ ���� 

//�л� ���� ����ü(����, ����, ����, ���) 
struct student {
	char name[30];
	int korean, english, math, avg;
};

//qsort �Լ� ����� ���� compare �Լ� ���� 
int compare(const void* a, const void* b);

int main() {
	//�����ͷ� ����ü �迭 S ���� (ũ��: 3) 
	struct student* S = new struct student[SIZE];

	//�л� ���� �Է¹ޱ� 
	std::cout << "�л� 3���� �̸�, ����, ����, ���� ������ �Է����ּ���" << std::endl;
	for (int i = 0; i < 3; i++) {
		std::cin >> S[i].name >> S[i].korean >> S[i].english >> S[i].math; //�̸�, ��, ��, �� 
		S[i].avg = (S[i].korean + S[i].english + S[i].math) / 3; //��� 
	}

	//��, ��, ��, ��� ������ �Է� �� ���� 
	std::cout << "����, ����, ����, ��� �� �ϳ��� �����ϼ���: ";
	std::cin >> choice;
	qsort(S, SIZE, sizeof(struct student), compare);

	//������ ���� ������ �̸� ��� 
	std::cout << "������ ���� ���� ������ �̸��� ����մϴ�." << std::endl;
	for (int i = 0; i < 3; i++)
		std::cout << S[i].name << " ";

	//�޸� �Ҵ� ���� 
	delete[] S;
	return 0;
}

int compare(const void* a, const void* b) {
	//struct student�������� ��ȯ�Ͽ� x, y�� �ޱ� 
	struct student x = *(struct student*)a;
	struct student y = *(struct student*)b;

	//�������� �����̹Ƿ� y���� x�� ���ش�.
	if (strcmp(choice, "����") == 0) return y.korean - x.korean;
	else if (strcmp(choice, "����") == 0) return y.english - x.english;
	else if (strcmp(choice, "����") == 0) return y.math - x.math;
	else return y.avg - x.avg;
}

/*
�� �ڵ带 �ۼ��Ҷ� ó������ qsort�� ����Ϸ� ������ compare �Լ� �ۼ����� ��ﳪ�� �ʾƼ�
���� �ð� ���� ���� ���� �ڵ带 ���� ¥�� ������ ������������ ���� �� �̸��� �������� ����Ͽ���.
������ �����ͼ� ���� �ڵ尡 �ʹ� ������� �������� �������� ������ �Լ��� ����Ͽ���.
std::cin���� ���ڿ��� �Է¹޴� �κе� scanf�θ� �غ��� �򰥷����� �ݹ� �����Ͽ���.
*/