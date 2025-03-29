//ī�޶� �뿩�ϴ� ���α׷�(���� �̹� ī�޶� ��� ���̶�� �뿩�� �� ����)
//��ü�� �̹� �����Ǿ� �ִ��� Ȯ�� �� ��ü�� �����ϴ� ���α׷�

#include <iostream>

class Camera { //ī�޶� Ŭ����
private:
	Camera() {} //�⺻ ������
	static Camera* instance; //��ü ����
public:
	static Camera* getInstance(); //��ü ����
	static void delInstance(); //��ü ����
	void capture() { std::cout << "Let's take a picture!!" << std::endl; }
};

Camera* Camera::instance = nullptr; //������ �ʱ�ȭ
//��ü�� ���� Ȯ�� �� ��ü�� ����, ��ü�� �̹� �����Ѵٸ� ������ ��ü�� �ּҸ� ����Ű�� ��
Camera* Camera::getInstance() {
	if (!instance) { //������ ��ü�� ���ٸ� ����
		instance = new Camera(); //��ü ����
		std::cout << "ī�޶� ���������� �뿩�Ͽ����ϴ�." << std::endl;
	}
	else std::cout << "�̹� ī�޶� ��� ���Դϴ�!" << std::endl;

	return instance; //��ü ����
}
void Camera::delInstance() {
	if (instance) { //������ ��ü�� �ִٸ� ����
		delete instance; //��ü �޸� �Ҵ� ����
		instance = nullptr; //instance �޸� 0���� ����
		std::cout << "ī�޶� ��� ����" << std::endl;
	}
}

int main() {
	std::cout << "s1 ī�޶� �뿩" << std::endl;
	Camera* s1 = Camera::getInstance();
	std::cout << "s2 ī�޶� �뿩" << std::endl;
	Camera* s2 = Camera::getInstance();
	std::cout << "s3 ī�޶� �뿩" << std::endl;
	Camera* s3 = Camera::getInstance();
	s1->capture();

	Camera::delInstance(); //��ü �޸� �Ҵ� ����


	return 0;
}

/*
�������� �������� �ʱ�ȭ �� *ptr = 0 or *ptr = NULL�� ���� �߾����ϴ�. 
������ �̷��� �� ��� ��ȣ�� ��Ȳ�� ���Ƽ� ����ϱ� �ָ��߽��ϴ�. 
�� ������ ���ۿ� ã�ƺ��� nullptr�� ���� �־ ������� �� �������� �� �������� 
NULL�� 0�� nullptr�� �����͸� ���Ͽ� �̸� ����ϰ� �Ǿ����ϴ�. 
�̹� ������ ���Ͽ� Singleton Pattern�� �ٷ�� ���� �˰� �Ǿ� ���ҽ��ϴ�.
*/