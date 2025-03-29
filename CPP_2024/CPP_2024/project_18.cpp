//������ ���ݷ��� �������� �����Ͽ� ����ϴ� ���α׷�

#include <iostream>
#include <ctime> //���� ������ ����

class Character {
protected: //����� ���Ͽ� protected ����
	std::string type; //����
	int attack; //���ݷ�
public:
	Character() {} //�⺻ ������
	Character(std::string type, int attack) : type(type), attack(attack) {} //type, attack ���� �ʱ�ȭ
	virtual void print() { //�� �������� ������ ������ �������� �Ǵϱ� virtual ���
		std::cout << "����: " << type << " / " << "���ݷ�: " << attack << std::endl;
	}
};

class Warrior : public Character { //type, attack ���� ����� ���� ���
private:
	int specialSkill; //Ư����
public:
	//Character���� ��ӹ��� type, attack�� specialSkill������ �ʱ�ȭ
	Warrior(std::string type, int attack, int specialSkill)
		: Character(type, attack), specialSkill(specialSkill) {
	}
	void print() override { //Warrior�� print�Լ��� ����Ѵٰ� ���
		std::cout << "����: " << type << " / " << "���ݷ�: " <<
			attack << " / " << "Ư���� : " << specialSkill << std::endl;
	}
};

class Thief : public Character { //type, attack ���� ����� ���� ���
private:
	int specialSkill; //Ư����
public:
	//Character���� ��ӹ��� type, attack�� specialSkill������ �ʱ�ȭ
	Thief(std::string type, int attack, int specialSkill)
		: Character(type, attack), specialSkill(specialSkill) {
	}
	void print() override { //Warrior�� print�Լ��� ����Ѵٰ� ���
		std::cout << "����: " << type << " / " << "���ݷ�: " <<
			attack << " / " << "Ư���� : " << specialSkill << std::endl;
	}
};

class Wizard : public Character { //type, attack ���� ����� ���� ���
private:
	int specialSkill; //Ư����
public:
	//Character���� ��ӹ��� type, attack�� specialSkill������ �ʱ�ȭ
	Wizard(std::string type, int attack, int specialSkill)
		: Character(type, attack), specialSkill(specialSkill) {
	}
	void print() override { //Warrior�� print�Լ��� ����Ѵٰ� ���
		std::cout << "����: " << type << " / " << "���ݷ�: " <<
			attack << " / " << "Ư���� : " << specialSkill << std::endl;
	}
};

int main() {
	srand(time(NULL)); //���� �Լ��� �����ϱ� ���� ���
	Character* C[10]; //Character �������� �迭 ���� (���� ��ü ����)
	//Character�� ���� ������ ��� ������ Character�� ��ӹ޾ұ� ����
	for (int i = 0; i < 10; i++) {
		int random = rand() % 8 + 1; //�ּ� 1 �ִ� 9 ���� ����
		int r_damage = rand(); //���� ����
		if (1 <= random && random <= 3) //random�� 1 �̻�, 3 ���϶�� Wizard ��ü ����
			C[i] = new Wizard("������", r_damage, r_damage * 1);
		else if (4 <= random && random <= 6) //random�� 4 �̻�, 6 ���϶�� Thief ��ü ����
			C[i] = new Thief("����", r_damage, r_damage * 2);
		else //�� ��(7 �̻� 9���϶�� Warrior ��ü ����
			C[i] = new Warrior("����", r_damage, r_damage * 3);
	}

	for (int i = 0; i < 10; i++) { C[i]->print(); } //������ ���� ���
	for (int i = 0; i < 10; i++) { delete C[i]; } //���� �޸� �Ҵ� ����

	return 0;
}
