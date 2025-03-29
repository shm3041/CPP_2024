//call-by-reference와 call-by-value로 복소수 덧셈, 곱셈을 하는 프로그램

#include <iostream>

class Complex {
private:
	double real, ima; //실수, 허수
	int obj_num; //객체 번호(소멸자 호출 시 객체 구별하기 위해 만듬)
	double result_real, result_ima; //복소수 계산결과
public:
	Complex() //기본 생성자 (모든 값을 0으로 생성)
		: real(0), ima(0), obj_num(0), result_real(0), result_ima(0) {
	}
	Complex(double real, double ima, int obj_num) //실수, 허수, 객체 번호 받는 생성자
		: real(real), ima(ima), obj_num(obj_num), result_real(0), result_ima(0) {
	}
	~Complex() { //소멸자
		std::cout << "C" << obj_num << " 객체 소멸자 호출" << std::endl;; //객체 번호 출력
		print_result(); //결과 출력
	}

	void set_real(double result_real) { this->result_real = result_real; } //계산한 실수 값을 매개변수로 받아와서 변경
	void set_ima(double result_ima) { this->result_ima = result_ima; } //계산한 허수 값을 매개변수로 받아와서 변경
	double get_real() { return this->real; } //실수 가져오기위해 생성
	double get_ima() { return this->ima; } //허수 가져오기위해 생성

	void print() { std::cout << "실수: " << real << " " << "허수: " << ima << "i" << std::endl; } //실수, 허수 출력
	void print_result() { std::cout << "실수: " << result_real << " " << "허수: " << result_ima << "i" << std::endl; } //실수, 허수 출력
	void copy_result(Complex& x) { //복소수 계산한 값을 다른 객체에 복사할 때 사용
		result_real = x.result_real;
		result_ima = x.result_ima;
	}

	void ref_add(Complex& x, Complex& y); //call-by-reference로 복소수 덧셈
	void ref_multi(Complex& x, Complex& y); //call-by-reference로 복소수 곱셈
	void value_add(Complex x, Complex y); //call-by-value로 복소수 덧셈
	void value_multi(Complex x, Complex y); //call-by-value로 복소수 곱셈
};
//call-by-reference
void Complex::ref_add(Complex& x, Complex& y) { // C1, C2의 실수, 소수를 받아오기 위해 받음
	x.set_real(x.get_real() + y.get_real()); //set_real, set_ima함수로 계산결과를 객체 x에 입력,
	x.set_ima(x.get_ima() + y.get_ima());    // get_real, get_ima로 값을 받아오기
	y.copy_result(x); //객체 y에 계산결과 복사
}
void Complex::ref_multi(Complex& x, Complex& y) { // C1, C2의 실수, 소수를 받아오기 위해 받음
	x.set_real(x.get_real() * y.get_real() - x.get_ima() * y.get_ima()); //set_real, set_ima함수로 계산결과를 객체 x에 입력,
	x.set_ima(x.get_real() * y.get_ima() + x.get_ima() * y.get_real());  // get_real, get_ima로 값을 받아오기
	y.copy_result(x); //객체 y에 계산결과 복사
}

//call-by-value
void Complex::value_add(Complex x, Complex y) { // C1, C2의 실수, 소수를 받아오기 위해 받음
	x.set_real(x.get_real() + y.get_real()); //set_real, set_ima함수로 계산결과를 객체 x에 입력,
	x.set_ima(x.get_ima() + y.get_ima());    // get_real, get_ima로 값을 받아오기
	y.copy_result(x); //객체 y에 계산결과 복사

	std::cout << "[value_add]" << std::endl;
	x.print_result(); //value_add에서 x의 계산결과 출력
	std::cout << std::endl;
}
void Complex::value_multi(Complex x, Complex y) { // C1, C2의 실수, 소수를 사용하기 위해 받음
	x.set_real(x.get_real() * y.get_real() - x.get_ima() * y.get_ima()); //set_real, set_ima함수로 계산결과를 객체 x에 입력,
	x.set_ima(x.get_real() * y.get_ima() + x.get_ima() * y.get_real());  // get_real, get_ima로 값을 받아오기
	y.copy_result(x); //객체 y에 계산결과 복사

	std::cout << "[value_multi]" << std::endl;
	x.print_result(); //value_result에서 x의 계산결과 출력
	std::cout << std::endl;
}

//C1, C2 객체 출력하는 함수
void print(Complex& C1, Complex& C2) { // C1, C2의 실수, 소수를 사용하기 위해 받음
	std::cout << "C1 / ";
	C1.print(); //C1객체의 print 함수 실행
	std::cout << "C2 / ";
	C2.print(); //C2 객체의 print 함수 실행
	std::cout << std::endl;
}

int main() {
	Complex C1(1, 2, 1); //1번 객체
	Complex C2(3, 4, 2); //2번 객체

	print(C1, C2); //C1, C2의 실수, 허수의 값을 각각 출력

	//call-by-reference
	std::cout << "-------------[call-by-reference]-------------" << std::endl;
	C1.ref_add(C1, C2); //call-by-reference로 복소수 덧셈
	std::cout << "더하기 > ";
	C1.print_result(); //계산결과 출력

	C1.ref_multi(C1, C2); //call-by-reference로 복소수 곱셈
	std::cout << "곱하기 > ";
	C1.print_result(); //계산결과 출력
	std::cout << std::endl;

	//call-by-value
	std::cout << "---------------[call-by-value]---------------" << std::endl;
	C1.value_add(C1, C2); //call-by-value로 복소수 덧셈
	std::cout << std::endl;
	std::cout << "[main]" << std::endl;
	std::cout << "더하기 > ";
	C1.print_result(); //계산결과 출력
	std::cout << std::endl;

	C1.value_multi(C1, C2); //call-by-value로 복소수 곱셈
	std::cout << std::endl;
	std::cout << "[main]" << std::endl;
	std::cout << "곱하기 > ";
	C1.print_result(); //계산결과 출력
	std::cout << std::endl;


	std::cout << std::endl << std::endl;
	std::cout << "[소멸자 호출]" << std::endl;
	return 0;
}
