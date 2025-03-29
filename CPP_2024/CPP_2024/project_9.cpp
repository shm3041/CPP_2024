//�ڵ���	Ŭ������ Ÿ�̾� Ŭ������ �����, Ÿ�̾� 4���� �ڵ����� �����ϴ� ���α׷�

#include <iostream>

class Tire {
private:
	std::string tire_name;
	int position;

public:
	void set_name(std::string tire_name_) { tire_name = tire_name_; } //Ÿ�̾� �̸� ����
	void set_position(int position_) { position = position_; } //Ÿ�̾� ��ġ ����
	void show_name() { std::cout << "����: '" << tire_name << "' "; } //Ÿ�̾� �̸� ���
	void show_position() { std::cout << "��ġ: '" << position << "'"; } //Ÿ�̾� ��ġ ���
};

class Car {
private:
	std::string car_name; //�ڵ��� �̸�
	Tire* T = new Tire[4]; //Ÿ�̾� 4�� ����

public:
	Car(std::string car_name) : car_name(car_name) {} //car_name �̸� ����
	~Car() { delete[] T; } //Ÿ�̾� ���� �޸� �Ҵ� ����
	//Ÿ�̾� �̸��� ��ġ ����
	void add_tire() {
		T[0].set_name("��ȣ");
		T[1].set_name("��ȣ");
		T[2].set_name("��ȣ");
		T[3].set_name("��ȣ");

		for (int i = 0; i < 4; i++)
			T[i].set_position(i + 1);
	}
	//�ڵ��� �̸�, Ÿ�̾� ����, ��ġ ���
	void show() {
		std::cout << "�ڵ��� �̸�: " << car_name << std::endl << std::endl << "<Ÿ�̾� ����, ��ġ> " << std::endl;
		for (int i = 0; i < 4; i++) {
			T[i].show_name();
			T[i].show_position();
			std::cout << std::endl;
		}
	}
};

int main() {
	Car C("�ڵ���"); //�ڵ��� �̸� ����, ��ü ����
	C.add_tire(); //Ÿ�̾� �߰�
	C.show(); //�ڵ��� �̸�, Ÿ�̾� ����, ��ġ �����ֱ�
	return 0;
}
