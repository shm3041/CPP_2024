//������, �Ҹ��ڸ� �̿��� �簢���� �ʺ�� ���̸� ����ϴ� ���α׷�

#include <iostream>

class Rectangle {
private:
	int width, height;

public:
	Rectangle(); //�⺻ ������ 
	Rectangle(int width_, int height_); //int�� �Ű������� 2���� ������
	~Rectangle(); //�Ҹ��� 

	void show();
	void set(int width_, int height_);
};

Rectangle::Rectangle() {
	width = 1;
	height = 1;
}

Rectangle::Rectangle(int width_, int height_) {
	width = width_;
	height = height_;
}

Rectangle::~Rectangle() {
	std::cout << "�Ҹ��� ȣ��" << " Width: " << width << " Height: " << height << std::endl;
}

void Rectangle::show() {
	std::cout << "Width: " << width << " Height: " << height << std::endl;
}

void Rectangle::set(int width_, int height_) {
	//width, height�� private�� ����Ǿ� ������ �Ʒ��� ���� ���� ���� 
	width = width_;
	height = height_;
}

int main() {
	Rectangle rect1; //�⺻ ������ ȣ�� 
	Rectangle rect2(10, 20); //�Ű����� 2���� ���� �ִ� ������ ȣ�� 
	rect1.show();
	rect1.set(5, 6);
	rect2.show();

	return 0;
}

/*
�̹� ������ �ֿ� ������ �����ڿ� �Ҹ��ڿ���. �����ڿ� �Ҹ��ڸ� ����� ���� ����� �ʾҴ�.
������ �����ڿ� �Լ��� �����ϴ� �κ��� �򰥷��� �Լ��� �ڷ����� �������� �ʴ� �Ǽ��� �Ͽ���.
�̸� �������� �ʵ��� �����ڿ� �Լ� ������ ������ �����ڿ� �Ҹ����� ���� ������ �����ؾ߰ڴٰ� ������.
*/