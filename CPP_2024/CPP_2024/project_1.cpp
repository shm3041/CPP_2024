//�̸�, �ּ�, ��ȣ�� �Է¹޾� ����ϴ� ���α׷�

#include <iostream>
#include <cstring> // strcmp �Լ��� ����ϱ� ���� �ҷ���
using namespace std;

int main() {
	char name[20];
	cout << "�̸��� �Է��ϼ���: ";
	cin >> name;
	cout << "�̸��� " << name << "�Դϴ�." << endl;

	cin.ignore(); //cin.getline ����� ���� ���۸� �����

	char home_address[100];
	cout << "�ּҸ� �Է��ϼ���: ";
	cin.getline(home_address, 100, '\n'); //�ּ� ���̿��� ���Ⱑ �����Ƿ� getline ���
	cout << "�ּҴ� " << home_address << "�Դϴ�." << endl;


	char pw1[50];
	char pw2[50];
	//��ȣ�� �ùٸ��� �Էµ��� ������ �ٽ� �Է��ϵ��� while ���
	while (1) {
		cout << "�� ��ȣ�� �Է��ϼ���: ";
		cin >> pw1;
		cout << "��ȣ�� �ѹ� �� �Է��ϼ���: ";
		cin >> pw2;

		//pw1�� pw2�� �� �� ���� ��ġ�ϸ� �ݺ����� ������������ ��
		if (strcmp(pw1, pw2) == 0) {
			cout << "��ȣ�� �ùٸ��� �ԷµǾ����ϴ�." << endl;
			break;
		}
		else
			cout << "��ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
	}

	return 0;
}
