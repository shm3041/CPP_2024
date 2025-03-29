//call-by-reference�� call-by-value�� ���Ҽ� ����, ������ �ϴ� ���α׷�

#include <iostream>

class Complex {
private:
	double real, ima; //�Ǽ�, ���
	int obj_num; //��ü ��ȣ(�Ҹ��� ȣ�� �� ��ü �����ϱ� ���� ����)
	double result_real, result_ima; //���Ҽ� �����
public:
	Complex() //�⺻ ������ (��� ���� 0���� ����)
		: real(0), ima(0), obj_num(0), result_real(0), result_ima(0) {
	}
	Complex(double real, double ima, int obj_num) //�Ǽ�, ���, ��ü ��ȣ �޴� ������
		: real(real), ima(ima), obj_num(obj_num), result_real(0), result_ima(0) {
	}
	~Complex() { //�Ҹ���
		std::cout << "C" << obj_num << " ��ü �Ҹ��� ȣ��" << std::endl;; //��ü ��ȣ ���
		print_result(); //��� ���
	}

	void set_real(double result_real) { this->result_real = result_real; } //����� �Ǽ� ���� �Ű������� �޾ƿͼ� ����
	void set_ima(double result_ima) { this->result_ima = result_ima; } //����� ��� ���� �Ű������� �޾ƿͼ� ����
	double get_real() { return this->real; } //�Ǽ� ������������ ����
	double get_ima() { return this->ima; } //��� ������������ ����

	void print() { std::cout << "�Ǽ�: " << real << " " << "���: " << ima << "i" << std::endl; } //�Ǽ�, ��� ���
	void print_result() { std::cout << "�Ǽ�: " << result_real << " " << "���: " << result_ima << "i" << std::endl; } //�Ǽ�, ��� ���
	void copy_result(Complex& x) { //���Ҽ� ����� ���� �ٸ� ��ü�� ������ �� ���
		result_real = x.result_real;
		result_ima = x.result_ima;
	}

	void ref_add(Complex& x, Complex& y); //call-by-reference�� ���Ҽ� ����
	void ref_multi(Complex& x, Complex& y); //call-by-reference�� ���Ҽ� ����
	void value_add(Complex x, Complex y); //call-by-value�� ���Ҽ� ����
	void value_multi(Complex x, Complex y); //call-by-value�� ���Ҽ� ����
};
//call-by-reference
void Complex::ref_add(Complex& x, Complex& y) { // C1, C2�� �Ǽ�, �Ҽ��� �޾ƿ��� ���� ����
	x.set_real(x.get_real() + y.get_real()); //set_real, set_ima�Լ��� ������� ��ü x�� �Է�,
	x.set_ima(x.get_ima() + y.get_ima());    // get_real, get_ima�� ���� �޾ƿ���
	y.copy_result(x); //��ü y�� ����� ����
}
void Complex::ref_multi(Complex& x, Complex& y) { // C1, C2�� �Ǽ�, �Ҽ��� �޾ƿ��� ���� ����
	x.set_real(x.get_real() * y.get_real() - x.get_ima() * y.get_ima()); //set_real, set_ima�Լ��� ������� ��ü x�� �Է�,
	x.set_ima(x.get_real() * y.get_ima() + x.get_ima() * y.get_real());  // get_real, get_ima�� ���� �޾ƿ���
	y.copy_result(x); //��ü y�� ����� ����
}

//call-by-value
void Complex::value_add(Complex x, Complex y) { // C1, C2�� �Ǽ�, �Ҽ��� �޾ƿ��� ���� ����
	x.set_real(x.get_real() + y.get_real()); //set_real, set_ima�Լ��� ������� ��ü x�� �Է�,
	x.set_ima(x.get_ima() + y.get_ima());    // get_real, get_ima�� ���� �޾ƿ���
	y.copy_result(x); //��ü y�� ����� ����

	std::cout << "[value_add]" << std::endl;
	x.print_result(); //value_add���� x�� ����� ���
	std::cout << std::endl;
}
void Complex::value_multi(Complex x, Complex y) { // C1, C2�� �Ǽ�, �Ҽ��� ����ϱ� ���� ����
	x.set_real(x.get_real() * y.get_real() - x.get_ima() * y.get_ima()); //set_real, set_ima�Լ��� ������� ��ü x�� �Է�,
	x.set_ima(x.get_real() * y.get_ima() + x.get_ima() * y.get_real());  // get_real, get_ima�� ���� �޾ƿ���
	y.copy_result(x); //��ü y�� ����� ����

	std::cout << "[value_multi]" << std::endl;
	x.print_result(); //value_result���� x�� ����� ���
	std::cout << std::endl;
}

//C1, C2 ��ü ����ϴ� �Լ�
void print(Complex& C1, Complex& C2) { // C1, C2�� �Ǽ�, �Ҽ��� ����ϱ� ���� ����
	std::cout << "C1 / ";
	C1.print(); //C1��ü�� print �Լ� ����
	std::cout << "C2 / ";
	C2.print(); //C2 ��ü�� print �Լ� ����
	std::cout << std::endl;
}

int main() {
	Complex C1(1, 2, 1); //1�� ��ü
	Complex C2(3, 4, 2); //2�� ��ü

	print(C1, C2); //C1, C2�� �Ǽ�, ����� ���� ���� ���

	//call-by-reference
	std::cout << "-------------[call-by-reference]-------------" << std::endl;
	C1.ref_add(C1, C2); //call-by-reference�� ���Ҽ� ����
	std::cout << "���ϱ� > ";
	C1.print_result(); //����� ���

	C1.ref_multi(C1, C2); //call-by-reference�� ���Ҽ� ����
	std::cout << "���ϱ� > ";
	C1.print_result(); //����� ���
	std::cout << std::endl;

	//call-by-value
	std::cout << "---------------[call-by-value]---------------" << std::endl;
	C1.value_add(C1, C2); //call-by-value�� ���Ҽ� ����
	std::cout << std::endl;
	std::cout << "[main]" << std::endl;
	std::cout << "���ϱ� > ";
	C1.print_result(); //����� ���
	std::cout << std::endl;

	C1.value_multi(C1, C2); //call-by-value�� ���Ҽ� ����
	std::cout << std::endl;
	std::cout << "[main]" << std::endl;
	std::cout << "���ϱ� > ";
	C1.print_result(); //����� ���
	std::cout << std::endl;


	std::cout << std::endl << std::endl;
	std::cout << "[�Ҹ��� ȣ��]" << std::endl;
	return 0;
}
