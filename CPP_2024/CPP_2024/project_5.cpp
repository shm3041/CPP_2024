//10-20������ ������ �Է¹ް� ���� 
//¦���� ��� ¦���� ���, Ȧ���� X�� ���
//Ȧ���� ��� Ȧ���� ���, ¦���� X�� ����ϴ� ���α׷�

#include <iostream>
using namespace std;

int main() {
	int* arr;
	int size;

	//�迭 ������ �Է�
	cout << "������ �Է��ϼ���: ";
	while (1) {
		cin >> size;
		if (10 <= size && size <= 20) break;
		else cout << "10 ~ 20������ ������ �Է��ϼ���: ";
	}

	//�迭 ������ ����
	arr = new int[size];

	//¦���� ��� ����
	if (size % 2 == 0) {
		for (int i = 0; i < size; i++)
			//¦���� ��� i�� �迭�� ����, Ȧ���� ��� 4444�� �迭�� ����
			i % 2 == 0 ? arr[i] = i : arr[i] = 4444;
	}
	//Ȧ���� ��� ����
	else {
		for (int i = 0; i < size; i++)
			//Ȧ���� ��� i�� �迭�� ����, ¦���� ��� 4444�� �迭�� ����
			i % 2 != 0 ? arr[i] = i : arr[i] = 4444;
	}

	//�迭�� �ִ� ���� 4444�� ��� X�� ���
	for (int i = 0; i < size; i++)
		arr[i] != 4444 ? cout << arr[i] << " " : cout << "X ";

	//���� �ڿ� �� ���
	cout << size;

	delete[] arr;
	return 0;
}
