//vector�� �̿��Ͽ� 1-100������ ���� �� 10�� ����� �ƴ� ���� ����,
//�̸� ������������ �����Ͽ� ���, ����� ����ϴ� ���α׷�

#include <iostream>
#include <time.h> //���� ������ ���� include
#include <vector> //vector�Լ� ����� ���� include
#include <algorithm> //sort�Լ� ����� ���� include

int main() {
	srand(time(NULL)); //���� ������ ���� ����
	std::vector<int> v; //int�ڷᰡ �� �� �ִ� ���� v ����

	//���� random(����)�� 10�� ������ �ݺ����� Ż��, �ƴ϶�� v�� ����
	while (1) {
		int random = rand() % 100 + 1; //���� ����
		if (random % 10) v.push_back(random); //���� 10�� ����� �ƴ϶�� ������ ������ v�� ����
		else break; //10�� ����� ������ �ݺ��� Ż��
	}

	//vector�� ù ��° ���Һ��� ������ ���ұ��� ��� ���� ���ؼ� result�� �ֱ�
	double result = 0; //��հ� ������ ����
	std::vector<int>::iterator it; //iterator���� ����
	for (it = v.begin(); it != v.end(); it++) {
		result += *it;
	}
	result = result / v.size(); //result �� ������ ������ ���� ����

	sort(v.begin(), v.end()); //������������ ����

	for (it = v.begin(); it != v.end(); it++) std::cout << *it << ' '; //��� ���� ���
	std::cout << std::endl << result << std::endl; //��� ���

	return 0;
}
