//��ü�� ������ ���� ����� �����ϴ� ���α׷�

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h> //strcpy ����ϱ� ���� ����
class Book {
private:
	char* title; //����
	int price; //����
public:
	Book(const char* title, int price) { //����, ���� �޾ƿ���
		this->title = new char[strlen(title) + 1]; //title �޸� ���� �Ҵ�
		strcpy(this->title, title); //Ÿ��Ʋ ����
		this->price = price; //���� ����
	}
	Book(const Book& B) { //���� ������
		title = B.title; //���� ���� (cpp�� title�� ���� �ּ� ����Ŵ)
		this->price = B.price; //���� ����
	}
	~Book() { //�Ҹ���
		std::cout << "�Ҹ��� ȣ��" << std::endl;
		if (this->title) delete[] this->title; //title�� ���ڰ� �ִٸ� ��ü�� �Ҹ��Ҷ� new�� �Ҵ��� �޸� ����
	}

	void set(const char* title, int price) { //Ÿ��Ʋ, ���� �����ϴ� �Լ�
		this->title = new char[strlen(title) + 1]; //���ڿ� ������ ���� �Ҵ�
		strcpy(this->title, title); //Ÿ��Ʋ ����
		this->price = price; //���� ����
	}
	void show() {
		std::cout << title << ' ' << price << "won" << std::endl;
	}
};
int main() {
	Book cpp("C++", 10000); //cpp ��ü ���� �� �ʱ�ȭ
	Book java = cpp; //cpp ���� ������(���� ����)
	java.set("Java", 12000); //�ڹ� ��ü�� title, price ����
	cpp.show(); //title, price ���
	java.show(); //title, price ���

	return 0;
}

/*
�̹� ������ �ϸ� ���� ����, ���� ���縦 �� �� �޸𸮿��� � ������ �Ͼ���� �˰� �Ǿ���. 
���� ����� ��� �޸� �ּҸ� �����ؼ� ���� ���� ���̶�� ���� ����� ����, �ٿ��ֱ� ��� �����̴�. 
���� ���� ����� A�� �޸� ���� �Ҵ��� �����ȴٸ� B�� �ش� �޸� ������ ������ �� ���� �ȴ�. 
���������� �ñ��� ���� �־ ���� ������ �Ͽ��µ� strcpy(A, B)�Լ��� ��쿡�� ���ڿ��� A �������� �����ϸ�
A = B�� ���� ���簡 �ȴ�. ������ std::string���� ���ڿ��� ����ٸ� A = B���� �� ���� ���簡 ����ȴٴ� ���� 
�˰� �Ǿ���.
*/