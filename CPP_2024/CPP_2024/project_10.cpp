//Ÿ�̾� ����, ����Ÿ� �Է¹޾Ƽ� ���� �� Ÿ�̾� ������ ���, ������ 0�� Ÿ�̾� ��ü, ��ü �� Ÿ�̾� �������� ����ϴ� ���α׷�

#include <iostream>
#include <string> //std::string�� ����ϱ� ���� 
#include <ctime> //srand(time(NULL)) ����� ����

int tire_size = 0; //Ÿ�̾� ���� �Է¹ޱ� ���� ����

//���� �������� ���� �Լ�
int rand_tire_durability(int tire_size) {
	return rand() % 10 + 5;
}

//Ÿ�̾� Ŭ����
class Tire {
private:
	std::string tire_name; //Ÿ�̾� �̸�
	int position; //Ÿ�̾� ��ġ
	int durability; //Ÿ�̾� ������

public:
	void set_name(std::string tire_name) { this->tire_name = tire_name; } //Ÿ�̾� �̸� ����
	void set_position(int position) { this->position = position; } //Ÿ�̾� ��ġ ����
	void set_durability() { this->durability = rand_tire_durability(tire_size); } //Ÿ�̾� ������ ����

	void sub_durability() { this->durability -= 1; } //Ÿ�̾� ������ ����

	int ret_tire_value() { return this->durability; } //Ÿ�̾� ������ ����

	void show_name() { std::cout << "�̸�: '" << this->tire_name << "' "; } //Ÿ�̾� �̸� ���
	void show_position() { std::cout << "��ġ: '" << this->position << "' "; } //Ÿ�̾� ��ġ ���
	void show_durability() {
		if (this->durability <= 0) std::cout << "�������� �� �Ǿ����ϴ�."; //Ÿ�̾� �������� 0���� �۰ų� ���� �� ���
		else std::cout << "������: '" << this->durability << "' "; //Ÿ�̾� �������� 0���� ũ�� ������ ���
	}
};

class Car {
private:
	std::string car_name; //�ڵ��� �̸� 
	Tire* T; //Ÿ�̾� ��ü ������ ����
	int run_metter; //����Ÿ�
	int re_tire_count; //Ÿ�̾� ��ü ���� ī��Ʈ

public:
	Car(std::string car_name) //�⺻ ������(�ڵ��� �̸�)
		: car_name(car_name) {
	}
	~Car() { delete[] T; } //�Ҹ���(��ü �迭 �޸� �Ҵ� ����)

	void set_tire() { //Ÿ�̾� ����, �� ����
		T = new Tire[tire_size]; //tire_size��ŭ �޸� ���� �Ҵ�

		//Ÿ�̾� �� ����(�̸�, ��ġ, ������)
		for (int i = 0; i < tire_size; i++) {
			T[i].set_name("�ѱ� Ÿ�̾�");
			T[i].set_position(i + 1);
			T[i].set_durability();
		}
	}

	void get_tire() { //Ÿ�̾� ���� ���(Ÿ�̾� �̸�, ��ġ, ������)
		std::cout << "<Ÿ�̾� ����>" << std::endl;
		for (int i = 0; i < tire_size; i++) {
			T[i].show_name(), T[i].show_position(), T[i].show_durability();
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	void re_tire(int position) { //Ÿ�̾� ��ü(������ �缳��)
		this->T[position].set_durability();
	}

	int run(int run_metter, int i) { //����
		i++;
		std::cout << "���� " << i << "km �Դϴ�." << std::endl;
		this->run_metter = i; //�� ����Ÿ��� ���� ����Ÿ� �߰�

		for (int k = 0; k < tire_size; k++) {
			T[k].sub_durability();
		}

		if (run_metter > i) return run(run_metter, i); //���� ���� ����Ÿ��� �� ����Ÿ����� �۴ٸ� run�Լ� ���� (����Լ�)
		else return 0; //���� ���� ����Ÿ��� �� ����Ÿ����� ���ų� ũ�ٸ� ����Լ� ����
	}

	void show() { //�� �̸�, Ÿ�̾� ����, ����Ÿ� ���
		std::cout << std::endl;
		std::cout << "<�ڵ��� ����>" << std::endl;
		std::cout << "�� �̸�: " << car_name << std::endl;
		std::cout << "Ÿ�̾� ����: " << tire_size << "��" << std::endl;
		std::cout << "���� �Ÿ�: " << run_metter << "km" << std::endl;
		std::cout << std::endl;
	}

	void after_run() { //���� �� �ڵ��� �����ϴ� �Լ�

		//���� �� Ÿ�̾� ��ġ, ������ ���
		std::cout << "<���� �� ������>" << std::endl;
		for (int i = 0; i < tire_size; i++) {
			T[i].show_position();
			T[i].show_durability();
			std::cout << std::endl;
		}
		std::cout << std::endl;


		//Ÿ�̾� �������� 0 ���϶�� ��ü ���� +1
		re_tire_count = 0;
		for (int i = 0; i < tire_size; i++) {
			if (T[i].ret_tire_value() <= 0)
				re_tire_count++; //���� Ÿ�̾� �������� 0 ���϶�� count++
		}

		//Ÿ�̾� ��ü
		for (int i = 0; i < tire_size; i++) {
			if (T[i].ret_tire_value() <= 0)
				re_tire(i); //���� Ÿ�̾� �������� 0 ���϶�� Ÿ�̾ ��ü
		}

		//��ü �� Ÿ�̾� ��ġ, ������ ���
		if (re_tire_count != 0) { //���� Ÿ�̾� ��ü ������ �ִٸ� ����
			std::cout << "<��ü �� ������>" << std::endl;
			for (int i = 0; i < tire_size; i++) {
				T[i].show_position();
				T[i].show_durability();
				std::cout << std::endl;
			}
		}
		else std::cout << "��ü�� Ÿ�̾ �����ϴ�." << std::endl; //Ÿ�̾� ��ü ������ ���ٸ� ����
		//std::cout << re_tire_count;

		std::cout << std::endl;
	}
};

int main() {
	srand(time(NULL)); // ���� ���� ���� ����

	//Ÿ�̾� ���� �Է�
	std::cout << "�߰��� Ÿ�̾� ����: ";
	std::cin >> tire_size;

	//�ڵ��� ���� (Ÿ�̾� ����, ���)
	Car C("�ڵ���");
	C.set_tire(); //����
	C.get_tire(); //���

	C.show(); //�� �̸�, Ÿ�̾� ����, ����Ÿ� ���

	int run_metter;
	std::cout << "���� �Ÿ� �Է�: ";
	std::cin >> run_metter;
	C.run(run_metter, 0); //�Ű������� ����Ÿ�, ���� ���� Ƚ�� �ޱ�

	std::cout << std::endl << "--------- ��� ������ ���ƽ��ϴ� ---------";
	C.show(); //�� �̸�, Ÿ�̾� ����, ����Ÿ� ���
	C.after_run(); //���� �� Ÿ�̾� ������ ���, ������ 0�� Ÿ�̾� ��ü, ��ü �� Ÿ�̾� ������ ���

	return 0;
}
