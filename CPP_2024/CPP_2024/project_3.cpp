//�迭 ũ�� �� ��Ҹ� �Է¹ް� ��Ҹ� �ݴ�� ��� �� ����� ���� ����ϴ� ���α׷�

#include <iostream>

//�迭�� �ִ� ���� �Ųٷ� ����Ѵ�.
int reverse(int arr[], int num) {
	std::cout << "�迭�� �ݴ�� ���" << std::endl;
	for (int i = num - 1; i >= 0; i--) {
		std::cout << arr[i] << " ";
	}

	return 0;
}

//�迭�� �ִ� ���� ��� ���ϰ� �̸� ���� �Լ��� �����Ѵ�.
int sum(int arr[], int num) {
	int sum = 0;

	for (int i = 0; i < num; i++) {
		sum += arr[i];
	}

	return sum;
}

int main() {
	int num = 0;
	int* arr;

	//����ڿ��� �迭�� ũ�⸦ �Է¹ް�, 1�̻� 10���Ϸ� �Է��Ͽ��ٸ� �ݺ����� Ż��
	while (1) {
		std::cout << "�迭�� ũ�⸦ �����ּ���: ";
		std::cin >> num;
		if (1 <= num && num <= 10) break;
		else std::cout << "1�̻� 10 ���Ϸ� �����Ͽ� �ּ���." << std::endl;
	}

	//����ڿ��� �Է¹��� ũ�⸸ŭ �޸𸮿� ���� �Ҵ�
	arr = new int[num];
	std::cout << "������ �Է��ϼ���: ";

	//�迭�� �� �� �Է¹ޱ�
	for (int i = 0; i < num; i++) {
		std::cin >> arr[i];
	}

	//reverse�Լ� ȣ��
	reverse(arr, num);

	//�迭�� �ִ� ���� ��� ���ϴ� �Լ�(sum)�� ȣ���ϰ� ���Ϲ��� ���� ����Ѵ�.
	std::cout << std::endl << "��� ������ ��: " << sum(arr, num) << std::endl;

	//arr�迭�� �޸� �Ҵ� ����
	delete[] arr;
	return 0;

}
