//연산자 오버로딩을 이용한 배열의 덧셈, 뺄셈, equal, 증감연산자, 대입연산자 구현

#include <iostream>
#include <time.h> //rand(), srand()

class op {
private:
	int* n; //배열
	int size; //배열의 사이즈
public:
	//생성자(default parameter) 오버로딩
	op(int size = 0) : size(size) {
		n = new int[size]; //size만큼 동적 메모리 할당
		for (int i = 0; i < size; i++) { n[i] = 0; } //배열의 원소 초기화
	}

	void insert(); //배열에 원소 삽입
	void show(); //배열의 원소 출력

	op operator+ (const op& x); //배열의 덧셈
	op operator- (const op& x); //배열의 뺄셈
	bool operator== (const op& x); //배열의 equal
	op& operator++ (); //증감연산자(전위)
	op& operator=(const op& x); // 대입 연산자
	~op() { delete[] n; } //객체 소멸 시 배열 n 메모리 할당 해제
};

//배열에 원소 삽입
void op::insert() {
	//배열에 랜덤한 값(1 ~ 10)을 삽입
	for (int i = 0; i < size; i++) {
		n[i] = rand() % 10 + 1;
	}
}

//배열의 원소 출력
void op::show() {
	for (int i = 0; i < size; i++) {
		std::cout << n[i] << " ";
	}
	std::cout << std::endl;
}

//배열 A와 배열 B에 있는 원소의 덧셈
op op::operator+ (const op& x) {
	op tmp(size);
	for (int i = 0; i < size; i++) {
		tmp.n[i] = n[i] + x.n[i];
	}
	return tmp;
}

//배열 A와 배열 B에 있는 원소의 뺄셈
op op::operator- (const op& x) {
	op tmp(size);
	for (int i = 0; i < size; i++) {
		tmp.n[i] = n[i] - x.n[i];
	}
	return tmp;
}

//배열 A와 배열 B의 원소가 동일한지 확인하는 연산자
bool op::operator== (const op& x) {
	//만약 하나라도 다른 원소가 있다면 false 리턴
	//만약 모든 원소가 같다면 true 리턴
	for (int i = 0; i < size; i++) {
		if (n[i] != x.n[i]) return false;
	}
	return true;
}

//배열에 있는 원소에 각각 증감연산자 사용
op& op::operator++() {
	for (int i = 0; i < size; i++) {
		n[i]++;
	}
	return *this;
}

//만약 대입 연산자를 만들지 않은 상태에서 C = A + B or C = A - B를 한다면 C는 임시 객체 tmp의
//메모리 주소를 가리키게 되어버림(얕은 복사)
//이후에 tmp의 소멸자가 호출되어서 n의 메모리 할당 해제를 해버린다면
//객체 C는 tmp의 멤버 변수 n의 메모리 주소를 가리키고 있기 때문에 오류가 발생함.
//따라서 대입 연산자를 만들어 주어서 이 문제를 해결함.(깊은 복사)
op& op::operator=(const op& x) {
	//size는 모든 객체가 동일하니 배열 n에 있는 원소만 this->n으로 옮겨줌
	for (int i = 0; i < size; i++) {
		n[i] = x.n[i];
	}
	return *this;
}

int main() {
	srand(time(NULL)); //난수 생성을 위해 사용

	//배열의 크기 입력받기
	int size;
	std::cout << "객체의 크기를 입력하세요: ";
	std::cin >> size;

	//객체 생성
	op A(size);
	op B(size);
	op C(size);

	//객체 A, B의 insert함수 실행
	A.insert();
	B.insert();

	//배열A, B의 원소 출력
	std::cout << "<배열 A의 원소>" << std::endl;
	A.show();
	std::cout << "<배열 B의 원소>" << std::endl;
	B.show();

	//객체 A, B +연산자 오버로딩 후 결과값 출력
	std::cout << "(배열 A) 더하기 (배열 B)" << std::endl;
	C = A + B;
	C.show();

	//객체 A, B -연산자 오버로딩 후 결과값 출력
	std::cout << "(배열 A) 빼기 (배열 B)" << std::endl;
	C = A - B;
	C.show();

	//배열 A, B의 원소가 동일한지 확인 후 결과값 출력
	std::cout << "(배열 A)와 (배열 B)의 일치 여부 확인" << std::endl;
	if (A == B) std::cout << "일치" << std::endl;
	else std::cout << "불일치" << std::endl;

	//배열 A, B에 각각 증감연산자 실행 후 결과값 출력
	std::cout << "<배열 A에 증감연산자>" << std::endl;
	C = ++A;
	C.show();
	std::cout << "<배열 B에 증감연산자>" << std::endl;
	C = ++B;
	C.show();

	return 0;
}
