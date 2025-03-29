//���簢��, ������ü�� ���� ����ϱ�(virtual, override ���)

#include <iostream>

class Rectangle { //���簢��
protected: //����� ���̱� ������ protected�� ����
	int height, width; //����, ���� ����
public:
	Rectangle() : height(0), width(0) {} //�⺻ ������
	Rectangle(int height, int width) : height(height), width(width) {} //����, ���� ���� ������ �����ε�
	~Rectangle() {} //�Ҹ���

	int area_calc() { return height * width; } //���� ���
	int perimeter_calc() { return (height + width) * 2; } //�ѷ� ���
	//���簢���� ���� ���(����, ����, �ѷ�, ����)
	//Cuboid������ Cuboid���� ���� print�Լ��� ����ؾ� �ż� virtual Ű���� ���
	void virtual print() {
		std::cout << "���簢���� ����: " << height << std::endl;
		std::cout << "���簢���� ����: " << width << std::endl;
		std::cout << "���簢���� �ѷ�: " << perimeter_calc() << std::endl;
		std::cout << "���簢���� ����: " << area_calc() << std::endl;
		std::cout << std::endl;
	}
};

class Cuboid : public Rectangle { //������ü
private:
	int high; //���� (����, ���� ���̴� Rectangle���� ��ӹ���)
public:
	Cuboid() : Rectangle(0, 0), high(0) {} //�⺻ ������
	//����, ����, ���� ������ �����ε�
	//Rectangle���� ��ӹ��� ����, ���� ����, Cuboid�� ���� ���� �ʱ�ȭ
	Cuboid(int height, int width, int high) : Rectangle(height, width), high(high) {}
	~Cuboid() {} //�Ҹ���

	int s_area_calc() { return 2 * ((width * height) + (width * high) + (height * high)); } //�ѳ��� ���
	int volume_calc() { return height * width * high; } //���� ���
	void print() override { //Rectangle�� print�Լ��� �ƴ� Cuboid�� print�Լ��� ����Ѵٰ� override Ű����� ���
		std::cout << "������ü�� ���� : " << height << std::endl;
		std::cout << "������ü�� ����: " << width << std::endl;
		std::cout << "������ü�� ����: " << high << std::endl;
		std::cout << "������ü�� �ѳ���: " << s_area_calc() << std::endl;
		std::cout << "������ü�� ����: " << volume_calc() << std::endl;
		std::cout << std::endl;
	}
};

int main() {

	Rectangle* diagram[6]; //Rectangle*�ڷ������� ���簢���� ������ü�� ������ �迭 ����

	diagram[0] = new Rectangle(1, 2); //��ü �޸� �Ҵ�
	diagram[1] = new Rectangle(2, 3); //��ü �޸� �Ҵ�
	diagram[2] = new Rectangle(3, 4); //��ü �޸� �Ҵ�
	diagram[3] = new Cuboid(1, 2, 3); //��ü �޸� �Ҵ�
	diagram[4] = new Cuboid(3, 4, 5); //��ü �޸� �Ҵ�
	diagram[5] = new Cuboid(5, 6, 7); //��ü �޸� �Ҵ�


	for (int i = 0; i < 6; i++) { diagram[i]->print(); } //���� ���� ���

	for (int i = 0; i < 6; i++) { delete diagram[i]; } //diagram[i]�� �ִ� ��ü�� �޸� �Ҵ� ����

	return 0;
}

/*
�̹� ������ �ϸ� ���� �������� ��� virtual�� override, ��ӿ� ���� ������ ��� ����� �� �־ ���Ҵ�.
ó�� ��ӿ� ���� ������ �� ���� �� ������ �ذ����� ���ߴ��� �ǹ��� �� ������ �Ҹ��ߴ�. 
������ ����� �߸� ����Ͽ� ����� ������ ���� �����ϸ鼭 �ڵ��ؾ߰ڴٰ� ������. 
���� �Ǽ��� �Ѵٰ� �Ͽ��� ��� �κп��� ������ �߸� �Ǿ����� ��ġä�� �̸� �ذ��ϱ�� ����� �� ���� �����̴�.
*/